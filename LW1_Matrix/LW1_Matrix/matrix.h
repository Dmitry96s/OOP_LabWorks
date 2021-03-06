#pragma once

class Matrix {
public:
	Matrix();
	Matrix(const Matrix &matrix);
	Matrix(const int height, const int width);
	double *operator[](int y);
    Matrix &operator=(const Matrix &matrix);
    Matrix operator-(const Matrix &matrix) const;
    Matrix operator+(const Matrix &matrix) const;
    int GetHeight() const;
    int GetWidth() const;
    void Print() const;
	void Recreate(const int height, const int width);
	void Transpose();
	~Matrix();
//private:
	int _matrixWidth;
	int _matrixHeight;
	double **_table;

    void _DeleteMatrix();
    void _NewMatrix();
};
