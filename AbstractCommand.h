#pragma once
#include <string>
#include <iostream>
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class AbstractCommand {
public:
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
	enum returnvalues {success, file_fail_open, command_fail, file_fail_create, 
		fail_to_add, file_not_exist, not_valid_command,
	};
};

