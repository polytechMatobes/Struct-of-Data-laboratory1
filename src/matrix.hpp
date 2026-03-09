#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdexcept>

class Matrix {
private:
    int m_rows;
    int m_cols;
    double** m_data;

    void allocateMemory();
    void clearMemory();

public:
    Matrix(int n);
    Matrix(int m, int n, double fillValue = 0);
    Matrix(const Matrix& other);

    ~Matrix();

    double get(int i, int j) const;
    void set(int i, int j, double value);
    int getHeight() const;
    int getWidth() const;

    void negate();
    void addInPlace(const Matrix& other);
    Matrix multiply(const Matrix& other);
    void printMatrix()const;
};

#endif
