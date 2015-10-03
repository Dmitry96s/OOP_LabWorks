#include <iostream>
#include <cstring>
#include "matrix.h"

using namespace std;

void Matrix::Recreate(const int width, const int hight) {
	DeleteMatrix();
	_matrixWidth = width;
	_matrixHight = hight;
	NewMatrix();
}

Matrix::Matrix() {
	_matrixWidth = 1;
	_matrixHight = 1;
	NewMatrix();
}

Matrix::Matrix(const Matrix &matrix) {
	int i, j;
	_matrixWidth = matrix._matrixWidth;
	_matrixHight = matrix._matrixHight;
	NewMatrix();
	for (i = 0; i < _matrixHight; i++)
		for (j = 0; j < _matrixWidth; j++)
			_table[i][j] = matrix._table[i][j];
}

Matrix::Matrix(const int width, const int hight)
	:_matrixWidth(width), _matrixHight(hight)
{
	NewMatrix();
}

Matrix Matrix::operator+(const Matrix &matrix) {
	int i, j;
	Matrix tempMatrix(*this);
	for (i = 0; i < _matrixHight; i++)
		for (j = 0; j < _matrixWidth; j++)
			tempMatrix._table[i][j] += matrix._table[i][j];
	return tempMatrix;
}

Matrix Matrix::operator-(const Matrix &matrix) {
	int i, j;
	Matrix tempMatrix(*this);
	for (i = 0; i < _matrixHight; i++)
		for (j = 0; j < _matrixWidth; j++)
			tempMatrix._table[i][j] -= matrix._table[i][j];
	return tempMatrix;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
	if (this == &matrix)
		return *this;
	if (_matrixWidth != matrix._matrixWidth || _matrixHight != matrix._matrixHight) {
		DeleteMatrix();
		_matrixWidth = matrix._matrixWidth;
		_matrixHight = matrix._matrixHight;
		_table = new double*[_matrixHight];
		for (int i = 0; i < _matrixHight; i++)
			_table[i] = new double[_matrixWidth];
	}
//	for (int i = 0; i < _matrixHight; i++)
//		for (int j = 0; j < _matrixWidth; j++)
//			_table[i][j] = matrix._table[i][j];
	for (int i = 0; i < _matrixHight; i++)
		memcpy(_table[i],matrix._table[i],_matrixWidth*sizeof(double));
	return *this;
}

double *Matrix::operator[](int y) {
	return _table[y];
}

int Matrix::GetWidth() {
	return _matrixWidth;
}

int Matrix::GetHight() {
	return _matrixHight;
}
/*
void Matrix::FillManually() {
	int i, j;
	for (i = 0; i < _matrixHight; i++)
		for (j = 0; j < _matrixWidth; j++)
			cin >> _table[i][j];
}
*/
void Matrix::Transpose() {
	int tempInt, i, j;
	Matrix tempMatrix(*this);
	DeleteMatrix();
	tempInt = _matrixWidth;
	_matrixWidth = _matrixHight;
	_matrixHight = tempInt;
	NewMatrix();
	for (i = 0; i < _matrixHight; i++)
		for (j = 0; j < _matrixWidth; j++)
			_table[i][j] = tempMatrix._table[j][i];
}

void Matrix::Print() {
	int i, j;
	for (i = 0; i < _matrixHight; i++) {
		for (j = 0; j < _matrixWidth; j++)
			cout << _table[i][j] << '\t';
		cout << endl;
	}
}

Matrix::~Matrix() {
	DeleteMatrix();
}

/**private**/

void Matrix::NewMatrix() {
	int i;
	_table = new double*[_matrixHight];
	for (i = 0; i < _matrixHight; i++) {
		_table[i] = new double[_matrixWidth];
		memset(_table[i], 0, sizeof(double)*_matrixWidth);
	}
}

void Matrix::DeleteMatrix() {
	int i;
	for (i = 0; i < _matrixHight; i++)
		delete[] _table[i];
	delete[] _table;
}
