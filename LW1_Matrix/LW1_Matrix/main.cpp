#include "commandExecutor.h"
#include "osDepended.h"

#define FILE "input.dat"


int main() {
	CommandExecutor commandExecutor(FILE);
	commandExecutor.ExecScript();
	_PAUSE_;
	return 0;
}
