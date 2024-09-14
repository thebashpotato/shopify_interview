local dap = require("dap")

dap.adapters.lldb = {
	type = "executable",
	command = "lldb-dap",
	name = "lldb",
}

dap.configurations.cpp = {
	{
		name = "Launch App tests",
		type = "lldb",
		request = "launch",
		program = function()
			return vim.fn.getcwd() .. "/build/app/tests/example_app_tests"
		end,
		cwd = "${workspaceFolder}",
		stopOnEntry = false,
	},
	{
		name = "Launch Main Application",
		type = "lldb",
		request = "launch",
		program = function()
			return vim.fn.getcwd() .. "/build/app/example_app"
		end,
		cwd = "${workspaceFolder}",
		stopOnEntry = false,
	},
}
