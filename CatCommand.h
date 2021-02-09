#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"

class CatCommand : public AbstractCommand {
public:
	 CatCommand(AbstractFileSystem*);
	 int execute(std::string );
	 void displayInfo();
	 ~CatCommand() = default;
private:
	AbstractFileSystem* fs;

};