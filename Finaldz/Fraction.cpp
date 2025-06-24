
#include "Fraction.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

// Приватные методы
void Fraction::simplify() {
    if (denominator_ == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю");
    }
    
    // Обеспечиваем положительность знаменателя
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
    
    // Сокращаем дробь
    long long g = gcd(std::abs(numerator_), std::abs(denominator_));
    numerator_ /= g;
    denominator_ /= g;
}

long long Fraction::gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long Fraction::lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

// Конструкторы и деструктор
Fraction::Fraction() : numerator_(0), denominator_(1) {}

Fraction::Fraction(long long numerator) : numerator_(numerator), denominator_(1) {}

Fraction::Fraction(long long numerator, long long denominator) 
    : numerator_(numerator), denominator_(denominator) {
    simplify();
}

Fraction::Fraction(double value, int precision) {
    if (precision < 0) precision = 6;
    
    long long multiplier = static_cast<long long>(std::pow(10, precision));
    numerator_ = static_cast<long long>(std::round(value * multiplier));
    denominator_ = multiplier;
    simplify();
}

Fraction::Fraction(const Fraction& other) 
    : numerator_(other.numerator_), denominator_(other.denominator_) {}

Fraction::~Fraction() {}

// Методы доступа
long long Fraction::getNumerator() const {
    return numerator_;
}

long long Fraction::getDenominator() const {
    return denominator_;
}

void Fraction::setNumerator(long long numerator) {
    numerator_ = numerator;
    simplify();
}

void Fraction::setDenominator(long long denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю");
    }
    denominator_ = denominator;
    simplify();
}

void Fraction::set(long long numerator, long long denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
    simplify();
}

// Арифметические операторы
Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    long long common_denominator = lcm(denominator_, other.denominator_);
    long long new_numerator = numerator_ * (common_denominator / denominator_) +
                             other.numerator_ * (common_denominator / other.denominator_);
    return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    long long common_denominator = lcm(denominator_, other.denominator_);
    long long new_numerator = numerator_ * (common_denominator / denominator_) -
                             other.numerator_ * (common_denominator / other.denominator_);
    return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator_ == 0) {
        throw std::invalid_argument("Деление на ноль");
    }
    return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
}

Fraction Fraction::operator-() const {
    return Fraction(-numerator_, denominator_);
}

Fraction Fraction::operator+() const {
    return *this;
}

// Составные операторы присваивания
Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

// Операторы сравнения
bool Fraction::operator==(const Fraction& other) const {
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator_ * other.denominator_ < other.numerator_ * denominator_;
}

bool Fraction::operator<=(const Fraction& other) const {
    return *this < other || *this == other;
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

// Математические функции
Fraction Fraction::abs() const {
    return Fraction(std::abs(numerator_), denominator_);
}

Fraction Fraction::reciprocal() const {
    if (numerator_ == 0) {
        throw std::invalid_argument("Нельзя получить обратную дробь от нуля");
    }
    return Fraction(denominator_, numerator_);
}

Fraction Fraction::power(int power) const {
    if (power == 0) {
        return Fraction(1LL);
    }
    
    if (power > 0) {
        long long new_numerator = 1;
        long long new_denominator = 1;
        
        for (int i = 0; i < power; ++i) {
            new_numerator *= numerator_;
            new_denominator *= denominator_;
        }
        
        return Fraction(new_numerator, new_denominator);
    } else {
        // Отрицательная степень
        if (numerator_ == 0) {
            throw std::invalid_argument("Нельзя возвести ноль в отрицательную степень");
        }
        
        return reciprocal().power(-power);
    }
}

double Fraction::toDouble() const {
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

bool Fraction::isInteger() const {
    return denominator_ == 1;
}

bool Fraction::isProper() const {
    return std::abs(numerator_) < std::abs(denominator_);
}

long long Fraction::getIntegerPart() const {
    return numerator_ / denominator_;
}

Fraction Fraction::getFractionalPart() const {
    long long remainder = numerator_ % denominator_;
    return Fraction(remainder, denominator_);
}

// Дружественные функции
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    if (fraction.denominator_ == 1) {
        os << fraction.numerator_;
    } else {
        os << fraction.numerator_ << "/" << fraction.denominator_;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction) {
    std::cout << "Введите числитель: ";
    is >> fraction.numerator_;
    std::cout << "Введите знаменатель: ";
    is >> fraction.denominator_;
    fraction.simplify();
    return is;
}
