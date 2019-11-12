
local LoadAsync = class("LoadAsync")

local autoReleaseFile = {}
local spriteFrameCache = cc.SpriteFrameCache:getInstance()
local textureCache = cc.Director:getInstance():getTextureCache()

function LoadAsync:ctor()
	self.resFiles = {}
	self.loadFileName_True = {}

	self.curLoadCount = 0
	self.totalLoadCount = 0

	self.curReleaseCount = 0
	self.totalReleaseCount = 0

	self.releaseFiles = {}
	self:clearAutoReleaseFile()
end

local ENABLE_DEBUG = true

------------------------------------------------------------public begin------------------------------------------------------------

function LoadAsync:addLoadResource(fileName, isAutoRelease, resType)

	if resType == nil then
		resType = LoadAsync.getExtension(fileName)
	end

	if not self.loadFileName_True[fileName] then
		self.loadFileName_True[fileName] = true
		table.insert(self.resFiles, LoadAsync.allocFileData(fileName, resType))
	end

	if isAutoRelease then
		table.insert(autoReleaseFile, LoadAsync.allocFileData(fileName, resType))
	end

	if resType == "plist" then
		fileName = string.gsub(fileName, ".plist$", ".png")
		self:addLoadResource(fileName, isAutoRelease, "png")
	end
end

function LoadAsync:addReleaseResource(fileName, resType)
	if resType == nil then
		resType = LoadAsync.getExtension(fileName)
	end
	table.insert(self.releaseFiles, LoadAsync.allocFileData(fileName, resType))
end

function LoadAsync:clearReleseFiles()
	self.releaseFiles = {}
end

function LoadAsync:start(processCallback, finishCallback)
	if self.runCoroutine then
		return false
	end

	self.runCoroutine = coroutine.create(function()
		self:doLogic()
	end)

	self.onProcessCallback = processCallback
	self.onFinishCallback = finishCallback

	return true
end

function LoadAsync:update(delta)
	if self.runCoroutine == nil then
		return
	end
	local ret, msg = coroutine.resume(self.runCoroutine, delta)
	if not ret then
		print("\n\n\n")
		print(msg)
		print("\n\n\n")
		self.runCoroutine = nil
	end
end

function LoadAsync:destroy()
	if self.resFiles == nil then
		return
	end

	for k, v in pairs(self.resFiles) do
		if self.isSupportAsyncLoad(v) then
			textureCache:unbindImageAsync(v.fileName)
		end
	end
	self.runCoroutine = nil
	self.resFiles = nil
	self.loadFileName_True = nil
	self.releaseFiles = nil
end

------------------------------------------------------------public begin------------------------------------------------------------

function LoadAsync:yield()
	self:updatePercent()
	return coroutine.yield()
end

function LoadAsync:clearAutoReleaseFile()
	for k, v in pairs(autoReleaseFile) do
		table.insert(self.releaseFiles, v)
	end
	autoReleaseFile = {}
end

function LoadAsync:doLogic()
	self:calcuLogic()

	self:releaseLogic()

	self:asyncLoadLogic()

	self:syncLoadLogic()

	self:yield()

	if self.onFinishCallback then
		self.onFinishCallback()
	end
end

function LoadAsync:calcuLogic()
	self.curLoadCount = 0
	self.totalLoadCount = 0
	for k, v in pairs(self.resFiles) do
		self.totalLoadCount = self.totalLoadCount + 1
	end

	self.curReleaseCount = 0
	self.totalReleaseCount = 0
	for k, v in pairs(self.releaseFiles) do
		self.totalReleaseCount = self.totalReleaseCount + 1
	end

	self:updatePercent()
end

