#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include "commandExecutor.h"
#include "osDepended.h"

using namespace std;

/**
 * public
 */

CommandExecutor::CommandExecutor()
:_varCount(0)
{
}

CommandExecutor::CommandExecutor(const char *fileName)
	: _file(fileName), _varCount(0)
{
}

void CommandExecutor::ExecScript(){
    if(_file)
        while(!_file.eof()){
            _ReadCommand();
            if(_command.length()==0)
                continue;
            _ParseCommand();
            _ExecCommand();
        }
}

void CommandExecutor::OpenFile(const char *fileName){
    if(!_file)
		_file.close();
	_file.open(fileName);
}

CommandExecutor::~CommandExecutor(){

}

/**
 * private
 */

int CommandExecutor::_WhereIsVar(const string &name) const{
    int varIndex(-1);
    for(int i=0; i<_varCount; i++){
        if(_var[i].name == name){
            varIndex=i;
            break;
        }
    }
    return varIndex;
}

Variable *CommandExecutor::_SetVariable(const string &name){
    int varIndex(_WhereIsVar(name));
    if(varIndex==-1){
        _AddVar();
        varIndex=_varCount-1;
        _var[varIndex].name=name;
    }
    return &_var[varIndex];
}

void CommandExecutor::_AddVar(){
    Variable *tempVar;
    tempVar=new Variable[_varCount+1];
    if(_varCount>0){
        for(int i=0; i<_varCount; i++){
            tempVar[i]=_var[i];
        }
        delete[] _var;
    }
    _varCount++;
    _var=tempVar;
}

void CommandExecutor::_ExecCommand() const{
    const string &action=_parsedCommand.action;
    Matrix
        &result=_parsedCommand.result->value,
        &operand1=_parsedCommand.operand[0]->value,
        &operand2=_parsedCommand.operand[1]->value;
    if(action=="="){
        result=operand1;
    }else if(action=="+"){
        result=operand1+operand2;
    }else if(action=="-"){
        result=operand1-operand2;
    }else if(action=="print"){
        _COLOR_;
        cout << _parsedCommand.operand[0]->name << endl;
        _DEF_COLOR_;
        operand1.Print();
    }else if(action=="transpose"){
        operand1.Transpose();
    }
}

void CommandExecutor::_ParseCommand(){
    if(_command[0]=='/' && _command[1]=='/'){
        _parsedCommand.action="//";
		return;
	}
	string tempCommand(_command);
    int i, j;
    for(i=0; tempCommand[i] != ' ' && tempCommand[i] != '=' && i<tempCommand.length(); i++){
        
	}
    if(tempCommand[i]=='='){
        _parsedCommand.result=_SetVariable(tempCommand.substr(0,i));
        tempCommand=tempCommand.substr(i+1);
        if(tempCommand[0]=='['){
			int width, hight;
			stringstream commandStream;
			hight = -1;
			for (i = 0; i < tempCommand.length(); i++) {
				if (tempCommand[i] == '[') {
					hight++;
					if (hight == 1) {
						width = 1;
						for (i; tempCommand[i] != ']'; i++) {
							if (tempCommand[i] == ' ')
								width++;
						}
					}
				}
			}
            _parsedCommand.result->value.Recreate(width,hight);
            for(i=0; i<tempCommand.length(); i++){
                if(tempCommand[i]=='[' || tempCommand[i]==']')
                    tempCommand[i]=' ';
            }
			commandStream << tempCommand;
            for(i=0; i<hight; i++){
                for(j=0; j<width; j++){
					commandStream >> _parsedCommand.result->value[i][j];
		}
            }
        }
        else{
            for(i=0; tempCommand[i]!='+' && tempCommand[i]!='-' && i<tempCommand.length(); i++){
                
			}
            if(tempCommand[i]=='+'){
                _parsedCommand.action='+';
                _parsedCommand.operand[0]=_SetVariable(tempCommand.substr(0,i));
                _parsedCommand.operand[1]=_SetVariable(tempCommand.substr(i+1));
			}
            else if(tempCommand[i]=='-'){
                _parsedCommand.action='-';
                _parsedCommand.operand[0]=_SetVariable(tempCommand.substr(0,i));
                _parsedCommand.operand[1]=_SetVariable(tempCommand.substr(i+1));
			}
            else if(i==tempCommand.length()){
                _parsedCommand.action='=';
                _parsedCommand.operand[0]=_SetVariable(tempCommand);
			}
		}
	}
    else{
        _parsedCommand.action=tempCommand.substr(0,i);
        _parsedCommand.operand[0]=_SetVariable(tempCommand.substr(i+1));
	}
}

void CommandExecutor::_ReadCommand(){
    getline(_file, _command);
}
