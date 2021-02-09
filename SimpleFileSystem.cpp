// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile* file_ptr) {
	if (all_files.count(filename) > 0) { //if file already existed
		return file_already_existed;
	}
	if (file_ptr == NULL) {
		return null_file_pointer;
	}
	all_files.insert(std::pair<string, AbstractFile*>(filename, file_ptr));
	return success;
}

int SimpleFileSystem::createFile(string filename) {
	if (all_files.count(filename) > 0) { //if file already existed
		return file_already_existed;
	}
	string text = ".txt";
	string image = ".img";
	AbstractFile* file;
	if (filename.find(text) != std::string::npos) { //if found file extension
		file = new TextFile(filename);
		all_files.insert(std::pair<string, AbstractFile*>(filename, file));
		return success;
	}
	else if (filename.find(image) != std::string::npos){
		file = new ImageFile(filename);
		all_files.insert(std::pair<string, AbstractFile*>(filename, file));
		return success;
	}
	else {
		return file_extension_not_supported;
	}
}

AbstractFile* SimpleFileSystem::openFile(string filename) {
	if (all_files.find(filename) == all_files.end()) { //if file not existed
		return nullptr;
	}
	AbstractFile* file = all_files.find(filename)->second; 
	if (currently_open.find(file) == currently_open.end()) { //if not currently open
		currently_open.insert(file);
		return file;
	}
	else { //file is already open.
		return nullptr;
	}
}

int SimpleFileSystem::closeFile(AbstractFile* file_ptr) {
	if (currently_open.find(file_ptr) != currently_open.end()) { //if currently open
		currently_open.erase(file_ptr);
		return success;
	}
	return file_not_open;
}

int SimpleFileSystem::deleteFile(string filename) {
	if (all_files.count(filename) == 0) { //if file not existed
		return file_not_existed;
	}
	AbstractFile* file = all_files.find(filename)->second;
	if (currently_open.find(file) != currently_open.end()) { //if currently open
		return file_currently_open;
	}
	all_files.erase(filename);
	delete file; //deletefile
	return success;
}

set <string> SimpleFileSystem::getFileNames() {
	set <string> fileNames;
	for (auto it = all_files.begin(); it != all_files.end(); it++)
	{
		fileNames.insert(it->first);  // string (key)
	}
	return fileNames;
}