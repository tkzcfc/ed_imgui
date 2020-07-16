-- Auto Generate by Excel 'language.xlsx', Don't try to modify!
-- Generated on 2020-06-09 21:26:39.

local M = {}

M.Data = {}
M.Data['UD_DUPLICATE_KEY'] = {cn = '"{1}" 中有重复key"{0}"', en = 'Duplicate key "{0}" in "{1}"'}
M.Data['UD_EMPTY_KEY'] = {cn = '"{0}"中的userdata有key为空的情况', en = 'Key in "{0}" is empty'}
M.Data['UD_FLOAT_KEY_WARN'] = {cn = '"{0}"中存在key为浮点数"{1}",将被强制转换为整形"{2}"', en = 'Key in "{0}" is floating-point number "{1}", which will be converted to "{2}"'}
M.Data['EXECUTE_COMMAND_FAILE'] = {cn = '执行命令失败:%q', en = 'Failed to execute command %q'}
M.Data['PROJECT_PATH_EMPTY'] = {cn = '工程路径为空', en = 'Project path is empty'}
M.Data['TRAVERSE_DIR_FAILED'] = {cn = '遍历目录%q失败', en = 'Traverse directory %q failed'}
M.Data['READ_FILE_FAILED'] = {cn = '文件读取失败', en = 'File read failed'}
M.Data['DETECTION_FILE_FAILED'] = {cn = '文件检测失败', en = 'File detection failed'}
M.Data['EXPORT_FILE_FAILED'] = {cn = '文件导出失败', en = 'File export failed'}
M.Data['COPY_FILE_FAILED'] = {cn = '文件拷贝失败', en = 'File copy failed'}
M.Data['DIR_EMPTY_OR_ILLEGAL_PATH'] = {cn = '目录为空或路径非法', en = 'Directory is empty or path is illegal'}
M.Data['PARS_FILE_FAILED'] = {cn = '文件%q解析失败', en = 'File %q parsing failed'}
M.Data['FILE_IS_EMPTY'] = {cn = '文件%q内容为空', en = 'The file %q is empty'}
M.Data['FIELD_MISS_FORM_FILE'] = {cn = '文件"{1}"中缺少字段"{0}"', en = 'Field "{0}" is missing from file "{1}"'}
M.Data['PUBLISH_FILE_FAILED'] = {cn = '文件"{0}"发布失败', en = 'Failed to publish file "{0}"'}
M.Data['PUBLISH_FILE_SUCCESS'] = {cn = '文件"{0}"发布成功', en = 'Publish file "{0}" succeeded'}
M.Data['WRITE_FILE_FAILED'] = {cn = '文件"{0}"写入失败', en = 'Failed to write file "{0}"'}
M.Data['PUBLISH_FILE_FAILED_AND_WRITE'] = {cn = '文件"{0}"发布失败<写入失败>', en = 'Failed to publish file "{0}" <write failed>'}
M.Data['EXPORT_FILE_FAILED_UNKNOWN_TYPE'] = {cn = '文件"{0}"导出失败,不支持导出类型"{1}"', en = 'Export of file "{0}" failed, unknown type "{1}"'}
M.Data['PUB_PLUGIN_FAIL_NO_IMP'] = {cn = '插件"{0}"没有对应的发布逻辑实现', en = 'Publishing implementation for plug-in "{0}" not found'}
M.Data['COPY_FILE_FAILED_FMT'] = {cn = '文件"{0}"拷贝失败', en = 'Failed to copy file "{0}"'}
M.Data['COPY_FILE_SUC_FMT'] = {cn = '文件"{0}"拷贝成功', en = 'Copy file "{0}" succeeded'}
M.Data['PUBLISH_SUCCESS'] = {cn = '发布成功', en = 'publish finished'}
M.Data['PUBLISH_FAILED'] = {cn = '发布失败', en = 'publish failed'}
M.length = 24

function M.getData(key)
    return M.Data[key]
end

function M.getItem(key1, key2)
    if M.Data[key1] == nil then
        print(string.format("错误: 文件'Lang.lua'中配置'%s'不存在!!!!!!!!!!!!!!!!!!!!!!!", tostring(key1)))
        return
    end
    return M.Data[key1][key2]
end

return M
