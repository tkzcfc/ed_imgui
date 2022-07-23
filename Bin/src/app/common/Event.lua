-- @Author: fangcheng
-- @Date:   2021-07-24 14:48:54
-- @remark: 事件定义

-- 系统事件
cc.exports.SysEvent = enum {
    "ON_ASSET_DRAG_END",            -- asset 资源拖拽结束
    "ON_DRAG_PRE_WIDGET",            -- 预制体widget拖拽结束

    "EVENT_WINDOW_RESIZED",         -- 窗口大小发生改变

    "ON_GUI_BEGIN",                 -- 主GUI绘制逻辑-GUI绘制开始
    "ON_GUI",                       -- 主GUI绘制逻辑-GUI绘制
    "ON_GUI_POPUP",                 -- 主GUI绘制逻辑-popup绘制
    "ON_GUI_END",                   -- 主GUI绘制逻辑-GUI绘制结束

    "ON_WINDOW_GUI_ROLE_ACTION",    -- RoleActionWindow-GUI绘制
    "ON_WINDOW_GUI_ROLE_SKILL",     -- RoleSkillWindow-GUI绘制
    "ON_WINDOW_ROLE_DOC_CHANGE",    -- RoleSkillWindow菜单切换

    "ON_ATTRIBUTE_CONTENT_GUI",     -- 属性面板GUI绘制
    "ON_NODE_CONTENT_GUI",          -- node面板GUI绘制
    "ON_NODE_CONTENT_GUI_END",      -- node面板GUI绘制结束
    "ON_GUI_MAIN_MENUBAR",          -- 主菜单栏GUI绘制
    "ON_TIMELINE_GUI",              -- timeline面板GUI绘制


    "ON_ROLE_TIMELINE_DOC_CHANGE",  -- 角色timeline面板菜单切换
    "ON_ROLE_ACTION_ID_CHANGE",     -- 角色动作id改变

    "ON_SHOW_BOTTOM_DOCUMENT",    -- 事件-控制底部documentManager显示页签

    "DO_CHANGE_ASSET",              -- 更改资源
    "ON_EDIT_CONTEXT_INIT_EVENT",   -- 编辑器context事件初始化消息
    "ON_EDIT_CONTENT_SCALE",        -- 编辑器context画布缩放改变事件

    "ON_GUI_MAIN_MENUBAR_FILE_NEW",  -- 主菜单-新建选项-子菜单GUI绘制
    "ON_GUI_MAIN_MENUBAR_FILE_OPEN", -- 主菜单-打开选项-子菜单GUI绘制
    "ON_GUI_MAIN_MENUBAR_PROJECT",   -- 主菜单-项目选项-子菜单GUI绘制
    "ON_GUI_MAIN_MENUBAR_FILE",      -- 主菜单-文件选项-子菜单GUI绘制
    "ON_GUI_MAIN_MENUBAR_TOOL",      -- 主菜单-工具选项-子菜单GUI绘制

    "ON_MENU_FILE_SAVE",            -- 菜单子项点击事件(Menu/File/Save)
    "ON_MENU_FILE_NEW_FOLDER",      -- 菜单子项点击事件(Menu/File/New/Folder)
    "ON_MENU_FILE_NEW_PROJECT",     -- 菜单子项点击事件(Menu/File/New/Project)
    "ON_MENU_FILE_OPEN_PROJECT",    -- 菜单子项点击事件(Menu/File/Open/Project)
    "ON_MENU_FILE_SAVEALL",         -- 菜单子项点击事件(Menu/File/SaveAll)
    "ON_MENU_PROJECT_PROJECT_SETTINGS",-- 菜单子项点击事件(Menu/Project/Project settings)

    "ON_DUCUMENT_CLOSED",           -- document关闭完毕
    "ON_DUCUMENT_CLOSE_CANCEL",     -- document关闭弹窗后,用户点击取消


    "ASSET_ON_ITEM_HOVERED",        -- 资源列表中,鼠标悬停在资源上
    "ASSET_ON_LEFT_DOUBLE_CLICK",   -- 资源列表中,鼠标左键双击资源
    "ASSET_ON_RIGHT_CLICK",         -- 资源列表中,鼠标右键单击资源
    "ASSET_MENU_ONGUI",             -- 资源列表中,资源被右键单击弹出的菜单栏GUI绘制


    "ON_ASSET_CONTENT_UPDATE",      -- 资源更新事件,发送此事件让资源管理器更新Content文件夹下的资源
    "ON_ASSET_COCOS_UPDATE",        -- 资源更新事件,发送此事件让资源管理器更新Cocos文件夹下的资源
    "ON_PRJ_USER_TMP_DATA_CHANGE",  -- 工程用户临时数据发生改变


    "ON_KEY_BOARD_SAVE",            -- 按键事件-保存 (Ctrl + S)
    "ON_KEY_BOARD_UNDO",            -- 按键事件-撤销 (Ctrl + Z)
    "ON_KEY_BOARD_ALL",             -- 按键事件-全选 (Ctrl + A)
    "ON_KEY_BOARD_DELETE",          -- 按键事件-删除 (Delete)
    "ON_KEY_BOARD_SINGLE_PRESSED",  -- 按键事件-当前键盘只有一个按键按下时触发的事件

    "ON_CHANGE_LANG",               -- 事件-语言切换


    "ON_MOUSE_MOVE",                -- 鼠标移动事件
    "ON_MOUSE_SCROLL",              -- 鼠标滚动事件
    "ON_MOUSE_DOWN",                -- 鼠标按下事件
    "ON_MOUSE_UP",                  -- 鼠标抬起事件


    "ON_TOUCH_BEGAN",               -- 触摸开始事件
    "ON_TOUCH_MOVED",               -- 触摸移动事件
    "ON_TOUCH_ENDED",               -- 触摸结束事件
    "ON_TOUCH_CANCELLED",           -- 触摸取消事件


    "CONTENT_ON_CONTENT_CHANGE",    -- 编辑中的内容发生改变
    "CONTENT_ON_EDITOR_CONTENT_SAVE",-- 让当前在编辑的窗口保存当前内容

    "SET_GAME_RES_DIR",             -- 设置游戏资源路径

    
    "ON_REBUILD_SKILL_NAME_NTF",            -- 通知role重构技能名称数据

    "TAG",
}


