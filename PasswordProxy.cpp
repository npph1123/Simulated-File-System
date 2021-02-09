#include"PasswordProxy.h"
#include <iostream>
using namespace std;

 
PasswordProxy::PasswordProxy(AbstractFile* file, std::string password)
	:realFile(file), password(password) {};

PasswordProxy::~PasswordProxy() {
	delete realFile;
}

string PasswordProxy::passwordPrompt() {
	string input;
	cout << "Enter your password: ";
	cin >> input;
	return input;
};
vector<char> PasswordProxy::read() {
	string user_input = passwordPrompt();
	if (user_input == password) {
		return realFile->read();
	}
	return vector<char>();
 }

int PasswordProxy::write(std::vector<char> input) {
	string user_input = passwordPrompt();
	if (user_input == password) {
		return realFile->write(input);
	}
	return cant_write_file;
}

int PasswordProxy::append(vector<char> input) {
	string user_input = passwordPrompt();
	if (user_input == password) {
		return realFile->append(input);
	}
	return cant_append_file;
}

unsigned PasswordProxy::getSize() {
	return realFile->getSize();
}
string PasswordProxy::getName() {
	return realFile->getName();
 }

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	string user_input = passwordPrompt();
	if (user_input == password) {
		realFile->accept(visitor);
	}

}

AbstractFile* PasswordProxy::clone(string newName) {
	AbstractFile* file = realFile->clone(newName);
	return new PasswordProxy(file, password); //same password as old
}
