#pragma once
#include "AbstractFile.h"
// Image file class declaration here
class ImageFile : public AbstractFile {
public:
	ImageFile(std::string filename);
	std::string getName();
	unsigned getSize();
	int write(std::vector<char> inputs);
	int append(std::vector<char> input);
	std::vector<char> read();
	void accept(AbstractFileVisitor* visitor);
	AbstractFile* clone(std::string newName);
	enum returnImage { success, empty_file, invalid_size, mismatch_size, invalid_symbol, not_supported_by_this_type };
private:
	std::string FileName;
	std::vector <char> contents;
	char size; //size of the image
};
