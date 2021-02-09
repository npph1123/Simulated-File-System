#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"
#include <map>
class SimpleFileFactory: public AbstractFileFactory {
public: 
	AbstractFile* createFile(std::string filename);
	enum returnSFF {
		success, file_already_existed, null_file_pointer,
		file_extension_not_supported, file_not_existed, file_not_open, file_currently_open,};
};

