/**
 * @file Vector3D.h
 * @brief Класс для работы с трехмерными векторами
 * @author Ваше имя
 * @date 2024
 */

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>

/**
 * @class Vector3D
 * @brief Класс для представления и операций с трехмерными векторами
 * 
 * Класс предоставляет полный набор операций для работы с 3D векторами:
 * арифметические операции, скалярное и векторное произведения, нормализация и др.
 */
class Vector3D {
private:
    double x_;  ///< Координата X
    double y_;  ///< Координата Y  
    double z_;  ///< Координата Z

public:
    /**
     * @brief Конструктор по умолчанию
     * Создает нулевой вектор (0, 0, 0)
     */
    Vector3D();

    /**
     * @brief Конструктор с параметрами
     * @param x Координата X
     * @param y Координата Y
     * @param z Координата Z
     */
    Vector3D(double x, double y, double z);

    /**
     * @brief Конструктор копирования
     * @param other Копируемый объект
     */
    Vector3D(const Vector3D& other);

    /**
     * @brief Деструктор
     */
    ~Vector3D();

    // Методы доступа
    /**
     * @brief Получить координату X
     * @return Координата X
     */
    double getX() const;

    /**
     * @brief Получить координату Y
     * @return Координата Y
     */
    double getY() const;

    /**
     * @brief Получить координату Z
     * @return Координата Z
     */
    double getZ() const;

    /**
     * @brief Установить координату X
     * @param x Новое значение координаты X
     */
    void setX(double x);

    /**
     * @brief Установить координату Y
     * @param y Новое значение координаты Y
     */
    void setY(double y);

    /**
     * @brief Установить координату Z
     * @param z Новое значение координаты Z
     */
    void setZ(double z);

    /**
     * @brief Установить все координаты
     * @param x Координата X
     * @param y Координата Y
     * @param z Координата Z
     */
    void set(double x, double y, double z);

    // Арифметические операторы
    /**
     * @brief Оператор присваивания
     * @param other Присваиваемый объект
     * @return Ссылка на текущий объект
     */
    Vector3D& operator=(const Vector3D& other);

    /**
     * @brief Оператор сложения векторов
     * @param other Слагаемый вектор
     * @return Результат сложения
     */
    Vector3D operator+(const Vector3D& other) const;

    /**
     * @brief Оператор вычитания векторов
     * @param other Вычитаемый вектор
     * @return Результат вычитания
     */
    Vector3D operator-(const Vector3D& other) const;

    /**
     * @brief Оператор унарного минуса
     * @return Противоположный вектор
     */
    Vector3D operator-() const;

    /**
     * @brief Оператор умножения на скаляр
     * @param scalar Скаляр
     * @return Результат умножения
     */
    Vector3D operator*(double scalar) const;

    /**
     * @brief Оператор деления на скаляр
     * @param scalar Скаляр
     * @return Результат деления
     * @throw std::invalid_argument если скаляр равен нулю
     */
    Vector3D operator/(double scalar) const;

    // Составные операторы присваивания
    /**
     * @brief Оператор +=
     * @param other Слагаемый вектор
     * @return Ссылка на текущий объект
     */
    Vector3D& operator+=(const Vector3D& other);

    /**
     * @brief Оператор -=
     * @param other Вычитаемый вектор
     * @return Ссылка на текущий объект
     */
    Vector3D& operator-=(const Vector3D& other);

    /**
     * @brief Оператор *= (умножение на скаляр)
     * @param scalar Скаляр
     * @return Ссылка на текущий объект
     */
    Vector3D& operator*=(double scalar);

    /**
     * @brief Оператор /= (деление на скаляр)
     * @param scalar Скаляр
     * @return Ссылка на текущий объект
     */
    Vector3D& operator/=(double scalar);

    // Операторы сравнения
    /**
     * @brief Оператор равенства
     * @param other Сравниваемый объект
     * @return true если векторы равны
     */
    bool operator==(const Vector3D& other) const;

    /**
     * @brief Оператор неравенства
     * @param other Сравниваемый объект
     * @return true если векторы не равны
     */
    bool operator!=(const Vector3D& other) const;

    // Векторные операции
    /**
     * @brief Вычислить длину вектора
     * @return Длина вектора
     */
    double magnitude() const;

    /**
     * @brief Вычислить квадрат длины вектора (для оптимизации)
     * @return Квадрат длины вектора
     */
    double magnitudeSquared() const;

    /**
     * @brief Нормализовать вектор (сделать единичным)
     * @return Нормализованный вектор
     * @throw std::runtime_error если вектор нулевой
     */
    Vector3D normalize() const;

    /**
     * @brief Нормализовать текущий вектор
     * @throw std::runtime_error если вектор нулевой
     */
    void normalizeSelf();

    /**
     * @brief Скалярное произведение
     * @param other Другой вектор
     * @return Скалярное произведение
     */
    double dotProduct(const Vector3D& other) const;

    /**
     * @brief Векторное произведение
     * @param other Другой вектор
     * @return Результат векторного произведения
     */
    Vector3D crossProduct(const Vector3D& other) const;

    /**
     * @brief Угол между векторами в радианах
     * @param other Другой вектор
     * @return Угол в радианах
     * @throw std::runtime_error если один из векторов нулевой
     */
    double angleBetween(const Vector3D& other) const;

    /**
     * @brief Расстояние до другого вектора
     * @param other Другой вектор
     * @return Расстояние
     */
    double distanceTo(const Vector3D& other) const;

    /**
     * @brief Проекция этого вектора на другой вектор
     * @param other Вектор, на который проецируем
     * @return Проекция
     * @throw std::runtime_error если вектор other нулевой
     */
    Vector3D projectOnto(const Vector3D& other) const;

    /**
     * @brief Проверить, является ли вектор нулевым
     * @param epsilon Точность сравнения
     * @return true если вектор нулевой
     */
    bool isZero(double epsilon = 1e-10) const;

    /**
     * @brief Проверить, перпендикулярны ли векторы
     * @param other Другой вектор
     * @param epsilon Точность сравнения
     * @return true если векторы перпендикулярны
     */
    bool isPerpendicular(const Vector3D& other, double epsilon = 1e-10) const;

    /**
     * @brief Проверить, параллельны ли векторы
     * @param other Другой вектор
     * @param epsilon Точность сравнения
     * @return true если векторы параллельны
     */
    bool isParallel(const Vector3D& other, double epsilon = 1e-10) const;

    // Дружественные функции
    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param vector Вектор для вывода
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vector);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param vector Вектор для ввода
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Vector3D& vector);

    /**
     * @brief Умножение скаляра на вектор (слева)
     * @param scalar Скаляр
     * @param vector Вектор
     * @return Результат умножения
     */
    friend Vector3D operator*(double scalar, const Vector3D& vector);
};

#endif // VECTOR3D_H 