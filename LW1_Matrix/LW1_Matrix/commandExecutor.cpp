#include <fstream>
#include <iostream>
#include <sstream>
#include "commandExecutor.h"
#include "osDepended.h"

using namespace std;

void CommandExecutor::ReadCommand()
{
	getline(_file, _command);
}

void CommandExecutor::ParseCommand()
{
	if(_command[0]=='/' && _command[1]=='/'){
		_parsedCommand.action="//";
		return;
	}
	string tempCommand(_command);
	int i, j, strlen(tempCommand.length());
	for(i=0; tempCommand[i] != ' ' && tempCommand[i] != '=' && i<strlen; i++)
	{
	
	}
	if(tempCommand[i]=='='){
		_parsedCommand.result=SetVariable(tempCommand.substr(0,i));
		tempCommand=tempCommand.substr(i+1);
		strlen=tempCommand.length();
		if(tempCommand[0]=='['){
			int width, hight;
			stringstream commandStream;
			hight=-1;
			for(i=0; i<strlen; i++){
				if(tempCommand[i]=='['){
					hight++;
					if(hight==1){
						width=1;
						for(i; tempCommand[i]!=']'; i++){
							if(tempCommand[i]==' ')
								width++;
						}
					}
				}
			}
			_parsedCommand.result->value.Recreate(width,hight);
			for(i=0; i<strlen; i++)
				if(tempCommand[i]=='[' || tempCommand[i]==']')
					tempCommand[i]=' ';
			commandStream << tempCommand;
			for(i=0; i<hight; i++)
				for(j=0; j<width; j++)
					commandStream >> _parsedCommand.result->value[i][j];
		}
		else{
			for(i=0; tempCommand[i]!='+' && tempCommand[i]!='-' && i<strlen; i++){
			
			}
			if(tempCommand[i]=='+'){
				_parsedCommand.action='+';
				_parsedCommand.operand[0]=SetVariable(tempCommand.substr(0,i));
				_parsedCommand.operand[1]=SetVariable(tempCommand.substr(i+1));
			}
			else if(tempCommand[i]=='-'){
				_parsedCommand.action='-';
				_parsedCommand.operand[0]=SetVariable(tempCommand.substr(0,i));
				_parsedCommand.operand[1]=SetVariable(tempCommand.substr(i+1));
			}
			else if(i==strlen){
				_parsedCommand.action='=';
				_parsedCommand.operand[0]=SetVariable(tempCommand);
			}
		}
	}
	else{
		_parsedCommand.action=tempCommand.substr(0,i);
		_parsedCommand.operand[0]=SetVariable(tempCommand.substr(i+1));
	}
}

void CommandExecutor::ExecCommand(){
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

void CommandExecutor::ExecScript(){
	while(!_file.eof()){
		ReadCommand();
		if(_command.length()==0)
			continue;
		ParseCommand();
		ExecCommand();
	}
}

Variable *CommandExecutor::SetVariable(string name){
	int varIndex;
	if(IsVarExist(name)){
			varIndex=IsVarExist(name)-1;
		}
		else{
			varIndex=_varCount;
			_var[varIndex].name=name;
			_varCount++;
		}
	return &_var[varIndex];
}

int CommandExecutor::IsVarExist(string name){
	int i, isExist(0);
	for(i=0; i<_varCount; i++){
		if(_var[i].name == name){
			isExist=i+1;
			break;
		}
	}
	return isExist;
}

CommandExecutor::CommandExecutor(const char *fileName)
:_file(fileName), _varCount(0)
{

}
