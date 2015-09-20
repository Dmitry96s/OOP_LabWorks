#pragma once

#include "matrix.h"

class ListOfMatrix
{
public:
	const int quantity;
	Matrix* list;
	void sumupMmatrix(int matrix1, int matrix2); 
	void subtractMatrix(int matrix1, int matrix2);
	void transposeMatrix(int matrix);
	void printMatrix(int matrix);
	ListOfMatrix(const int len, const int width, const int hight);
	~ListOfMatrix();
};
