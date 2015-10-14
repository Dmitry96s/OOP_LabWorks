#pragma once

#include <string>
#include "command.h"

class Parser
{
public:
    Command *command;
    
    Parser();
    Parser(const std::string &s1);
    void Set(const std::string &s1);
    void Parse();
private:
    std::string _strCommand;
    CommandInteractor _commandInteractor;
    int _pointer;
    
    std::string _GetWord();
};