-- 编辑器事件
cc.exports.EditorEvent = enum {
    10000,
    "ON_CHANGE_POSITION",           -- 位置改变
    "ON_CHANGE_NODE_ORDER",         -- 节点顺序改变
    "ON_CHANGE_PARENT",             -- 父节点改变
    "ON_CHANGE_NAME",               -- 名称改变
    "ON_CHANGE_ANCHOR_POINT",       -- 锚点改变
    "ON_CHANGE_SIZE",               -- size 改变
    "ON_CHANGE_SCALE",              -- scale 改变
    "ON_CHANGE_ROTATION",           -- 旋转改变
    "ON_CHANGE_OPACITY",            -- 透明度改变
    "ON_CHANGE_COLOR",              -- 颜色改变
    "ON_CHANGE_SKEW",               -- 斜率改变
    "ON_CHANGE_SPRITERESOURCE",     -- 纹理资源改变
    "ON_CHANGE_IMAGE_USE_TEX_SIZE", -- Image元素是否使用纹理自身尺寸
    "ON_CHANGE_USERDATA",           -- userdata改变
    "ON_CHANGE_PREFABRESOURCE",     -- 预制资源改变
    
    -- 动画
    "ON_CHANGE_ARMATURE_PLAY",      -- 动画播放数据改变

    "ON_CHANGE_WORK_SPACE",         -- 工作区域大小改变
    "ON_CHANGE_WORK_SPACE_COLOR",   -- 工作区域颜色改变

    -- 插件PluginLineRect
    "ON_CHANGE_LINE_DATA",          -- 线段数据改变
    "ON_CHANGE_RECT_DATA",          -- 矩形数据改变
    "ON_CHANGE_LINE_RECT_USERDATA", -- userdata改变
    "ON_CHANGE_LINE_VISIBLE",       -- 线段是否显示
    "ON_CHANGE_RECT_VISIBLE",       -- 矩形是否显示

    -- 插件PluginMapLayer
    "ON_CHANGE_BG_LAYER_ASSET",     -- 背景层资源改变
    "ON_CHANGE_FG_LAYER_ASSET",     -- 前景层资源改变
    "ON_CHANGE_GM_LAYER_ASSET",     -- 游戏曾资源改变

    -- 复活点
    "ON_CHANGE_REVIVEPOINT_CREATE", -- 创建复活点
    "ON_CHANGE_REVIVEPOINT_DEL",    -- 删除复活点
    "ON_CHANGE_REVIVEPOINT_POS",    -- 复活点位置改变

    -- 人物编辑器
    "ROLE_CONTEXT_BEGIN",               -- role begin

    
    "ROLE_ACTION_BEGIN",                -- action begin
    "ON_CHANGE_ROLE_ACTION",            -- 人物编辑器-动作编辑-动作数据改变
    "ON_CHANGE_ROLE_ACTION_ID",         -- 人物编辑器-动作编辑-动作数据改变(其中id也发生变化了,需要通知技能编辑器也改变对应的引用id)
    "ROLE_ACTION_END",                  -- action end

    
    "ROLE_SKILL_BEGIN",                 -- skill begin
    "ON_CHANGE_ROLE_SKILL",             -- 人物编辑器-技能编辑-技能数据改变
    "ROLE_SKILL_END",                   -- skill end

    "ON_CHANGE_ROLE_SIZE",              -- 改变角色大小
    "ON_CHANGE_ROLE_RADIUS",              -- 改变角色半径
    "ON_CHANGE_ROLE_MASS",              -- 改变角色质量
    "ON_CHANGE_ROLE_VELOCITY",          -- 改变角色速度
    "ON_CHANGE_ROLE_IMPULSION",         -- 改变角色冲力
    "ON_CHANGE_ROLE_FORCE",             -- 改变角色力
    "ON_CHANGE_ROLE_DIRECTION",         -- 改变角色资源朝向
    "ON_CHANGE_ROLE_DFT_SKILL_IDX",     -- 改变技能默认技能下标



    "ROLE_CONTEXT_END",                 -- role end
}
