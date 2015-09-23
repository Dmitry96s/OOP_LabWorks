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

	_PAUSE_;
	return 0;
}
