// studio 18 - file factory interface declared here
#pragma once

#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile (std::string filename) = 0;
};
