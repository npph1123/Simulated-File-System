// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* textFile) {
	cout.width(25); cout << left << textFile->getName();
	cout.width(35); cout << left << "text";
	cout.width(15); cout << left << textFile->getSize();
}
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	cout.width(30); cout << left << imageFile->getName();
	cout.width(30); cout << left << "image";
	cout.width(30); cout << left << imageFile->getSize();
}
