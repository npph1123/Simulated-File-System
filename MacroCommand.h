#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*);
	 int execute(std::string);
	 void displayInfo();
	 void addCommand(AbstractCommand*);
	 void setParseStrategy(AbstractParsingStrategy*);
	 ~MacroCommand() = default;

private:
	std::vector<AbstractCommand*> allCommands;
	AbstractParsingStrategy* parsingStrategy;
	AbstractFileSystem* fs;
};