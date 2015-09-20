#pragma once

#include "matrix.h"

class ListOfMatrix
{
public:
	Matrix* matrix;
	void SumupMmatrix(int mat1, int mat2); 
	void SubtractMatrix(int mat1, int mat2);
	void TransposeMatrix(int mat);
	void PrintMatrix(int mat);
	ListOfMatrix(const int len, const int width, const int hight);
	~ListOfMatrix();
private:
	const int quantity;
	
};
