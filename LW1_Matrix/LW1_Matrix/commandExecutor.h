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

class CommandExecutor{
public:
	CommandExecutor();
	CommandExecutor(const int maxVarCount);
	CommandExecutor(const char *fileName);
	CommandExecutor(const char *fileName, const int maxVarCount);
	void OpenFile(const char *fileName);
	void ReadCommand();
	void ParseCommand();
	void ExecCommand();
	void ExecScript();
	Variable *SetVariable(const std::string &name);
	int WhereIsVar(const std::string &name);
	~CommandExecutor();
private:
	std::ifstream _file;
	std::string _command;
	Command _parsedCommand;
	unsigned int _varCount;
	const unsigned int _maxVarCount;
	Variable *_var;
};
