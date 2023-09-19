add_rules("mode.debug", "mode.releasedbg")

add_requires("zeromq 4.3.2", {
    alias = "zeromq",
    configs = {shared = true, pic = true, vs_runtime = "MD"}
})

target("task_forward")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("zeromq")

    -- 自动生成 compile_commands.json 帮助代码补全跳转
    after_build(function (target)
        import("core.base.task")
        task.run("project", {kind = "compile_commands", outputdir = ".vscode"})
    end)
target_end()
