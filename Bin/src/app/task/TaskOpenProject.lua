-- @Author : fc
-- @Date   : 2021-8-27 17:34:17
-- @remark : 打开工程任务

local TaskOpenProject = class("TaskOpenProject", G_Class.Task)

function TaskOpenProject:ctor(projectFileName)
    self.projectFileName = projectFileName
end

function TaskOpenProject:run(taskFlowPipe)
    _MyG.EditorProject:open(self.projectFileName, self, taskFlowPipe)
end

return TaskOpenProject