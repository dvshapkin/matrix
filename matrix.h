/*
 * matrix.h
 *
 *  Created on: 21 Dec 2020
 *      Author: dvshapkin
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>
#include <cstdlib>

using namespace std;

class Matrix {
public:
    Matrix(size_t cols, size_t rows);
    size_t cols() const;
    size_t rows() const;
    const double* operator[](const size_t offset) const;
    double* operator[](const size_t offset);
    bool operator==(const Matrix& other) const;
private:
    size_t _cols;
    size_t _rows;
    double *data;
};


Matrix::Matrix(size_t cols, size_t rows) :
        _cols { cols }, _rows { rows } {
    data = new double[cols * rows] { 0 };
}

size_t Matrix::cols() const {
    return _cols;
}

size_t Matrix::rows() const {
    return _rows;
}

const double* Matrix::operator[](const size_t offset) const {
    return data + offset * _cols;
}

double* Matrix::operator[](const size_t offset) {
    return data + offset * _cols;
}

bool Matrix::operator==(const Matrix& other) const {
    if (_cols != other._cols || _rows != other._rows) {
        return false;
    }
    if (data == nullptr && other.data == nullptr) {
        return true;
    }
    if (data != nullptr && other.data != nullptr) {
        for (size_t offset=0; offset < _cols * _rows; ++offset) {
            if (data[offset] != other.data[offset]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

#endif /* MATRIX_H_ */
