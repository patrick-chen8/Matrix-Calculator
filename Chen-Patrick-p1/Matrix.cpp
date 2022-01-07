#include <iostream>
#include "Matrix.h"

using namespace std;

// constructor (all elements initialized to 0)
Matrix :: Matrix(uint rows, uint cols) {
    this->rows = rows;
    this->cols = cols;
    matrix = new double* [rows];

    for (uint i = 0; i < rows; i++) {
        matrix [i] = new double [cols];
    }
    for (uint m = 0; m < rows; m++) {
        for (uint n = 0; n < cols; n++) {
            matrix [m][n] = 0;
        }
    }
}

// copy constructor
Matrix :: Matrix(const Matrix & m) {
    rows = m.rows;
    cols = m.cols;

    matrix = new double* [rows];
    for (uint i = 0; i < rows; i++) {
        matrix [i] = new double [cols];
    }
    for (uint j = 0; j < rows; j++) {
        for (uint k = 0; k < cols; k++) {
            matrix [j][k] = m.matrix [j][k];
        }
    }
}

// destructor
Matrix :: ~Matrix() {
    for (uint i = 0; i < this->rows; i++) {
		delete[] matrix[i];
	} // for
	delete[] matrix;

}

// add scalar to this matrix
Matrix Matrix :: add(double s) const {
    Matrix m1 = *this;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            m1.matrix [i][j] += s;
        }
    }
    return m1;
}

// add this matrix and another matrix
Matrix Matrix :: add(const Matrix & m) const {
    Matrix m1 = *this;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            m1.matrix [i][j] += m.matrix[i][j];
        }
    }
    return m1;
}

// subtract scalar from this matrix
Matrix Matrix :: subtract(double s) const {
    Matrix m1 = *this;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            m1.matrix [i][j] -= s;
        }
    }
    return m1;
}

// subtract another matrix from this matrix
Matrix Matrix :: subtract(const Matrix & m) const {
    Matrix m1 = *this;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            m1.matrix [i][j] -= m.matrix[i][j];
        }
    }
    return m1;
}

// // multiply this matrix by a scaler
Matrix Matrix :: multiply(double s) const {
    Matrix m1 = *this;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            m1.matrix [i][j] *= s;
        }
    }
    return m1;
}

// multiply this matrix by another matrix
Matrix Matrix :: multiply(const Matrix & m) const {
    Matrix m1(rows, m.cols);
    for (uint i = 0; i < m1.rows; i ++) {
        for (uint j = 0; j < m1.cols; j++) {
            double dotProduct = 0;
            for (uint k = 0; k < cols; k++) {
                dotProduct += matrix [i][k] * m.matrix [k][j];
            }
            m1.matrix [i][j] = dotProduct;
        }
    }
    return m1;
}

// divide this matrix by a scalar
Matrix Matrix :: divide(double s) const {
    Matrix m1 = *this;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            m1.matrix [i][j] /= s;
        }
    }
    return m1;
}

// transpose of this matrix
Matrix Matrix :: t() const {
    Matrix m1(cols, rows);
    for (uint i = 0; i < m1.rows; i++) {
        for (uint j = 0; j < m1.cols; j++) {
            m1.matrix [i][j] = matrix [j][i];
        }
    }
    return m1;
}

// returns the number of rows
const uint Matrix :: numRows() const {
    return this->rows;
}

// returns the number of cols
const uint Matrix :: numCols() const {
    return this->cols;
}

// get/set element at row,col
double & Matrix :: at(uint row, uint col) {
    return matrix [row][col];
}

// get element at row,col (when using a const object)
const double & Matrix :: at (uint row, uint col) const {
    return matrix [row][col];
}
