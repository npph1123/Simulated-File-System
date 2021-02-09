#pragma once
#include "AbstractFile.h"
class PasswordProxy :public AbstractFile {
private:
	AbstractFile* realFile;
	std::string password;
protected:
	std::string passwordPrompt();
public:
	PasswordProxy(AbstractFile* file, std::string password);
	~PasswordProxy();
	std::vector<char> read() ;
	int write(std::vector<char> input);
	int append(std::vector<char> input);
	unsigned getSize();
	std::string getName();
	void accept(AbstractFileVisitor* visitor);
	AbstractFile* clone(std::string newName);
	enum returnPP{ success, cant_write_file, cant_append_file };
};