function LoadAsync:asyncLoadLogic()
	local totalAsyncLoadCount = 0
	local curAsyncLoadCount = 0
	local curTime = 0

	for k, v in pairs(self.resFiles) do
		if self.isSupportAsyncLoad(v) then
			totalAsyncLoadCount = totalAsyncLoadCount + 1
		end
	end

	local loadingCallback = function()
		curAsyncLoadCount = curAsyncLoadCount + 1
		curTime = 0
		self.curLoadCount = self.curLoadCount + 1
	end

	for k, v in pairs(self.resFiles) do
		if self.isSupportAsyncLoad(v) then
			self:doAsyncLoad(v, loadingCallback)
		end
	end

	repeat
		curTime = curTime + self:yield()

		if curAsyncLoadCount >= totalAsyncLoadCount then
			break
		end

		-- 异步加载数量长时间未变化，,还是让程序回调(防止程序一直卡在界面)
		-- 其实后面直接加载资源也是一样的,只是可能卡点点而已
		if curTime > 3.0 then
			self.curLoadCount = totalAsyncLoadCount
			break
		end
	until(false)
end

function LoadAsync:syncLoadLogic()
	local count = 0
	for k, v in pairs(self.resFiles) do
		if not self.isSupportAsyncLoad(v) then
			self:doSyncLoad(v, loadingCallback)
			self.curLoadCount = self.curLoadCount + 1
			if count > 3 then
				count = 0
				self:yield()
			end
		end
	end

	self.curLoadCount = self.totalLoadCount
end

function LoadAsync:releaseLogic()
	local count = 0
	for k, v in pairs(self.releaseFiles) do
		self:doRelease(v)
		self.curReleaseCount = self.curReleaseCount + 1
		if count > 3 then
			count = 0
			self:yield()
		end 
	end

	self.curReleaseCount = self.totalReleaseCount
end

function LoadAsync:doAsyncLoad(fileData, callback)
	if ENABLE_DEBUG then
		print("async load", fileData.fileName)
		if LoadAsync.isTexture(fileData.resType) then
			textureCache:addImageAsync(fileData.fileName, function()
				print("load finish", fileData.fileName)
				callback()
			end)
		end
	else
		if LoadAsync.isTexture(fileData.resType) then
			textureCache:addImageAsync(fileData.fileName, callback)
		end
	end
end

function LoadAsync:doSyncLoad(fileData)
	if ENABLE_DEBUG then
		print("sync load", fileData.fileName)
	end

	if fileData.resType == "plist" then
		spriteFrameCache:addSpriteFrames(fileData.fileName)
	end
end

function LoadAsync:doRelease(fileData)
	if ENABLE_DEBUG then
		print("release", fileData.fileName)
	end

	if fileData.resType == "png" or fileData.resType == "jpg" then
		textureCache:removeTextureForKey(fileData.fileName)
	elseif fileData.resType == "plist" then
		spriteFrameCache:removeSpriteFramesFromFile(fileData.fileName)
	end
end

function LoadAsync:updatePercent()
	if self.onProcessCallback == nil then
		return
	end

	local total = self.totalLoadCount + self.totalReleaseCount
	if total <= 0 then
		self.onProcessCallback(1)
		return
	end

	local cur = self.curLoadCount + self.curReleaseCount
	cur = math.min(cur, total)

	self.onProcessCallback(cur / total)

	if ENABLE_DEBUG then
		print(cur / total)
	end
end

------------------------------------------------------------static begin------------------------------------------------------------

function LoadAsync.isTexture(extension)
	return extension == "png" or extension == "jpg"
end

function LoadAsync.isSupportAsyncLoad(fileData)
	if LoadAsync.isTexture(fileData.resType) then
		return true
	end
	return false
end

function LoadAsync.getExtension(fileName)
	local extension = string.match(fileName, "%.(%w+)$")
	if extension == nil then
		extension = ""
	end
	return extension
end

function LoadAsync.allocFileData(_fileName, _resType)
	local t = {}
	t["fileName"] = _fileName
	t["resType"] = _resType
	return t
end

------------------------------------------------------------static end------------------------------------------------------------

return LoadAsync


