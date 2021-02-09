#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"

class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem* fileSys, AbstractFileFactory* fileFactory);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
	virtual ~TouchCommand() = default;

private:
	AbstractFileFactory* ff ;
	AbstractFileSystem* fs;
};