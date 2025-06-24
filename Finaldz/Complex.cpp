/**
 * @file Complex.cpp
 * @brief Реализация класса для работы с комплексными числами
 */

#include "Complex.h"
#include <stdexcept>
#include <iomanip>

// Конструкторы и деструктор
Complex::Complex() : real_(0.0), imag_(0.0) {}

Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

Complex::Complex(const Complex& other) : real_(other.real_), imag_(other.imag_) {}

Complex::~Complex() {}

// Методы доступа
double Complex::getReal() const {
    return real_;
}

double Complex::getImag() const {
    return imag_;
}

void Complex::setReal(double real) {
    real_ = real;
}

void Complex::setImag(double imag) {
    imag_ = imag;
}

// Арифметические операторы
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real_ = other.real_;
        imag_ = other.imag_;
    }
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real_ + other.real_, imag_ + other.imag_);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real_ - other.real_, imag_ - other.imag_);
}

Complex Complex::operator*(const Complex& other) const {
    double real_part = real_ * other.real_ - imag_ * other.imag_;
    double imag_part = real_ * other.imag_ + imag_ * other.real_;
    return Complex(real_part, imag_part);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
    if (std::abs(denominator) < 1e-10) {
        throw std::invalid_argument("Деление на ноль");
    }
    
    double real_part = (real_ * other.real_ + imag_ * other.imag_) / denominator;
    double imag_part = (imag_ * other.real_ - real_ * other.imag_) / denominator;
    return Complex(real_part, imag_part);
}

// Составные операторы присваивания
Complex& Complex::operator+=(const Complex& other) {
    real_ += other.real_;
    imag_ += other.imag_;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real_ -= other.real_;
    imag_ -= other.imag_;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double temp_real = real_ * other.real_ - imag_ * other.imag_;
    imag_ = real_ * other.imag_ + imag_ * other.real_;
    real_ = temp_real;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

// Операторы сравнения
bool Complex::operator==(const Complex& other) const {
    const double epsilon = 1e-10;
    return (std::abs(real_ - other.real_) < epsilon) && 
           (std::abs(imag_ - other.imag_) < epsilon);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Математические функции
double Complex::magnitude() const {
    return std::sqrt(real_ * real_ + imag_ * imag_);
}

double Complex::argument() const {
    return std::atan2(imag_, real_);
}

Complex Complex::conjugate() const {
    return Complex(real_, -imag_);
}

Complex Complex::power(double power) const {
    if (real_ == 0.0 && imag_ == 0.0) {
        return Complex(0.0, 0.0);
    }
    
    double r = magnitude();
    double theta = argument();
    
    double new_r = std::pow(r, power);
    double new_theta = power * theta;
    
    return Complex(new_r * std::cos(new_theta), new_r * std::sin(new_theta));
}

Complex Complex::sqrt() const {
    return power(0.5);
}

// Дружественные функции для ввода/вывода
std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << std::fixed << std::setprecision(3);
    
    if (complex.imag_ >= 0) {
        os << complex.real_ << " + " << complex.imag_ << "i";
    } else {
        os << complex.real_ << " - " << std::abs(complex.imag_) << "i";
    }
    
    return os;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
    std::cout << "Введите действительную часть: ";
    is >> complex.real_;
    std::cout << "Введите мнимую часть: ";
    is >> complex.imag_;
    return is;
} 