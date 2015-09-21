//This is Matrix!!!
#include <iostream>
#include <fstream>
#include "list.h"
//Test for merging RubyScorp was successful!
#define FILE "input.dat"

int main() {
	Matrix mat1(3, 2), mat2;
	mat1.FillManually();
	mat2 = mat1;
	mat1 = mat1;
	mat1.Print();
	std::cout << std::endl;
	mat2.Print();
	//system("Pause");
	return 0;
}//Test for merging RubyScorp
//2 2 2 2 2 2
