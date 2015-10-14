#include <iostream>
#include <string>
#include "parser.h"
#include "command.h"

using namespace std;

Parser::Parser()
    :command(NULL), _pointer(0)
{

}

Parser::Parser(const std::string &s1)
    :_strCommand(s1), command(NULL), _pointer(0)
{

}

void Parser::Set(const string &s1)
{
    _strCommand = s1;
}

void Parser::Parse()
{
    int wordLength = 0;
    string strCommand(_GetWord());
    
    command = _commandInteractor.Get(strCommand);
    
    while(_pointer < _strCommand.length())
    {
        _GetWord();
    }
    
    _pointer = 0;
}

/** private **/

string Parser::_GetWord()
{
    int wordBegin, wordLength;
    
    //  Skipping spaces
    while(
            ( _strCommand[_pointer] == ' ' || _strCommand[_pointer] == '\t' ) &&
            _pointer < _strCommand.length()
         )//while
    {
        _pointer++;
    }
    
    wordBegin=_pointer;
    //  Read the word composed of ['a'-'z'] || ['A'-'Z'] || ['0'-'9'] || '_'
    if(
        _strCommand[_pointer] >= 'a' && _strCommand[_pointer] <= 'z' ||
        _strCommand[_pointer] >= 'A' && _strCommand[_pointer] <= 'Z' ||
        _strCommand[_pointer] == '_'
      )//if
    {
        while(
                ( _strCommand[_pointer] >= 'a' && _strCommand[_pointer] <= 'z' ||
                  _strCommand[_pointer] >= 'A' && _strCommand[_pointer] <= 'Z' ||
                  _strCommand[_pointer] >= '0' && _strCommand[_pointer] <= '9' ||
                  _strCommand[_pointer] == '_'
                ) &&
                _pointer < _strCommand.length()
             )//while
        {
            _pointer++;
        }
    }
    else if( _strCommand[_pointer] >= '0' && _strCommand[_pointer] <= '9' ||
             _strCommand[_pointer] == '.' )//esle if
    {
        while(
                ( _strCommand[_pointer] >= '0' && _strCommand[_pointer] <= '9' ||
                  _strCommand[_pointer] == '.'
                ) &&
                _pointer < _strCommand.length()
             )//while
        {
            _pointer++;
        }
    }
    //Read one character
    else
    {
        _pointer++;
    }
    
    wordLength=_pointer-wordBegin;
    
    return _strCommand.substr(wordBegin, wordLength);
}
