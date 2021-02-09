// definition of ImageFile class here
#include "ImageFile.h"
#include <vector>
#include <iostream>
using namespace std;
ImageFile::ImageFile(std::string filename)
	: FileName(filename), size('0')
{}


string ImageFile::getName() {
	return FileName;
}

unsigned ImageFile::getSize() {
	return contents.size();
}

int ImageFile::write(vector<char> input) {
	if (input.size() == 0) {
		return empty_file;
	}
	size = input.back();
	if (size < '0' || size > '9') {
		size = '0'; //zero out
		contents.clear(); //destroy everything inside.
		return invalid_size;
	}
	int dimension = size - '0';
	if (input.size() - 1 != dimension * dimension) { //-1 to account for size
		size = '0'; //"zero out"
		contents.clear(); //destroy everything inside.
		return mismatch_size;
	}

	int i = 0;
	while (i < input.size() - 1) { //-1 one cause size
		char elt = input[i];
		if ((elt != ' ') && (elt != 'X')) {//invalid input, delete everything
			size = '0'; //"zero out"
			contents.clear(); //destroy everything inside.
			return invalid_symbol;
		}
		contents.push_back(elt);
		i++;
	}
	return success;
}
int ImageFile::append(std::vector<char> input) {
	return not_supported_by_this_type;
}

vector<char> ImageFile::read() {
	/*int size_num = size - '0';
	for (int i = size_num-1; i >= 0; i--) {
		for (int j = 0; j < size_num; j++) {
			int index = i * size_num + j;
			cout << contents[index];
		}
		cout << endl;
	}*/
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	if (visitor) {
		visitor->visit_ImageFile(this);
	}
}

AbstractFile* ImageFile::clone(string newName) {
	//new name doesn't have extension
	AbstractFile* file = new ImageFile(newName + ".img");
	file->write(this->read());
	return file;
}
