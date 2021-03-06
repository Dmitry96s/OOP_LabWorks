#include <iostream>
#include <cstring>
#include "matrix.h"

using namespace std;

/**
 * public
 */

Matrix::Matrix()
    :_matrixWidth(1), _matrixHeight(1)
{
    _NewMatrix();
}

Matrix::Matrix(const Matrix &matrix)
    :_matrixWidth(matrix._matrixWidth), _matrixHeight(matrix._matrixHeight)
{
    _NewMatrix();
    for (int i = 0; i < _matrixHeight; i++){
        for (int j = 0; j < _matrixWidth; j++){
            _table[i][j] = matrix._table[i][j];
        }
    }
}

Matrix::Matrix(const int height, const int width)
    :_matrixWidth(width), _matrixHeight(height)
{
    _NewMatrix();
}

double *Matrix::operator[](int y) {
    return _table[y];
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix)
        return *this;
    if (_matrixWidth != matrix._matrixWidth || _matrixHeight != matrix._matrixHeight) {
        _DeleteMatrix();
        _matrixWidth = matrix._matrixWidth;
        _matrixHeight = matrix._matrixHeight;
        _table = new double*[_matrixHeight];
        for (int i = 0; i < _matrixHeight; i++){
            _table[i] = new double[_matrixWidth];
        }
    }
    for (int i = 0; i < _matrixHeight; i++){
        memcpy(_table[i],matrix._table[i],_matrixWidth*sizeof(double));
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &matrix) const{
    Matrix tempMatrix(*this);
    for (int i = 0; i < _matrixHeight; i++)
        for (int j = 0; j < _matrixWidth; j++)
            tempMatrix._table[i][j] -= matrix._table[i][j];
    return tempMatrix;
}

Matrix Matrix::operator+(const Matrix &matrix) const{
    Matrix tempMatrix(*this);
    for (int i = 0; i < _matrixHeight; i++){
        for (int j = 0; j < _matrixWidth; j++){
            tempMatrix._table[i][j] += matrix._table[i][j];
        }
    }
    return tempMatrix;
}

int Matrix::GetWidth() const{
    return _matrixWidth;
}

int Matrix::GetHeight() const{
    return _matrixHeight;
}

void Matrix::Print() const{
    for (int i = 0; i < _matrixHeight; i++) {
        for (int j = 0; j < _matrixWidth; j++){
            cout << _table[i][j] << '\t';
        }
        cout << endl;
    }
}

void Matrix::Recreate(const int height, const int width) {
    _DeleteMatrix();
    _matrixHeight = height;
    _matrixWidth = width;
    _NewMatrix();
}

void Matrix::Transpose() {
    Matrix tempMatrix(*this);
    _DeleteMatrix();
    swap(_matrixWidth, _matrixHeight);
    _NewMatrix();
    for (int i = 0; i < _matrixHeight; i++){
        for (int j = 0; j < _matrixWidth; j++){
            _table[i][j] = tempMatrix._table[j][i];
        }
    }
}

Matrix::~Matrix() {
    _DeleteMatrix();
}

/**
 * public
 */

void Matrix::_DeleteMatrix() {
    for (int i = 0; i < _matrixHeight; i++){
        delete[] _table[i];
    }
    delete[] _table;
}

void Matrix::_NewMatrix() {
    _table = new double*[_matrixHeight];
    for (int i = 0; i < _matrixHeight; i++) {
        _table[i] = new double[_matrixWidth];
        memset(_table[i], 0, sizeof(double)*_matrixWidth);
    }
}
