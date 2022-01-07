#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    // creating a matrix and printing it out
    Matrix m(2, 3);
    cout << "Testing:\n";
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            cout << m.at(i,j) << " ";
        }
        cout << endl;
    }

    // printing and testing scalar addition
    cout << "\nTesting addition of scalar(5): \n";
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            cout << m.at(i,j) << " ";
        }
        cout << endl;
    }
    Matrix mAddScalar = m.add(5);
    for (uint i = 0; i < mAddScalar.numRows(); i++) {
        for (uint j = 0; j < mAddScalar.numCols(); j++) {
            cout << mAddScalar.at(i,j) << " ";
        }
        cout << endl;
    }

    // printing and testing addition of matrices
    cout << "\nTesting addition of matrices: \n";
    Matrix mCopy = mAddScalar;
    for (uint i = 0; i < mCopy.numRows(); i++) {
        for (uint j = 0; j < mCopy.numCols(); j++) {
            cout << mCopy.at(i,j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mAddScalar.at(i,j) << " ";
        }
        cout << endl;
    }
    cout << "Sum:\n";
    Matrix sum = mCopy.add(mAddScalar);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sum.at(i,j) << " ";
        }
        cout << endl;
    }

    // printing and testing subtraction of scalars
    cout << "\nTesting subtraction of scalar(2): \n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sum.at(i,j) << " ";
        }
        cout << endl;
    }
    Matrix mSubtractScalar = sum.subtract(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mSubtractScalar.at(i,j) << " ";
        }
        cout << endl;
    }

    // printing and testing subtraction of matrices
    cout << "\nTesting subtraction of matrices: \n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mSubtractScalar.at(i,j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mCopy.at(i,j) << " ";
        }
        cout << endl;
    }
    cout << "Difference:\n";
    Matrix diff = mSubtractScalar.subtract(mCopy);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << diff.at(i,j) << " ";
        }
        cout << endl;
    }

    // testing and printing multiplication of matrices
    Matrix m1(3, 4);
    Matrix m1AddScalar = m1.add(3);
    cout << "\nTesting multiplication of matrices: \n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mAddScalar.at(i,j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << m1AddScalar.at(i,j) << " ";
        }
        cout << endl;
    }
    cout << "Result: \n";
    Matrix result = mAddScalar.multiply(m1AddScalar);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << result.at(i,j) << " ";
        }
        cout << endl;
    }

    // testing and printing transposes
    cout << "\nTesting transpose: \n";
    Matrix transpose = result.t();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << transpose.at(i,j) << " ";
        }
        cout << endl;
    }

    // testing and printing multiplicaiton by scalar
    cout << "\nTesting multiplication by scalar(2):\n";
    Matrix mMultiplicationScalar = result.multiply(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << result.at(i,j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mMultiplicationScalar.at(i,j) << " ";
        }
        cout << endl;
    }

    // testing and printing division by scalar
    cout << "\nTesting division by scalar(3):\n";
    Matrix mDivisionScalar = mMultiplicationScalar.divide(3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mMultiplicationScalar.at(i,j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mDivisionScalar.at(i,j) << " ";
        }
        cout << endl;
    }

    // testing numRows and numCols functions
    cout << "\nReturning rows and cols of the matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mDivisionScalar.at(i,j) << " ";
        }
        cout << endl;
    }
    cout << "Rows: " << mDivisionScalar.numRows() << endl;
    cout << "Cols: " << mDivisionScalar.numCols() << endl;


    cout << "\nTesting Example:\n";
    Matrix a(2, 2);
    a.at(0, 0) = 1; // [ 1, 2 ]
    a.at(0, 1) = 2; // [ 1, 3 ]
    a.at(1, 0) = 1;
    a.at(1, 1) = 3;

    Matrix b(2, 1);
    b.at(0, 0) = 3; // [ 3 ]
    b.at(1, 0) = 2; // [ 2 ]

    Matrix c = a.multiply(b);
    cout << "[ " << c.at(0, 0) << " ]" << endl  // [ 7 ]
         << "[ " << c.at(1, 0) << " ]" << endl; // [ 9 ]

}
