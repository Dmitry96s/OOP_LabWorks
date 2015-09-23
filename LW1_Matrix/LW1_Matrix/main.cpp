#include "commandExecutor.h"
#include "osDepended.h"

#define FILE "input.dat"


int main() {
	CommandExecutor commandExecutor(FILE);
	commandExecutor.ReadCommand();
	commandExecutor.ParseCommand();
	commandExecutor.ReadCommand();
	commandExecutor.ParseCommand();
	commandExecutor.ReadCommand();
	commandExecutor.ParseCommand();

	_PAUSE_;
	return 0;
}
