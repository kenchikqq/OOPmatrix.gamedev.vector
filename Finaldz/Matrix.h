/**
 * @file Matrix.h
 * @brief Класс для работы с матрицами
 * @author Ваше имя
 * @date 2024
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @class Matrix
 * @brief Класс для представления и операций с матрицами
 * 
 * Класс предоставляет полный набор операций для работы с матрицами:
 * арифметические операции, вычисление определителя, транспонирование и др.
 */
class Matrix {
private:
    std::vector<std::vector<double>> data_;  ///< Данные матрицы
    size_t rows_;    ///< Количество строк
    size_t cols_;    ///< Количество столбцов

public:
    /**
     * @brief Конструктор по умолчанию
     * Создает пустую матрицу 0x0
     */
    Matrix();

    /**
     * @brief Конструктор с размерами
     * @param rows Количество строк
     * @param cols Количество столбцов
     */
    Matrix(size_t rows, size_t cols);

    /**
     * @brief Конструктор с размерами и начальным значением
     * @param rows Количество строк
     * @param cols Количество столбцов
     * @param value Начальное значение для всех элементов
     */
    Matrix(size_t rows, size_t cols, double value);

    /**
     * @brief Конструктор из вектора векторов
     * @param data Двумерный вектор с данными
     * @throw std::invalid_argument если строки имеют разную длину
     */
    Matrix(const std::vector<std::vector<double>>& data);

    /**
     * @brief Конструктор копирования
     * @param other Копируемый объект
     */
    Matrix(const Matrix& other);

    /**
     * @brief Деструктор
     */
    ~Matrix();

    // Методы доступа
    /**
     * @brief Получить количество строк
     * @return Количество строк
     */
    size_t getRows() const;

    /**
     * @brief Получить количество столбцов
     * @return Количество столбцов
     */
    size_t getCols() const;

    /**
     * @brief Получить элемент матрицы (только чтение)
     * @param row Номер строки (0-based)
     * @param col Номер столбца (0-based)
     * @return Значение элемента
     * @throw std::out_of_range если индексы вне границ
     */
    double get(size_t row, size_t col) const;

    /**
     * @brief Установить элемент матрицы
     * @param row Номер строки (0-based)
     * @param col Номер столбца (0-based)
     * @param value Новое значение
     * @throw std::out_of_range если индексы вне границ
     */
    void set(size_t row, size_t col, double value);

    /**
     * @brief Изменить размер матрицы
     * @param rows Новое количество строк
     * @param cols Новое количество столбцов
     * @param value Значение для новых элементов
     */
    void resize(size_t rows, size_t cols, double value = 0.0);

    // Операторы
    /**
     * @brief Оператор присваивания
     * @param other Присваиваемый объект
     * @return Ссылка на текущий объект
     */
    Matrix& operator=(const Matrix& other);

    /**
     * @brief Оператор доступа к элементу (изменяемый)
     * @param row Номер строки
     * @return Ссылка на строку
     * @throw std::out_of_range если индекс вне границ
     */
    std::vector<double>& operator[](size_t row);

    /**
     * @brief Оператор доступа к элементу (только чтение)
     * @param row Номер строки
     * @return Константная ссылка на строку
     * @throw std::out_of_range если индекс вне границ
     */
    const std::vector<double>& operator[](size_t row) const;

    /**
     * @brief Оператор сложения матриц
     * @param other Слагаемая матрица
     * @return Результат сложения
     * @throw std::invalid_argument если размеры не совпадают
     */
    Matrix operator+(const Matrix& other) const;

    /**
     * @brief Оператор вычитания матриц
     * @param other Вычитаемая матрица
     * @return Результат вычитания
     * @throw std::invalid_argument если размеры не совпадают
     */
    Matrix operator-(const Matrix& other) const;

    /**
     * @brief Оператор умножения матриц
     * @param other Множитель
     * @return Результат умножения
     * @throw std::invalid_argument если размеры несовместимы для умножения
     */
    Matrix operator*(const Matrix& other) const;

