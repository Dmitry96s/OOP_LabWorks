#include "list.h"

void ListOfMatrix::sumupMmatrix(int matrix1, int matrix2)
{
	if(list[matrix1].GetHight()==list[matrix2].GetHight() && list[matrix1].GetWidth()==list[matrix2].GetWidth())
		list[0] = list[matrix1] + list[matrix2];
	
}

void ListOfMatrix::subtractMatrix(int matrix1, int matrix2)
{
	if(list[matrix1].GetHight()==list[matrix2].GetHight() && list[matrix1].GetWidth()==list[matrix2].GetWidth())
		list[0] = list[matrix1] - list[matrix2];
}

void ListOfMatrix::transposeMatrix(int matrix)
{
	list[matrix].Transpose();
}

void ListOfMatrix::printMatrix(int matrix)
{
	list[matrix].PrintMatrix();
}

ListOfMatrix::ListOfMatrix(const int len,const int width, const int hight)
:list(new Matrix[len + 1]), quantity(len + 1)
{
	int i;
	for (i = 0; i < quantity; i++)
		list[i].RemakeMatrix(width,hight);
}


ListOfMatrix::~ListOfMatrix()
{
	delete[]list;
}
