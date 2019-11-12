local M = {}

M["新建"] = "New"
M["打开"] = "Open"
M["取消"] = "Cancel"
M["确定"] = "OK"
M["路径"] = "path"
M["转到"] = "go to"
M["向上"] = "up"
M["保存"] = "Save"
M["文件已经存在，是否替换"] = "overlay files?"
M["是"] = "Y"
M["否"] = "N"
M["文件夹名字"] = "Folder Name"
M["文件已经存在"] = "file already exists"


M["FAILE_DEL_FILE"] = "Failed to delete file"
M["FAILE_DEL_PUB_FILE"] = "Failed to delete publish file"
M["DLG_IS_DEL_FILE"] = "Do you want to delete this file?"
M["DLG_DEL_FILE_NO_CLOSE"] = "The file is being edited"
M["DLG_IS_SVAE_ITEM"] = "Save change to the following items?"


M["FILE_EXIST_FMT"] = "Does the file %q already exist? Is it replaced?"
M["PROJECT_EXISTS"] = "The project already exists"
M["PROJECT_CREATE_SUCCESS"] = "Project Creation Success"
M["PROJECT_CREATE_FAIL"] = "Project creation failed"
M["FOLDER_CREATE_FAIL"] = "Folder creation failed"
M["PROJECT_CREATE_FAIL_EXIST"] = "Project already exists"


M["EA_POS"] = "Position"
M["EA_ANC"] = "AnchorPoint"
M["EA_SIZE"] = "Size"
M["EA_SCALE"] = "Scale"
M["EA_ROTATION"] = "Rotation"
M["EA_OPACITY"] = "Opacity"
M["EA_COLOR"] = "Color"
M["EA_RESOURCE"] = "Resource"
M["EA_BASE_ATTR"] = "Base"
M["EA_NAME"] = "Name"
M["EA_WORK_SPACE"] = "workspace"
M["EA_Z_ORDER"] = "Order"
M["EA_LINES"] = "Line"
M["EA_DELETE"] = "delete"
M["EA_EDIT"] = "edit"
M["EA_CREATE"] = "create"
M["EA_IS_LEFT"] = "normal left"
M["EA_IS_VISIBLE"] = "visible"
M["EA_RECTS"] = "Rect"
M["EA_SKEW_X"] = "skew x"
M["EA_SKEW_Y"] = "skew y"
M["EA_USE_TEXTURE_SIZE"] = "Using Texture Size"
M["EA_FEATURES"] = "Unique"
M["EA_WORK_SPACE_COLOR"] = "Color"
M["EA_RESOURCE_MAP_BG_LAYER"] = "Background Layer"
M["EA_RESOURCE_MAP_GM_LAYER"] = "Game Layer"
M["EA_RESOURCE_MAP_FG_LAYER"] = "Foreground Layer"
M["EA_VISIBLE_CKBOX_MAP_BG_LAYER"] = "Visible##BG"
M["EA_VISIBLE_CKBOX_MAP_GM_LAYER"] = "Visible##GM"
M["EA_VISIBLE_CKBOX_MAP_FG_LAYER"] = "Visible##FG"
M["EA_NODE_MOVE_UP_ITEM"] = "Move up"
M["EA_NODE_MOVE_DOWN_ITEM"] = "Move down"
M["EA_IS_HIDE_ALL_REVIVEPOINT"] = "Hide the resurrection point"

M["WC_Sprite"] = "Sprite"
M["WC_Image"] = "Image"
M["WC_RevivePoint"] = "RevivePoint"

local ch = require("app.lang.ch.Text")
for k,v in pairs(ch) do
	if M[k] == nil then
		M[k] = k
	end
end

return M