    /**
     * @brief Оператор умножения на скаляр
     * @param scalar Скаляр
     * @return Результат умножения
     */
    Matrix operator*(double scalar) const;

    /**
     * @brief Оператор деления на скаляр
     * @param scalar Скаляр
     * @return Результат деления
     * @throw std::invalid_argument если скаляр равен нулю
     */
    Matrix operator/(double scalar) const;

    // Составные операторы присваивания
    /**
     * @brief Оператор +=
     * @param other Слагаемая матрица
     * @return Ссылка на текущий объект
     */
    Matrix& operator+=(const Matrix& other);

    /**
     * @brief Оператор -=
     * @param other Вычитаемая матрица
     * @return Ссылка на текущий объект
     */
    Matrix& operator-=(const Matrix& other);

    /**
     * @brief Оператор *= (умножение на скаляр)
     * @param scalar Скаляр
     * @return Ссылка на текущий объект
     */
    Matrix& operator*=(double scalar);

    /**
     * @brief Оператор /= (деление на скаляр)
     * @param scalar Скаляр
     * @return Ссылка на текущий объект
     */
    Matrix& operator/=(double scalar);

    // Операторы сравнения
    /**
     * @brief Оператор равенства
     * @param other Сравниваемый объект
     * @return true если матрицы равны
     */
    bool operator==(const Matrix& other) const;

    /**
     * @brief Оператор неравенства
     * @param other Сравниваемый объект
     * @return true если матрицы не равны
     */
    bool operator!=(const Matrix& other) const;

    // Математические операции
    /**
     * @brief Транспонировать матрицу
     * @return Транспонированная матрица
     */
    Matrix transpose() const;

    /**
     * @brief Вычислить определитель (только для квадратных матриц)
     * @return Определитель матрицы
     * @throw std::invalid_argument если матрица не квадратная
     */
    double determinant() const;

    /**
     * @brief Обратная матрица
     * @return Обратная матрица
     * @throw std::invalid_argument если матрица не квадратная или вырожденная
     */
    Matrix inverse() const;

    /**
     * @brief Возвести матрицу в степень
     * @param power Показатель степени
     * @return Результат возведения в степень
     * @throw std::invalid_argument если матрица не квадратная или степень отрицательная
     */
    Matrix power(int power) const;

    /**
     * @brief Проверить, является ли матрица квадратной
     * @return true если матрица квадратная
     */
    bool isSquare() const;

    /**
     * @brief Проверить, является ли матрица единичной
     * @param epsilon Точность сравнения
     * @return true если матрица единичная
     */
    bool isIdentity(double epsilon = 1e-10) const;

    /**
     * @brief Проверить, является ли матрица симметричной
     * @param epsilon Точность сравнения
     * @return true если матрица симметричная
     */
    bool isSymmetric(double epsilon = 1e-10) const;

    /**
     * @brief Заполнить матрицу нулями
     */
    void fillZeros();

    /**
     * @brief Заполнить матрицу единицами
     */
    void fillOnes();

    /**
     * @brief Сделать единичную матрицу (только для квадратных)
     * @throw std::invalid_argument если матрица не квадратная
     */
    void makeIdentity();

    // Статические методы
    /**
     * @brief Создать единичную матрицу
     * @param size Размер матрицы
     * @return Единичная матрица
     */
    static Matrix identity(size_t size);

    /**
     * @brief Создать нулевую матрицу
     * @param rows Количество строк
     * @param cols Количество столбцов
     * @return Нулевая матрица
     */
    static Matrix zeros(size_t rows, size_t cols);

    /**
     * @brief Создать матрицу из единиц
     * @param rows Количество строк
     * @param cols Количество столбцов
     * @return Матрица из единиц
     */
    static Matrix ones(size_t rows, size_t cols);

    // Дружественные функции
    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param matrix Матрица для вывода
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    /**
     * @brief Умножение скаляра на матрицу (слева)
     * @param scalar Скаляр
     * @param matrix Матрица
     * @return Результат умножения
     */
    friend Matrix operator*(double scalar, const Matrix& matrix);
};

#endif // MATRIX_H 