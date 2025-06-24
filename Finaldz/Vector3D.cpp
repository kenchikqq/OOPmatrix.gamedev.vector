/**
 * @file Vector3D.cpp
 * @brief Реализация класса для работы с трехмерными векторами
 */

#include "Vector3D.h"
#include <stdexcept>
#include <iomanip>

// Конструкторы и деструктор
Vector3D::Vector3D() : x_(0.0), y_(0.0), z_(0.0) {}

Vector3D::Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Vector3D::Vector3D(const Vector3D& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}

Vector3D::~Vector3D() {}

// Методы доступа
double Vector3D::getX() const {
    return x_;
}

double Vector3D::getY() const {
    return y_;
}

double Vector3D::getZ() const {
    return z_;
}

void Vector3D::setX(double x) {
    x_ = x;
}

void Vector3D::setY(double y) {
    y_ = y;
}

void Vector3D::setZ(double z) {
    z_ = z;
}

void Vector3D::set(double x, double y, double z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

// Арифметические операторы
Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
        z_ = other.z_;
    }
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Vector3D Vector3D::operator-() const {
    return Vector3D(-x_, -y_, -z_);
}

Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x_ * scalar, y_ * scalar, z_ * scalar);
}

Vector3D Vector3D::operator/(double scalar) const {
    if (std::abs(scalar) < 1e-10) {
        throw std::invalid_argument("Деление на ноль");
    }
    return Vector3D(x_ / scalar, y_ / scalar, z_ / scalar);
}

// Составные операторы присваивания
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x_ += other.x_;
    y_ += other.y_;
    z_ += other.z_;
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    z_ -= other.z_;
    return *this;
}

Vector3D& Vector3D::operator*=(double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    z_ *= scalar;
    return *this;
}

Vector3D& Vector3D::operator/=(double scalar) {
    if (std::abs(scalar) < 1e-10) {
        throw std::invalid_argument("Деление на ноль");
    }
    x_ /= scalar;
    y_ /= scalar;
    z_ /= scalar;
    return *this;
}

// Операторы сравнения
bool Vector3D::operator==(const Vector3D& other) const {
    const double epsilon = 1e-10;
    return (std::abs(x_ - other.x_) < epsilon) &&
           (std::abs(y_ - other.y_) < epsilon) &&
           (std::abs(z_ - other.z_) < epsilon);
}

bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other);
}

// Векторные операции
double Vector3D::magnitude() const {
    return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

double Vector3D::magnitudeSquared() const {
    return x_ * x_ + y_ * y_ + z_ * z_;
}

Vector3D Vector3D::normalize() const {
    double mag = magnitude();
    if (mag < 1e-10) {
        throw std::runtime_error("Нельзя нормализовать нулевой вектор");
    }
    return Vector3D(x_ / mag, y_ / mag, z_ / mag);
}

void Vector3D::normalizeSelf() {
    double mag = magnitude();
    if (mag < 1e-10) {
        throw std::runtime_error("Нельзя нормализовать нулевой вектор");
    }
    x_ /= mag;
    y_ /= mag;
    z_ /= mag;
}

double Vector3D::dotProduct(const Vector3D& other) const {
    return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
}

Vector3D Vector3D::crossProduct(const Vector3D& other) const {
    return Vector3D(
        y_ * other.z_ - z_ * other.y_,
        z_ * other.x_ - x_ * other.z_,
        x_ * other.y_ - y_ * other.x_
    );
}

double Vector3D::angleBetween(const Vector3D& other) const {
    double mag1 = magnitude();
    double mag2 = other.magnitude();
    
    if (mag1 < 1e-10 || mag2 < 1e-10) {
        throw std::runtime_error("Нельзя вычислить угол с нулевым вектором");
    }
    
    double cosAngle = dotProduct(other) / (mag1 * mag2);
    
    // Ограничиваем значение для избежания ошибок вычисления
    if (cosAngle > 1.0) cosAngle = 1.0;
    if (cosAngle < -1.0) cosAngle = -1.0;
    
    return std::acos(cosAngle);
}

double Vector3D::distanceTo(const Vector3D& other) const {
    return (*this - other).magnitude();
}

Vector3D Vector3D::projectOnto(const Vector3D& other) const {
    double otherMagSquared = other.magnitudeSquared();
    if (otherMagSquared < 1e-10) {
        throw std::runtime_error("Нельзя проецировать на нулевой вектор");
    }
    
    double scalar = dotProduct(other) / otherMagSquared;
    return other * scalar;
}

bool Vector3D::isZero(double epsilon) const {
    return magnitude() < epsilon;
}

bool Vector3D::isPerpendicular(const Vector3D& other, double epsilon) const {
    return std::abs(dotProduct(other)) < epsilon;
}

bool Vector3D::isParallel(const Vector3D& other, double epsilon) const {
    Vector3D cross = crossProduct(other);
    return cross.magnitude() < epsilon;
}

// Дружественные функции
std::ostream& operator<<(std::ostream& os, const Vector3D& vector) {
    os << std::fixed << std::setprecision(3);
    os << "(" << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3D& vector) {
    std::cout << "Введите координату X: ";
    is >> vector.x_;
    std::cout << "Введите координату Y: ";
    is >> vector.y_;
    std::cout << "Введите координату Z: ";
    is >> vector.z_;
    return is;
}

Vector3D operator*(double scalar, const Vector3D& vector) {
    return vector * scalar;
} 