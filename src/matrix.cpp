#include "matrix.hpp"
#include <iostream>

void Matrix::allocateMemory() {
    m_data = new double*[m_rows];
    for (int i = 0; i < m_rows; ++i) {
        m_data[i] = new double[m_cols];
    }
}

void Matrix::clearMemory() {
    for (int i = 0; i < m_rows; ++i) {
        delete[] m_data[i];
    }
    delete[] m_data;
}

Matrix::Matrix(int n) : m_rows(n), m_cols(n) {
    allocateMemory();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m_data[i][j] = (i == j ? 1.0 : 0.0);
        }
    }
}

Matrix::Matrix(int m, int n, double fillValue) : m_rows(m), m_cols(n) {
    allocateMemory();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            m_data[i][j] = fillValue;
        }
    }
}

Matrix::Matrix(const Matrix& other) : m_rows(other.m_rows), m_cols(other.m_cols) {
    allocateMemory();
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

Matrix::~Matrix() {
    clearMemory();
}

double Matrix::get(int i, int j) const {
    if (i < 0 || i >= m_rows || j < 0 || j >= m_cols) throw std::out_of_range("Index out of bounds");
    return m_data[i][j];
}

void Matrix::set(int i, int j, double value) {
    if (i < 0 || i >= m_rows || j < 0 || j >= m_cols) throw std::out_of_range("Index out of bounds");
    m_data[i][j] = value;
}

int Matrix::getHeight() const { return m_rows; }
int Matrix::getWidth() const { return m_cols; }

void Matrix::negate() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            m_data[i][j] *= -1;
        }
    }
}

void Matrix::addInPlace(const Matrix& other) {
    if (m_rows != other.m_rows || m_cols != other.m_cols) {
        throw std::invalid_argument("Matrices dimensions must match for addition");
    }
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            m_data[i][j] += other.m_data[i][j];
        }
    }
}

Matrix Matrix::multiply(const Matrix& other) {
    if (m_cols != other.m_rows) {
        throw std::invalid_argument("Matrices dimensions incompatible for multiplication");
    }
    
    Matrix result(m_rows, other.m_cols, 0.0);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < other.m_cols; ++j) {
            double sum = 0;
            for (int k = 0; k < m_cols; ++k) {
                sum += m_data[i][k] * other.m_data[k][j];
            }
            result.m_data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::printMatrix()const{
    for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            std::cout << get(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}
