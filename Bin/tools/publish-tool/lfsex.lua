-- @Author : fangcheng
-- @Date   : 2020-05-13 13:45:05
-- @remark : lfs扩展

require("lfs")

local log = print
if logE then
    log = logE
end

-- @@brief 格式化路径
-- @param isdir 是否是目录,如果是则会检查最后是否带'/',没有则自动加上
local function fmtpath(path, isdir)
	path = string.gsub(path, "\\", "/")
    path = string.gsub(path, "/+", "/")
	if isdir then
		if string.sub(path, -1, -1) == "/" then
			return path
		end
		return path .. "/"
	end
	return path
end

os.fmtpath = fmtpath

-- @brief 判断目录是否存在
local function exists(path)
    local iter = lfs.dir(path)
    return iter and iter()
end
os.exists = exists


-- @brief 创建目录
function os.mkdir(path)
    if not exists(path) then
        return lfs.mkdir(path)
    end
    return true
end

-- @brief 递归删除目录
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

--- @brief 通过目录路径递归创建文件夹
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

-- @brief 读取文件内容
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

-- @brief 文件写入
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

-- @brief 文件拷贝
-- @param sourcePath 原路径
-- @param targetPath 目标路径
function os.copyfile(sourcePath, targetPath)
    if not os.mkdirpath(targetPath) then
        return false
    end

    if true then
        return Tools:copyFile(sourcePath, targetPath)
    else
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

        local wf = io.open(targetPath,"wb")
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
    end

    return true
end

-- @brief 文件移动
-- @param sourcePath 原路径
-- @param targetPath 目标路径
function os.movefile(sourcePath, targetPath)
    if not os.mkdirpath(targetPath) then
        return false
    end

    local ok, err, code = os.rename(sourcePath, targetPath)

    if not ok then
        logE(string.format("rename %s, code:%s", tostring(err), tostring(code)))
    end

    return ok
end

-- @brief 返回当前目录
function os.currentdir()
	return fmtpath(lfs.currentdir(), true)
end

-- @brief 遍历文件夹
-- @param rootpath 文件夹路径
-- @param recursion 是否递归遍历
-- @param filter 自定义过滤
function os.seek_dir(dir, recursion, filter)
    local outList = {}

    -- 默认递归
    if recursion == nil then recursion = true end

    local function do_seek(rootpath)
        
        local dirs = {}
        rootpath = os.fmtpath(rootpath, true)

        for entry in lfs.dir(rootpath) do  
            if entry ~= '.' and entry ~= '..' then
                local path = rootpath .. entry  
                local attr = lfs.attributes(path)
                
                path = os.fmtpath(path)
                local isdir = attr.mode == "directory"

                if filter == nil or filter(path, isdir) then
                    table.insert(outList, {
                        path = path,
                        isdir = isdir
                    })
                    if isdir then
                        table.insert(dirs, path)
                    end
                end
            end  
        end

        if recursion then
            for _, v in pairs(dirs) do
                do_seek(v)
            end
        end
    end

    do_seek(os.fmtpath(dir, true))

    return outList
end
