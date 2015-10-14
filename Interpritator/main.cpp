#if 0
    g++ main.cpp interpritator.cpp parser.cpp command.cpp -std=c++11 -o interpritator && ./interpritator
    exit
#endif

#include <iostream>
#include <string>
#include "interpritator.h"

using namespace std;

int main()
{
    Interpritator mainInterpritator;
    Executor mainExecutor;
    
    mainInterpritator.Run();
    mainExecutor.Run();
    return 0;
}
