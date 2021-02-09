#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem* fileSys);
	 int execute(std::string);
	 void displayInfo();
	 ~DisplayCommand() = default;
private:
	AbstractFileSystem* fs;
};
