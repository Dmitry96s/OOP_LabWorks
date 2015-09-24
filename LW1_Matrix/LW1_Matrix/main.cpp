#include "commandExecutor.h"
#include "osDepended.h"

#define FILE "input.dat"


int main() {
	CommandExecutor commandExecutor(FILE);
	for(int i=0; i<6; i++){
		commandExecutor.ReadCommand();
		commandExecutor.ParseCommand();
		commandExecutor.ExecCommand();
	}
	_PAUSE_;
	return 0;
}
