#include "list.h"

/*  class
*  ListOfMatrix
*/

/**public**/

void ListOfMatrix::SumupMmatrix(int mat1, int mat2)
{
	if (matrix[mat1].GetHight() == matrix[mat2].GetHight() && matrix[mat1].GetWidth() == matrix[mat2].GetWidth())
		matrix[0] = matrix[mat1] + matrix[mat2];
}

void ListOfMatrix::SubtractMatrix(int mat1, int mat2)
{
	if (matrix[mat1].GetHight() == matrix[mat2].GetHight() && matrix[mat1].GetWidth() == matrix[mat2].GetWidth())
		matrix[0] = matrix[mat1] - matrix[mat2];
}

void ListOfMatrix::TransposeMatrix(int mat)
{
	matrix[mat].Transpose();
}

void ListOfMatrix::PrintMatrix(int mat)
{
	matrix[mat].PrintMatrix();
}

ListOfMatrix::ListOfMatrix(const int len, const int width, const int hight)
	:matrix(new Matrix[len + 1]), quantity(len + 1)
{
	int i;
	for (i = 0; i < quantity; i++)
		matrix[i].RemakeMatrix(width, hight);
}

ListOfMatrix::~ListOfMatrix()
{
	delete[]matrix;
}
