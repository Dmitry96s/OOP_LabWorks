#pragma once

class Matrix {
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
	void Recreate(const int width, const int hight);
//	void FillManually();
	void Transpose();
	void Print();
	~Matrix();
private:
	int _matrixWidth;
	int _matrixHight;
	double **_table;
	void NewMatrix();
	void DeleteMatrix();
};
