

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/**
 * @class Fraction
 * @brief Класс для представления и операций с обыкновенными дробями
 * 
 * Класс предоставляет полный набор операций для работы с дробями:
 * арифметические операции, сравнение, приведение к общему знаменателю и др.
 * Дроби всегда хранятся в сокращенном виде.
 */
class Fraction {
private:
    long long numerator_;    ///< Числитель
    long long denominator_;  ///< Знаменатель

    /**
     * @brief Приведение дроби к каноническому виду
     * Сокращает дробь и обеспечивает положительность знаменателя
     */
    void simplify();

    /**
     * @brief Наибольший общий делитель
     * @param a Первое число
     * @param b Второе число
     * @return НОД чисел a и b
     */
    static long long gcd(long long a, long long b);

    /**
     * @brief Наименьшее общее кратное
     * @param a Первое число
     * @param b Второе число
     * @return НОК чисел a и b
     */
    static long long lcm(long long a, long long b);

public:
    /**
     * @brief Конструктор по умолчанию
     * Создает дробь 0/1
     */
    Fraction();

    /**
     * @brief Конструктор с числителем
     * @param numerator Числитель (знаменатель = 1)
     */
    Fraction(long long numerator);

    /**
     * @brief Конструктор с числителем и знаменателем
     * @param numerator Числитель
     * @param denominator Знаменатель
     * @throw std::invalid_argument если знаменатель равен нулю
     */
    Fraction(long long numerator, long long denominator);

    /**
     * @brief Конструктор из вещественного числа
     * @param value Вещественное число
     * @param precision Точность (количество знаков после запятой)
     */
    explicit Fraction(double value, int precision = 6);

    /**
     * @brief Конструктор копирования
     * @param other Копируемый объект
     */
    Fraction(const Fraction& other);

    /**
     * @brief Деструктор
     */
    ~Fraction();

    // Методы доступа
    /**
     * @brief Получить числитель
     * @return Числитель
     */
    long long getNumerator() const;

    /**
     * @brief Получить знаменатель
     * @return Знаменатель
     */
    long long getDenominator() const;

    /**
     * @brief Установить числитель
     * @param numerator Новый числитель
     */
    void setNumerator(long long numerator);

    /**
     * @brief Установить знаменатель
     * @param denominator Новый знаменатель
     * @throw std::invalid_argument если знаменатель равен нулю
     */
    void setDenominator(long long denominator);

    /**
     * @brief Установить дробь
     * @param numerator Числитель
     * @param denominator Знаменатель
     * @throw std::invalid_argument если знаменатель равен нулю
     */
    void set(long long numerator, long long denominator);

    // Арифметические операторы
    /**
     * @brief Оператор присваивания
     * @param other Присваиваемый объект
     * @return Ссылка на текущий объект
     */
    Fraction& operator=(const Fraction& other);

    /**
     * @brief Оператор сложения
     * @param other Слагаемое
     * @return Результат сложения
     */
    Fraction operator+(const Fraction& other) const;

    /**
     * @brief Оператор вычитания
     * @param other Вычитаемое
     * @return Результат вычитания
     */
    Fraction operator-(const Fraction& other) const;

    /**
     * @brief Оператор умножения
     * @param other Множитель
     * @return Результат умножения
     */
    Fraction operator*(const Fraction& other) const;

    /**
     * @brief Оператор деления
     * @param other Делитель
     * @return Результат деления
     * @throw std::invalid_argument если делитель равен нулю
     */
    Fraction operator/(const Fraction& other) const;

    /**
     * @brief Оператор унарного минуса
     * @return Противоположная дробь
     */
    Fraction operator-() const;

    /**
     * @brief Оператор унарного плюса
     * @return Копия дроби
     */
    Fraction operator+() const;

    // Составные операторы присваивания
    /**
     * @brief Оператор +=
     * @param other Слагаемое
     * @return Ссылка на текущий объект
     */
    Fraction& operator+=(const Fraction& other);

    /**
     * @brief Оператор -=
     * @param other Вычитаемое
     * @return Ссылка на текущий объект
     */
    Fraction& operator-=(const Fraction& other);

    /**
     * @brief Оператор *=
     * @param other Множитель
     * @return Ссылка на текущий объект
     */
    Fraction& operator*=(const Fraction& other);

    /**
     * @brief Оператор /=
     * @param other Делитель
     * @return Ссылка на текущий объект
     */
    Fraction& operator/=(const Fraction& other);

    // Операторы сравнения
    /**
     * @brief Оператор равенства
     * @param other Сравниваемый объект
     * @return true если дроби равны
     */
    bool operator==(const Fraction& other) const;

    /**
     * @brief Оператор неравенства
     * @param other Сравниваемый объект
     * @return true если дроби не равны
     */
    bool operator!=(const Fraction& other) const;

    /**
     * @brief Оператор "меньше"
     * @param other Сравниваемый объект
     * @return true если текущая дробь меньше
     */
    bool operator<(const Fraction& other) const;

    /**
     * @brief Оператор "меньше или равно"
     * @param other Сравниваемый объект
     * @return true если текущая дробь меньше или равна
     */
    bool operator<=(const Fraction& other) const;

    /**
     * @brief Оператор "больше"
     * @param other Сравниваемый объект
     * @return true если текущая дробь больше
     */
    bool operator>(const Fraction& other) const;

    /**
     * @brief Оператор "больше или равно"
     * @param other Сравниваемый объект
     * @return true если текущая дробь больше или равна
     */
    bool operator>=(const Fraction& other) const;

    // Математические функции
    /**
     * @brief Получить абсолютное значение
     * @return Абсолютное значение дроби
     */
    Fraction abs() const;

    /**
     * @brief Получить обратную дробь
     * @return Обратная дробь
     * @throw std::invalid_argument если дробь равна нулю
     */
    Fraction reciprocal() const;

    /**
     * @brief Возвести в степень
     * @param power Показатель степени
     * @return Результат возведения в степень
     */
    Fraction power(int power) const;

    /**
     * @brief Преобразовать в десятичную дробь
     * @return Значение в виде double
     */
    double toDouble() const;

    /**
     * @brief Проверить, является ли дробь целым числом
     * @return true если дробь целая
     */
    bool isInteger() const;

    /**
     * @brief Проверить, является ли дробь правильной (|числитель| < |знаменатель|)
     * @return true если дробь правильная
     */
    bool isProper() const;

    /**
     * @brief Получить целую часть
     * @return Целая часть
     */
    long long getIntegerPart() const;

    /**
     * @brief Получить дробную часть
     * @return Дробная часть (правильная дробь)
     */
    Fraction getFractionalPart() const;

    // Дружественные функции
    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param fraction Дробь для вывода
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param fraction Дробь для ввода
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
};

#endif // FRACTION_H 