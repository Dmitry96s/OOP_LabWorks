#pragma once

class Matrix {
public:
	Matrix();
	Matrix(const Matrix &matrix);
	Matrix(const int hight, const int width);
	double *operator[](int y);
    Matrix &operator=(const Matrix &matrix);
    Matrix operator-(const Matrix &matrix) const;
    Matrix operator+(const Matrix &matrix) const;
    int GetHight() const;
    int GetWidth() const;
    void Print() const;
	void Recreate(const int hight, const int width);
	void Transpose();
	~Matrix();
private:
	int _matrixWidth;
	int _matrixHight;
	double **_table;

    void _DeleteMatrix();
    void _NewMatrix();
};
