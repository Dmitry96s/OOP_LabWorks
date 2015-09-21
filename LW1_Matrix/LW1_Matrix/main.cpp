#include <iostream>
#include <fstream>
//#include "list.h"
#include "commandExecutor.h"
#define FILE "input.dat"

#include <string>

int main() {
	CommandExecutor commandExecutor("input.dat");
	commandExecutor.ReadCommand();
	commandExecutor.ParseCommand();
	commandExecutor.ReadCommand();
	commandExecutor.ParseCommand();
	commandExecutor.ReadCommand();
	commandExecutor.ParseCommand();
//	std::string num="15 13";
//	double dnum;
//	dnum=std::stod(num);
//	std::cout << dnum << std::endl;
//	std::string testString;
	
//	testString=commandExecutor._command;
	
//	testString=testString.substr(1);
//	std::cout << testString.length() << std::endl;
	
	//system("Pause");
	return 0;
}
