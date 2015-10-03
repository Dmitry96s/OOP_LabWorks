#include "commandExecutor.h"
#include "osDepended.h"

#define FILE "input.dat"
// Как сказал один человек: "Дефайн - это плохо"

int main() {
	CommandExecutor commandExecutor(FILE);
	commandExecutor.ExecScript();
	_PAUSE_;
	return 0;
}
