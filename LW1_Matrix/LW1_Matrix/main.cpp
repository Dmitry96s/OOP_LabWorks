#include <iostream>
#include <fstream>
#include <string>
//#include "list.h"
#include "commandExecutor.h"
#include"osDepended.h"
#define FILE "input.dat"


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
	
//	testString=testString.substr(1);
//	std::cout << testString.length() << std::endl;
	
	PAUSE;
	return 0;
}
