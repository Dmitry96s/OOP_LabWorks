#pragma once

#include "matrix.h"

class ListOfMatrix
{
public:
	const int quantity;
	Matrix* list;
	void SumupMmatrix(int matrix1, int matrix2); 
	void SubtractMatrix(int matrix1, int matrix2);
	void TransposeMatrix(int matrix);
	void PrintMatrix(int matrix);
	ListOfMatrix(const int len, const int width, const int hight);
	~ListOfMatrix();
};
