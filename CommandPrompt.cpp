#include "CommandPrompt.h"
#include <iostream>
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt() :
	fs(nullptr), ff(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* filesystem) {
	fs = filesystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* filefactory) {
	ff = filefactory;
}

int CommandPrompt::addCommand(string name, AbstractCommand* cmd) {
	auto insert = commands.insert({ name, cmd });
	if (insert.second) {
		return success;
	}
	else {
		return fail_add_command;
	}
}

void CommandPrompt::listCommands() {
	for (auto it = commands.begin(); it!= commands.end(); it++) {
		cout << it->first << endl;
	}
}

string CommandPrompt::prompt() {
	cout << "Enter a valid command, q to quit" << endl;
	cout << "Enter help for a list of command" << endl;
	cout << "Enter help <command> for more information about that command" << endl;
	cout << " $ ";
	string input;
	getline(cin, input);
	return input;
}

int CommandPrompt::run() {
	while (1) {
		string input = prompt();
		if (input == "q") {
			return user_quit;
		}
		else if (input == "help") {
			listCommands();
		}
		else if (input.find_first_of(' ') == string::npos) {//if no space, single command
			auto it = commands.find(input);
			if (it == commands.end()) {
				cout << "command not exist." << endl;
			}
			else {
				int result = it->second->execute("");
				if (result != success) {
					cout << "command failed to execute." << endl;
				}
			}
		}
		else { //command with additional parameters
			istringstream iss(input);
			string long_command;
			iss >> long_command;
			if (long_command == "help") {//if first word is help
				string helpCommand; 
				iss >> helpCommand;
				auto it = commands.find(helpCommand);
				if (it != commands.end()) {
					it->second->displayInfo();
				}
				else {
					cout << "command not exist." << endl;
				}
			}
			else {
				auto it = commands.find(long_command);
				if (it != commands.end()) {
					string parameter = input.substr(input.find_first_of(' ') + 1, string::npos); //pass everything after the first word
					int result = it->second->execute(parameter);
					if (result != success) {
						cout << "command failed to execute" << endl;
					}
				}
				else {
					cout << "command not exist." << endl;
				}

			}
		}
	}
}