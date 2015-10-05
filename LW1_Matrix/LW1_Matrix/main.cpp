//#include <iostream>
#include "commandExecutor.h"
#include "osDepended.h"

int main(int argc, char* argv[]) {
    const char *FILE_NAME("input.dat");
    CommandExecutor commandExecutor;
    if(argc > 1)
        commandExecutor.OpenFile(argv[1]);
    else
        commandExecutor.OpenFile(FILE_NAME);
    commandExecutor.ExecScript();
    _PAUSE_;
    return 0;
}
