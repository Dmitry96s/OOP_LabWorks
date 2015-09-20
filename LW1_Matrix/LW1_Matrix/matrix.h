#pragma once

class Matrix{
	int _matrixWidth;
	int _matrixHight;
	double **_table;
	void NewMatrix();
	void DeleteMatrix();
public:
	Matrix();
	Matrix(const Matrix &matrix);
	Matrix(const int width, const int hight);
	Matrix operator+(const Matrix &matrix);
	Matrix operator-(const Matrix &matrix);
	Matrix &operator=(const Matrix &matrix);
	double *operator[](int y);
	int GetWidth();
	int GetHight();
	void RemakeMatrix(const int width, const int hight );
	void FillMatrixManually();
	void Transpose();
	void PrintMatrix();
	~Matrix();
};
