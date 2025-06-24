/**
 * @file Complex.h
 * @brief Класс для работы с комплексными числами
 * @author Ваше имя
 * @date 2024
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

/**
 * @class Complex
 * @brief Класс для представления и операций с комплексными числами
 * 
 * Класс предоставляет полный набор операций для работы с комплексными числами:
 * арифметические операции, вычисление модуля, аргумента и др.
 */
class Complex {
private:
    double real_;  ///< Действительная часть комплексного числа
    double imag_;  ///< Мнимая часть комплексного числа

public:
    /**
     * @brief Конструктор по умолчанию
     * Создает комплексное число 0 + 0i
     */
    Complex();

    /**
     * @brief Конструктор с параметрами
     * @param real Действительная часть
     * @param imag Мнимая часть
     */
    Complex(double real, double imag = 0.0);

    /**
     * @brief Конструктор копирования
     * @param other Копируемый объект
     */
    Complex(const Complex& other);

    /**
     * @brief Деструктор
     */
    ~Complex();

    // Методы доступа
    /**
     * @brief Получить действительную часть
     * @return Действительная часть числа
     */
    double getReal() const;

    /**
     * @brief Получить мнимую часть
     * @return Мнимая часть числа
     */
    double getImag() const;

    /**
     * @brief Установить действительную часть
     * @param real Новое значение действительной части
     */
    void setReal(double real);

    /**
     * @brief Установить мнимую часть
     * @param imag Новое значение мнимой части
     */
    void setImag(double imag);

    // Арифметические операторы
    /**
     * @brief Оператор присваивания
     * @param other Присваиваемый объект
     * @return Ссылка на текущий объект
     */
    Complex& operator=(const Complex& other);

    /**
     * @brief Оператор сложения
     * @param other Слагаемое
     * @return Результат сложения
     */
    Complex operator+(const Complex& other) const;

    /**
     * @brief Оператор вычитания
     * @param other Вычитаемое
     * @return Результат вычитания
     */
    Complex operator-(const Complex& other) const;

    /**
     * @brief Оператор умножения
     * @param other Множитель
     * @return Результат умножения
     */
    Complex operator*(const Complex& other) const;

    /**
     * @brief Оператор деления
     * @param other Делитель
     * @return Результат деления
     * @throw std::invalid_argument если делитель равен нулю
     */
    Complex operator/(const Complex& other) const;

    // Составные операторы присваивания
    /**
     * @brief Оператор +=
     * @param other Слагаемое
     * @return Ссылка на текущий объект
     */
    Complex& operator+=(const Complex& other);

    /**
     * @brief Оператор -=
     * @param other Вычитаемое
     * @return Ссылка на текущий объект
     */
    Complex& operator-=(const Complex& other);

    /**
     * @brief Оператор *=
     * @param other Множитель
     * @return Ссылка на текущий объект
     */
    Complex& operator*=(const Complex& other);

    /**
     * @brief Оператор /=
     * @param other Делитель
     * @return Ссылка на текущий объект
     */
    Complex& operator/=(const Complex& other);

    // Операторы сравнения
    /**
     * @brief Оператор равенства
     * @param other Сравниваемый объект
     * @return true если числа равны
     */
    bool operator==(const Complex& other) const;

    /**
     * @brief Оператор неравенства
     * @param other Сравниваемый объект
     * @return true если числа не равны
     */
    bool operator!=(const Complex& other) const;

    // Математические функции
    /**
     * @brief Вычислить модуль комплексного числа
     * @return Модуль числа
     */
    double magnitude() const;

    /**
     * @brief Вычислить аргумент комплексного числа
     * @return Аргумент в радианах
     */
    double argument() const;

    /**
     * @brief Получить комплексно-сопряженное число
     * @return Сопряженное число
     */
    Complex conjugate() const;

    /**
     * @brief Возвести в степень
     * @param power Показатель степени
     * @return Результат возведения в степень
     */
    Complex power(double power) const;

    /**
     * @brief Вычислить квадратный корень
     * @return Главное значение квадратного корня
     */
    Complex sqrt() const;

    // Дружественные функции для ввода/вывода
    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param complex Комплексное число для вывода
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param complex Комплексное число для ввода
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Complex& complex);
};

#endif // COMPLEX_H 