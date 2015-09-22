#include <iostream>
#include <fstream>
#include "commandExecutor.h"

void CommandExecutor::ParseCommand()
{
	std::string tempCommand(_command), leftPart;
	unsigned int strlen(tempCommand.length()), hight, width;
	int i, j, varIndex, beginNum, endNum;
	for(i=0; tempCommand[i] != ' ' && tempCommand[i] != '='; i++){
		
	}
	leftPart = tempCommand.substr(0, i);
	tempCommand = tempCommand.substr(i+1);
	strlen = tempCommand.length();
	if(_command[i]=='='){
		if(IsVarExist(leftPart)){
			varIndex=IsVarExist(leftPart)-1;
		}
		else{
			varIndex=_varCount;
			_var[varIndex].name=leftPart;
			_varCount++;
		}
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
		_var[varIndex].value.Recreate(width,hight);
		for(i=0; i<strlen; i++){
			beginNum=i;
			endNum=-1;
			while(tempCommand[i]>='0' && tempCommand[i]<='9' || tempCommand[i]=='.'){
				endNum=i;
				i++;
			}
			if(endNum!=-1){
				cout << _var[varIndex].value[i/width][i%width] << std::endl;
				i--;
			}
		}
	}
}

void CommandExecutor::ReadCommand()
{
	getline(_file, _command);
}

int CommandExecutor::IsVarExist(std::string name){
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
