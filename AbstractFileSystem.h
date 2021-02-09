#pragma once
#include "AbstractFile.h"
#include <set>
#include <string>

class AbstractFileSystem {
public:
	virtual int addFile(std::string filename, AbstractFile* file_ptr)=0;
	virtual int createFile(std::string filename) = 0;
	virtual int deleteFile(std::string filename) = 0;
	virtual AbstractFile* openFile(std::string filename) = 0;
	virtual int closeFile(AbstractFile* file_ptr) = 0;
	virtual std::set <std::string> getFileNames() = 0;
	enum returnAFS {
		success, file_already_existed, null_file_pointer,
		file_extension_not_supported, file_not_existed, file_not_open, file_currently_open,
	};
};
