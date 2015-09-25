#include <fstream>
#include <string>
#include "matrix.h"

struct Variable{
	std::string name;
	Matrix value;
};

struct Command{
	Variable *result;
	Variable *operand[2];
	std::string action;
};

class CommandExecutor
{
public:
	void ReadCommand();
	void ParseCommand();
	void ExecCommand();
	void ExecScript();
	Variable *SetVariable(std::string name);
	int IsVarExist(std::string name);
	CommandExecutor(const char *fileName);
private:
	std::ifstream _file;
	std::string _command;
	Command _parsedCommand;
	unsigned int _varCount;
	Variable _var[50];
};
