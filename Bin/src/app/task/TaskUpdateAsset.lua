-- @Author : fc
-- @Date   : 2021-8-27 17:35:13
-- @remark : 刷新资源

local TaskUpdateAsset = class("TaskUpdateAsset", G_Class.Task)

function TaskUpdateAsset:ctor(projectFileName)
    local projectDirPath, name = _MyG.EditorProject:genProjectDir(projectFileName)

    self.projectDirPath = projectDirPath

	local FileDialog = require("app.imgui.FileDialog")

	-- 递归所有asset文件
	local allFiles = {}
	local function _seekFile(dir)
		local files = FileDialog.getFiles(dir)

		for k, v in pairs(files) do
			if v.isDir then
				_seekFile(v.fullPath)
			else
				local extension = G_Helper.getExtension(v.fullPath)
				if extension == "asset" then
					table.insert(allFiles, v)
				end
			end
		end
	end

	_seekFile(projectDirPath)

	self.progressWeight = #allFiles
    self.allFiles = allFiles
end

function TaskUpdateAsset:run(taskFlowPipe)
	_MyG.ProjectAssetManager:clearCache()
    -- 读取asset文件内容
    for k, v in pairs(self.allFiles) do
        _MyG.ProjectAssetManager:getAssetData(v.fullPath)
        -- 更新进度
        self.curProgress = k

        taskFlowPipe:yield()
    end

	-- 资源打开
	_MyG.ProjectAssetManager:open(self.projectDirPath)
end

return TaskUpdateAsset