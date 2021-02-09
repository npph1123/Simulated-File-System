#include "MacroCommand.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* fileSys)
	: fs(fileSys) {}

void MacroCommand::displayInfo() {
	cout << "This is a macro command" << endl;
}


void MacroCommand::addCommand(AbstractCommand* cmd) {
	allCommands.push_back(cmd);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* APS) {
	parsingStrategy = APS;
}


int MacroCommand::execute(string filename) {
	vector<string> inputString = parsingStrategy->parse(filename);
	for (int i = 0; i < allCommands.size(); i++) {
		int status = allCommands[i]->execute(inputString[i]);
		if (status !=  success) { //if one command fails to execute, return error
			return status;
		}
	}
	return success;
}

