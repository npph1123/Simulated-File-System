#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CopyCommand : public AbstractCommand {
public:
	 CopyCommand(AbstractFileSystem*);
	 int execute(std::string);
	 void displayInfo();
	 ~CopyCommand() = default;

private:
	AbstractFileSystem* fs;
};
