#include <fstream>
#include <string>
#include "variable.h"

class CommandExecutor
{
public:
	void ParseCommand();
	void ReadCommand();
	CommandExecutor(const char *fileName);
private:
	std::ifstream _file;
	std::string _command;
	Variable _var[50];
	unsigned int _varCount;
};//sdf