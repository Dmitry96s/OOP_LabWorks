#include <fstream>
#include <string>
#include "variable.h"

class CommandExecutor
{
public:
	void ParseCommand();
	void ReadCommand();
	int IsVarExist(std::string name);
	CommandExecutor(const char *fileName);
	std::string _command;
private:
	std::ifstream _file;
	Variable _var[50];
	unsigned int _varCount;
};
