#include "CatCommand.h"

using namespace std;
CatCommand::CatCommand(AbstractFileSystem* fileSys)
	: fs(fileSys) {}

void CatCommand::displayInfo() {
	cout << "cat concatenates the file (if include -a) or overwrite it" << endl;
	cout << "Usage: cat <filename> [-a]" << endl;
}


int CatCommand::execute(string para) {
	bool append = false;
	string filename;
	string action = "write";
	if (para.substr(para.size() - 3) == " -a") {
		//append is true
		filename = para.substr(0, para.size() - 3);
		append = true;
		action = "append";
	}
	else { 
		filename = para;

	}
	if (!fs->getFileNames().count(filename)) {
		return file_not_exist;
	}

	AbstractFile* file = fs->openFile(filename);
	vector<char> content = file->read();

	if (append) { //if append, print out as required
		for (auto it = content.begin(); it != content.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}

	vector<char> temp_content; //store input from user, either overide or append
	string input;

	while (1) {
		cout << "Enter data you would like to " << action << " to the file." << "Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
		getline(cin, input);
		if (input == ":q") { //quit, don't do anythin else
			fs->closeFile(file);
			return success;
		}
		if (input == ":wq") {
			temp_content.pop_back(); //get rid of ":wq"
			int flag;
			if (append) {
				flag = file->append(temp_content);
			}
			else {
				flag = file->write(temp_content);
			}
			fs->closeFile(file);
			return flag;
		}
		temp_content.insert(temp_content.end(), input.begin(), input.end());
		temp_content.push_back('\n'); //add newline character back since getline trim it off
	}
	return success;
}
