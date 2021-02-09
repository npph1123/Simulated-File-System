#pragma once
#include "AbstractFileSystem.h"
#include <map>
#include <string>
#include <set>
class SimpleFileSystem : public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile* > all_files; //contains all file
	std::set<AbstractFile*> currently_open;

public:
	 int addFile(std::string filename, AbstractFile* file_ptr);
	 int createFile(std::string filename);
	 int deleteFile(std::string filename);
	 AbstractFile* openFile(std::string filename);
	 int closeFile(AbstractFile* file_ptr);
	 std::set <std::string> getFileNames();

};
