#include "DisplayCommand.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fs(fileSys) {
}

void DisplayCommand::displayInfo() {
	cout << "ds opens a file and displays its contents, either formatted or not (when given the “ - d” option for data only)" << endl;
	cout << "Usage: ds <filename> [-d]" << endl;
}


int DisplayCommand::execute(string filename) {
	bool format = true;
	if (filename.substr(filename.size() - 3) == " -d") {
		filename = filename.substr(0, filename.size() - 3);
		format = false;
	}
	set <string> fn = fs->getFileNames();
	if ( !fn.count(filename) ) {
		return file_not_exist;
	}

	AbstractFile* file = fs->openFile(filename);

	if (format) {
		//print format
		AbstractFileVisitor* BDV = new BasicDisplayVisitor();
		file->accept(BDV);
	}
	else {
		//raw data
		vector<char> contents = file->read();
		for (auto it = contents.begin(); it != contents.end(); ++it) {
			cout << *it;
		}
	}
	cout << endl;
	fs->closeFile(file);
	return success;
}

