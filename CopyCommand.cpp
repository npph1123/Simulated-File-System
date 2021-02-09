#include "CopyCommand.h"

using namespace std;
CopyCommand::CopyCommand(AbstractFileSystem* fileSys) 
	: fs(fileSys) {}

void CopyCommand::displayInfo() {
	cout << "cp makes a copy of existing file and add it to the system under a different name" << endl;
	cout <<	"Usage : cp <file_to_copy> <new_name_with_no_extension>" << endl;
}


int CopyCommand::execute(string para) {
	int space = para.find(' '); //find if two files were input
	if (space == string::npos) {
		return not_valid_command;
	}
	string oldname = para.substr(0, space); //everything before space
	string newname = para.substr(space + 1); 

	if (fs->getFileNames().count(oldname) == 0) {
		return file_not_exist;
	}
	AbstractFile* file = fs->openFile(oldname);
	AbstractFile* newFile = file->clone(newname);
	fs->closeFile(file);

	if ((fs->getFileNames().count(newFile->getName()) > 0) || newFile->getName() == oldname ) {
		//if file with new name already existed or new name is same as old name
		delete newFile;
		return not_valid_command;
	}
	fs->addFile(newFile->getName(), newFile);
	return success;
}


