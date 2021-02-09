// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(string filename) {
	string text = ".txt";
	string image = ".img";
	AbstractFile* file;

	if (filename.find(text) != std::string::npos) { //if found file extension
		file = new TextFile(filename);
		return file;
	}
	else if (filename.find(image) != std::string::npos) {
		file = new ImageFile(filename);
		return file;
	}
	else {
		return nullptr;
	}

}
