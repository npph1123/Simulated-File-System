#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class LSCommand : public AbstractCommand {
public:
	 LSCommand(AbstractFileSystem* fileSys);
	 int execute(std::string);
	 void displayInfo();
	 ~LSCommand() = default;
private:
	AbstractFileSystem* fs;
};