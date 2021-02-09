#include "TouchCommand.h"
#include <iostream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fileSys, AbstractFileFactory* fileFactory)
	:ff(fileFactory), fs(fileSys) {}

void TouchCommand::displayInfo() {
	cout << "touch creates a file" << endl;
	cout << "Usage: touch <filename>" << endl;
}
int TouchCommand::execute(string input) {
	if (input.substr(input.size() - 3) == " -p") {// -p option, password
		string filename = input.substr(0, input.size() - 3);
		AbstractFile* file_protected = ff->createFile(filename);
		if (file_protected == nullptr) {
			return file_fail_create;
		}

		else {
			string password;
			cout << "Enter your password: " << endl;
			cin >> password;
			AbstractFile* proxy = new PasswordProxy(file_protected, password);
			int add = fs->addFile(filename, proxy);
			if (add != success) {
				delete proxy;
			}
			return add;
		}
	}
	else { //input is just regular file now
		AbstractFile* f = ff->createFile(input);
		if (f == nullptr) { //file failed to create
			cout << "file failed to create" << endl;
			return file_fail_create;
		}
		int add = fs->addFile(input, f);
		if (add != success) {

			delete f;
		}
		return add;
	}
}
