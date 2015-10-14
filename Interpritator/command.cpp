#include <iostream>                                                             //--//
#include "command.h"

using namespace std;

/**
 *  class Exit : public Command
 */

/** public Exit **/

int Exit::Exec()
{
    return 0;
}


/**
 *  class Unknown : public Command
 */

/** public Unknown **/

int Unknown::Exec()
{
    cout << "Unknown command" << endl;                                          //--//
    return 1;
}

/**
 *  class Empty : public Command
 */

/** public Empty **/

int Empty::Exec()
{
    return -1;
}

/**
 *  class CommandInteractor
 */

/** public CommandInteractor **/

CommandInteractor::CommandInteractor()
{
    cMap["exit"] = &_exit;
//    cMap["unknown"] = &_unknown;
    cMap[""] = &_empty;
}

Command *CommandInteractor::Get(const string &str1)
{
    map<string, Command*>::iterator it;
    if(
        cMap.end() !=
        ( it = cMap.find( str1 ) )
      )
    {
        return it->second;
    }
    else
    {
        return &_unknown;
    }
}
