#pragma once

#include "parser.h"

class Interpritator
{
public:
    Interpritator();
    int Run();
protected:
    Parser _parser;
    int _status;
    
    virtual bool _IsExit();
};


class Executor : public Interpritator
{
protected:
    bool _IsExit();
};
