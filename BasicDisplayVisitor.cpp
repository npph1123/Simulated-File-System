// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>
using namespace std;

 void BasicDisplayVisitor::visit_TextFile(TextFile* textFile) {
	vector <char> contents = textFile->read();
	if (contents.size()) {
		for (vector<char>::const_iterator i = contents.begin(); i != contents.end(); ++i)
			cout << *i;
	}
}
 void BasicDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	vector <char> contents = imageFile->read();
 
	if (contents.size()) {
		int size = 1, result = 1; //finding the side of the nxn image.
		while (result < contents.size()) //assume valid size. File corrupt and wipeout if not
		{
			size++;
			result = size * size;
		}

		for (int i = size - 1; i >= 0; i--) {
			for (int j = 0; j < size; j++) {
				int index = i * size + j;
				cout << contents[index];
			}
			cout << endl;
		}

	}
}

