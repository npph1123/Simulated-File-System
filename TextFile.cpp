//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
#include <iostream>
using namespace std;
TextFile::TextFile(std::string name)
	: FileName(name)
{}
string TextFile::getName() {
	return FileName;
}

unsigned TextFile::getSize() {
	return contents.size();
}


int TextFile::write(vector<char> input) {
	contents = input;
	return 0;
}

int TextFile::append(std::vector<char> input) {
	for (vector<char>::const_iterator i = input.begin(); i != input.end(); ++i) {
		contents.push_back(*i);
	}
	return 0;
}

vector<char> TextFile::read() {
	/*for (vector<char>::const_iterator i = contents.begin(); i != contents.end(); ++i)
		cout << *i;*/
	return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	if (visitor) {
		visitor->visit_TextFile(this);
	}
}

AbstractFile* TextFile::clone(string newName) {
	//newName has no extension, so we must add it.
	AbstractFile* file = new TextFile(newName + ".txt");
	file->write(this->read());
	return file;
}
