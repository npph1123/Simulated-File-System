#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
class BasicDisplayVisitor: public AbstractFileVisitor {
public:
	  void visit_TextFile(TextFile* textFile) ;
	  void visit_ImageFile(ImageFile* imageFile) ;
};