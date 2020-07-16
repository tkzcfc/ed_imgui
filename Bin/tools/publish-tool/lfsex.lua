-- @Author : fangcheng
-- @Date   : 2020-05-13 13:45:05
-- @remark : lfs扩展

require("lfs")

local log = print
if logE then
    log = logE
end

local function fmtpath(path, isdir)
	path = string.gsub(path, "\\", "/")
	if isdir then
		if string.sub(path, -1, -1) == "/" then
			return path
		end
		return path .. "/"
	end
	return path
end

os.fmtpath = fmtpath

function exists(path)
    local iter = lfs.dir(path)
    return iter and iter()
end
os.exists = exists

function os.mkdir(path)
    if not exists(path) then
        return lfs.mkdir(path)
    end
    return true
end

function os.rmdir(path)
	path = fmtpath(path)
    if exists(path) then
        local function _rmdir(path)
            local iter, dir_obj = lfs.dir(path)
            while true do
                local dir = iter(dir_obj)
                if dir == nil then break end
                if dir ~= "." and dir ~= ".." then
                    local curDir = path..dir
                    local mode = lfs.attributes(curDir, "mode") 
                    if mode == "directory" then
                        _rmdir(curDir.."/")
                    elseif mode == "file" then
                    	local succ, des = os.remove(curDir)
						if not succ then
            				print(path, des)
            			end
                    end
                end
            end
            local succ, des = lfs.rmdir(path)
            if not succ then
            	print(path, des)
            end
            return succ
        end
        return _rmdir(path)
    end
    return true
end

function os.mkdirpath(path)
	path = fmtpath(path)
    local idx = 1
    while true do
        local pos = string.find(path, "/", idx)
        if pos then
            idx = pos + 1
            local dirname = string.sub(path, 1, pos)
            local iter = lfs.dir(dirname)
            if iter and not iter() then
                local ok, msg = lfs.mkdir(dirname)
                if not ok then
                    log("mkdir", dirname)
                    log(msg)
                    return false
                end
            end
        else
            break
        end
    end
    return true
end

function os.readfile(filename, mode)
	mode = mode or "rb"
    local file = io.open(filename, mode)
    if not file then
        log(string.format("The file %q is cannot be read", filename))
      return ""
    end

    local content = file:read("*a")
    io.close(file)
    return content
end

function os.writefile(path, content, mode)
    if not os.mkdirpath(path) then
        return false
    end

    mode = mode or "wb"
    local file = io.open(path, mode)
    if file then
        if not file:write(content) then
            io.close(file)
            return false
        end
        io.close(file)
        return true
    else
        return false
    end
end

function os.copyfile(sourcePath, targetPath)
    if not os.mkdirpath(targetPath) then
        return false
    end

    local rf = io.open(sourcePath,"rb")
    
    if not rf then
        log(string.format("The file %q is cannot be read", sourcePath))
        return false
    end
    
    local len = rf:seek("end")
    
    rf:seek("set",0)--重新设置文件索引为0的位置

    local data = ""
    if len > 0 then
        data = rf:read(len)  --根据文件长度读取文件数据
        if not data then
            rf:close()
            return false
        end
    end

    local wf = io.open(targetPath,"wb")  --用“wb”方法写入二进制文件
    if not wf or not wf:write(data) then
        log(string.format("Failed to write file %q", targetPath))
        rf:close()
        if wf then
            wf:close()
        end
        return false
    end
    rf:close()
    wf:close()

    return true
end

function os.currentdir()
	return fmtpath(lfs.currentdir(), true)
end
