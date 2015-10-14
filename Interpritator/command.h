#pragma once

#include <map>



class Command
{
public:
    virtual int Exec()=0;
protected:
    
};


class Exit : public Command
{
public:
    int Exec();
};


class Unknown : public Command
{
public:
    int Exec();
};


class Empty : public Command
{
public:
    int Exec();
};


class CommandInteractor
{
public:
    CommandInteractor();
    Command *Get(const std::string &str1);
private:
    Exit _exit;
    Empty _empty;
    Unknown _unknown;
    
    std::map< std::string, Command* > cMap;
};
