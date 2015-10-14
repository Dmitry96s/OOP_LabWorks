#include <iostream>
#include <string>
#include "interpritator.h"
#include "command.h"

using namespace std;

/**
 * class Interpritator
 */

/** public class Interpritator **/

Interpritator::Interpritator()
    :_status(0)
{

}

int Interpritator::Run()                                                       //  ???
{
    string tempString;
    Command *command;
    
    for(_status = -1; _IsExit() ; _status = command->Exec())
    {
        cout << "$ ";
        getline(cin, tempString);
        _parser.Set(tempString);
        _parser.Parse();
        command = _parser.command;
    }
    return _status;
}

/** protected class Interpritator **/

bool Interpritator::_IsExit()
{
    return _status == -1 || _status == 1;
}

/**
 * class Executor
 */

/** public class Executor **/

bool Executor::_IsExit()
{
    return _status == -1;
}
