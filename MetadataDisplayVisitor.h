#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor:public AbstractFileVisitor {
	void visit_TextFile(TextFile* textFile) ;
	void visit_ImageFile(ImageFile* imageFile) ;
};