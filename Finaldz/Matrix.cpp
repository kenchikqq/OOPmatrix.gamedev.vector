/**
 * @file Matrix.cpp
 * @brief Реализация класса для работы с матрицами
 */

#include "Matrix.h"
#include <iomanip>
#include <cmath>

// Конструкторы и деструктор
Matrix::Matrix() : rows_(0), cols_(0) {}

Matrix::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
    data_.resize(rows_, std::vector<double>(cols_, 0.0));
}

Matrix::Matrix(size_t rows, size_t cols, double value) : rows_(rows), cols_(cols) {
    data_.resize(rows_, std::vector<double>(cols_, value));
}

Matrix::Matrix(const std::vector<std::vector<double>>& data) {
    if (data.empty()) {
        rows_ = cols_ = 0;
        return;
    }
    
    rows_ = data.size();
    cols_ = data[0].size();
    
    // Проверяем, что все строки имеют одинаковую длину
    for (const auto& row : data) {
        if (row.size() != cols_) {
            throw std::invalid_argument("Все строки должны иметь одинаковую длину");
        }
    }
    
    data_ = data;
}

Matrix::Matrix(const Matrix& other) : data_(other.data_), rows_(other.rows_), cols_(other.cols_) {}

Matrix::~Matrix() {}

// Методы доступа
size_t Matrix::getRows() const {
    return rows_;
}

size_t Matrix::getCols() const {
    return cols_;
}

double Matrix::get(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Индекс вне границ матрицы");
    }
    return data_[row][col];
}

void Matrix::set(size_t row, size_t col, double value) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Индекс вне границ матрицы");
    }
    data_[row][col] = value;
}

void Matrix::resize(size_t rows, size_t cols, double value) {
    data_.resize(rows);
    for (auto& row : data_) {
        row.resize(cols, value);
    }
    rows_ = rows;
    cols_ = cols;
}

// Операторы
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        data_ = other.data_;
        rows_ = other.rows_;
        cols_ = other.cols_;
    }
    return *this;
}

std::vector<double>& Matrix::operator[](size_t row) {
    if (row >= rows_) {
        throw std::out_of_range("Индекс строки вне границ");
    }
    return data_[row];
}

const std::vector<double>& Matrix::operator[](size_t row) const {
    if (row >= rows_) {
        throw std::out_of_range("Индекс строки вне границ");
    }
    return data_[row];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Размеры матриц не совпадают для сложения");
    }
    
    Matrix result(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            result.data_[i][j] = data_[i][j] + other.data_[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Размеры матриц не совпадают для вычитания");
    }
    
    Matrix result(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            result.data_[i][j] = data_[i][j] - other.data_[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Несовместимые размеры для умножения матриц");
    }
    
    Matrix result(rows_, other.cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < other.cols_; ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < cols_; ++k) {
                sum += data_[i][k] * other.data_[k][j];
            }
            result.data_[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            result.data_[i][j] = data_[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    if (std::abs(scalar) < 1e-10) {
        throw std::invalid_argument("Деление на ноль");
    }
    return *this * (1.0 / scalar);
}

// Составные операторы присваивания
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

Matrix& Matrix::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

// Операторы сравнения
bool Matrix::operator==(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }
    
    const double epsilon = 1e-10;
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            if (std::abs(data_[i][j] - other.data_[i][j]) > epsilon) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// Математические операции
Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            result.data_[j][i] = data_[i][j];
        }
    }
    return result;
}

double Matrix::determinant() const {
    if (!isSquare()) {
        throw std::invalid_argument("Определитель можно вычислить только для квадратной матрицы");
    }
    
    if (rows_ == 1) {
        return data_[0][0];
    }
    
    if (rows_ == 2) {
        return data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0];
    }
    
    // Для матриц большего размера используем разложение по первой строке
    double det = 0.0;
    for (size_t j = 0; j < cols_; ++j) {
        // Создаем минор
        Matrix minor(rows_ - 1, cols_ - 1);
        for (size_t i = 1; i < rows_; ++i) {
            size_t minor_j = 0;
            for (size_t k = 0; k < cols_; ++k) {
                if (k != j) {
                    minor.data_[i - 1][minor_j] = data_[i][k];
                    minor_j++;
                }
            }
        }
        
        double sign = (j % 2 == 0) ? 1.0 : -1.0;
        det += sign * data_[0][j] * minor.determinant();
    }
    
    return det;
}

Matrix Matrix::inverse() const {
    if (!isSquare()) {
        throw std::invalid_argument("Обратная матрица существует только для квадратных матриц");
    }
    
    double det = determinant();
    if (std::abs(det) < 1e-10) {
        throw std::invalid_argument("Матрица вырожденная (определитель равен нулю)");
    }
    
    // Для простоты реализуем только для матриц 2x2
    if (rows_ == 2) {
        Matrix result(2, 2);
        result.data_[0][0] = data_[1][1] / det;
        result.data_[0][1] = -data_[0][1] / det;
        result.data_[1][0] = -data_[1][0] / det;
        result.data_[1][1] = data_[0][0] / det;
        return result;
    }
    
    throw std::invalid_argument("Обращение матриц размера больше 2x2 не реализовано");
}

Matrix Matrix::power(int power) const {
    if (!isSquare()) {
        throw std::invalid_argument("Возведение в степень возможно только для квадратных матриц");
    }
    
    if (power < 0) {
        throw std::invalid_argument("Отрицательные степени не поддерживаются");
    }
    
    if (power == 0) {
        return Matrix::identity(rows_);
    }
    
    if (power == 1) {
        return *this;
    }
    
    Matrix result = Matrix::identity(rows_);
    Matrix base = *this;
    
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        power /= 2;
    }
    
    return result;
}

bool Matrix::isSquare() const {
    return rows_ == cols_;
}

bool Matrix::isIdentity(double epsilon) const {
    if (!isSquare()) {
        return false;
    }
    
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            double expected = (i == j) ? 1.0 : 0.0;
            if (std::abs(data_[i][j] - expected) > epsilon) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetric(double epsilon) const {
    if (!isSquare()) {
        return false;
    }
    
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            if (std::abs(data_[i][j] - data_[j][i]) > epsilon) {
                return false;
            }
        }
    }
    return true;
}

void Matrix::fillZeros() {
    for (auto& row : data_) {
        std::fill(row.begin(), row.end(), 0.0);
    }
}

void Matrix::fillOnes() {
    for (auto& row : data_) {
        std::fill(row.begin(), row.end(), 1.0);
    }
}

void Matrix::makeIdentity() {
    if (!isSquare()) {
        throw std::invalid_argument("Единичная матрица должна быть квадратной");
    }
    
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            data_[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

// Статические методы
Matrix Matrix::identity(size_t size) {
    Matrix result(size, size);
    result.makeIdentity();
    return result;
}

Matrix Matrix::zeros(size_t rows, size_t cols) {
    return Matrix(rows, cols, 0.0);
}

Matrix Matrix::ones(size_t rows, size_t cols) {
    return Matrix(rows, cols, 1.0);
}

// Дружественные функции
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << std::fixed << std::setprecision(3);
    
    for (size_t i = 0; i < matrix.rows_; ++i) {
        os << "[";
        for (size_t j = 0; j < matrix.cols_; ++j) {
            os << std::setw(8) << matrix.data_[i][j];
            if (j < matrix.cols_ - 1) os << " ";
        }
        os << "]";
        if (i < matrix.rows_ - 1) os << "\n";
    }
    
    return os;
}

Matrix operator*(double scalar, const Matrix& matrix) {
    return matrix * scalar;
} 