#pragma once
#include <string>
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class CommandPrompt {
public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();


private:
	std::map<std::string, AbstractCommand*> commands;
	AbstractFileSystem* fs;
	AbstractFileFactory* ff;
	enum return_commandprompt { success, fail_add_command, user_quit };
};
