//#include <iostream>
#include <fstream>
#include "commandExecutor.h"

void CommandExecutor::ParseCommand()
{
	
}

void CommandExecutor::ReadCommand()
{
	getline(_file, _command);
}

CommandExecutor::CommandExecutor(const char *fileName)
:_file(fileName), _varCount(0)
{

}
