#include <iostream>
#include <fstream>
#include "list.h"

#define FILE "input.dat"

int main() {
	Matrix mat1(3, 2), mat2;
	mat1.FillMatrixManually();
	mat2 = mat1;
	mat1 = mat1;
	mat1.PrintMatrix();
	std::cout << std::endl;
	mat2.PrintMatrix();
	//Здесь не будет Русского языка system("Pause");
	return 0;
}
//2 2 2 2 2 2