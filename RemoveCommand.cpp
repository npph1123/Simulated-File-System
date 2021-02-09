#include "RemoveCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys)
	: fs(fileSys) {}

int RemoveCommand::execute(std::string fileName) {
	int result = fs->deleteFile(fileName);
	return result;
}

void RemoveCommand::displayInfo() {
	cout << "Remove a file in the file system" << endl;
	cout << "Usage: rm <filename>" << endl;
}