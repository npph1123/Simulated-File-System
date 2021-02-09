#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"
class AbstractFile {
public: 
	virtual std::vector<char> read() =0;
	virtual int write(std::vector<char> input) = 0;
	virtual int append(std::vector<char> input)= 0;
	virtual unsigned getSize() = 0;
	virtual std::string getName() =0;
	virtual void accept(AbstractFileVisitor* visitor) = 0;
	virtual AbstractFile* clone(std::string newName) = 0;
	virtual ~AbstractFile() = default;
};