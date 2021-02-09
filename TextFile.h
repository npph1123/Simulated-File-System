#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile: public AbstractFile {
public:
	TextFile(std::string name);
	std::string getName();
	unsigned getSize();
	std::vector<char> read();
	int write(std::vector<char> input);
	int append(std::vector<char> input);
	void accept(AbstractFileVisitor* visitor);
	AbstractFile* clone(std::string newName);

private:
	std::vector <char> contents;
	std::string FileName;
};