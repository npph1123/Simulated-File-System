#pragma once
#include "LSCommand.h"
#include "BasicDisplayVisitor.h"
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


LSCommand::LSCommand(AbstractFileSystem* fileSys) :
	fs(fileSys) {}

int LSCommand::execute(string para) {
	set <string> fileNames = fs->getFileNames();
	if (para == "-m") { //meta data
		for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
		{
			string file_name = *it;
			AbstractFile* file = fs->openFile(file_name);

			string type;
			if (file_name.find(".txt") != string::npos) {
				type = "text";
			}

			else if (file_name.find(".img") != string::npos) {
				type = "image";
			}

			cout.width(25); cout << left << file->getName() << " ";
			cout.width(25); cout << left << type << " ";
			cout.width(25); cout << left << file->getSize() <<" ";
			cout << endl;
			fs->closeFile(file);
		}
		return success;
	}
	else if (para == "") { //regular print
		int count = 0; //formatting purposes, 2 items per line
		for (auto it = fileNames.begin(); it != fileNames.end(); ++it) {
			cout.width(25); cout << left << *it;
			count++;
			if (count % 2 == 0) {
				cout << endl;
			}
		}
		return success;
	}
	else {
		return command_fail;
	}

}
 void LSCommand::displayInfo(){
	 cout << "lists the contents of the current directory, add -m for medata" << endl;
	 cout << "Usage: ls, ls  -m" << endl;
}