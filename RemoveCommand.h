#pragma once

#include "AbstractCommand.h"


class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* filesys);
	int execute(std::string para);
	void displayInfo();
	~RemoveCommand() = default;
private:
	AbstractFileSystem* fs;
};

