
#include "MathLibrary.h"
#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

/**
 * @brief Демонстрация работы с классом Complex
 */
void demonstrateComplex() {
    cout << "\n=== ДЕМОНСТРАЦИЯ КЛАССА COMPLEX ===" << endl;
    
    // Создание комплексных чисел
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    // Арифметические операции
    cout << "\nАрифметические операции:" << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "c1 / c2 = " << (c1 / c2) << endl;
    
    // Математические функции
    cout << "\nМатематические функции:" << endl;
    cout << "Модуль c1: " << c1.magnitude() << endl;
    cout << "Аргумент c1: " << c1.argument() << " радиан" << endl;
    cout << "Сопряженное c1: " << c1.conjugate() << endl;
    cout << "c1^2: " << c1.power(2) << endl;
    cout << "sqrt(c1): " << c1.sqrt() << endl;
}

/**
 * @brief Демонстрация работы с классом Vector3D
 */
void demonstrateVector3D() {
    cout << "\n=== ДЕМОНСТРАЦИЯ КЛАССА VECTOR3D ===" << endl;
    
    // Создание векторов
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    
    // Арифметические операции
    cout << "\nАрифметические операции:" << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2.0 = " << (v1 * 2.0) << endl;
    cout << "v1 / 2.0 = " << (v1 / 2.0) << endl;
    
    // Векторные операции
    cout << "\nВекторные операции:" << endl;
    cout << "Длина v1: " << v1.magnitude() << endl;
    cout << "Скалярное произведение v1 * v2: " << v1.dotProduct(v2) << endl;
    cout << "Векторное произведение v1 x v2: " << v1.crossProduct(v2) << endl;
    cout << "Угол между v1 и v2: " << v1.angleBetween(v2) << " радиан" << endl;
    cout << "Расстояние от v1 до v2: " << v1.distanceTo(v2) << endl;
    
    // Нормализация
    Vector3D normalized = v1.normalize();
    cout << "Нормализованный v1: " << normalized << endl;
    cout << "Длина нормализованного вектора: " << normalized.magnitude() << endl;
}

/**
 * @brief Демонстрация работы с классом Matrix
 */
void demonstrateMatrix() {
    cout << "\n=== ДЕМОНСТРАЦИЯ КЛАССА MATRIX ===" << endl;
    
    // Создание матриц
    Matrix m1(2, 2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    
    Matrix m2(2, 2);
    m2[0][0] = 5; m2[0][1] = 6;
    m2[1][0] = 7; m2[1][1] = 8;
    
    cout << "Матрица m1:" << endl << m1 << endl;
    cout << "Матрица m2:" << endl << m2 << endl;
    
    // Арифметические операции
    cout << "\nАрифметические операции:" << endl;
    cout << "m1 + m2:" << endl << (m1 + m2) << endl;
    cout << "m1 - m2:" << endl << (m1 - m2) << endl;
    cout << "m1 * m2:" << endl << (m1 * m2) << endl;
    cout << "m1 * 2.0:" << endl << (m1 * 2.0) << endl;
    
    // Матричные операции
    cout << "\nМатричные операции:" << endl;
    cout << "Транспонированная m1:" << endl << m1.transpose() << endl;
    cout << "Определитель m1: " << m1.determinant() << endl;
    
    try {
        Matrix inv = m1.inverse();
        cout << "Обратная матрица m1:" << endl << inv << endl;
        cout << "Проверка m1 * inv:" << endl << (m1 * inv) << endl;
    } catch (const exception& e) {
        cout << "Ошибка при вычислении обратной матрицы: " << e.what() << endl;
    }
    
    // Статические методы
    cout << "\nСтатические методы:" << endl;
    Matrix identity = Matrix::identity(3);
    cout << "Единичная матрица 3x3:" << endl << identity << endl;
    
    Matrix zeros = Matrix::zeros(2, 3);
    cout << "Нулевая матрица 2x3:" << endl << zeros << endl;
}

/**
 * @brief Демонстрация работы с классом Fraction
 */
void demonstrateFraction() {
    cout << "\n=== ДЕМОНСТРАЦИЯ КЛАССА FRACTION ===" << endl;
    
    // Создание дробей
    Fraction f1(3, 4);      // 3/4
    Fraction f2(2, 6);      // 2/6 = 1/3
    Fraction f3(5LL);       // 5/1 = 5
    
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << " (автоматически сокращена)" << endl;
    cout << "f3 = " << f3 << endl;
    
    // Арифметические операции
    cout << "\nАрифметические операции:" << endl;
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;
    
    // Операции сравнения
    cout << "\nОперации сравнения:" << endl;
    cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << endl;
    cout << "f1 > f2: " << (f1 > f2 ? "true" : "false") << endl;
    cout << "f1 < f3: " << (f1 < f3 ? "true" : "false") << endl;
    
    // Дополнительные функции
    cout << "\nДополнительные функции:" << endl;
    cout << "Абсолютное значение f1: " << f1.abs() << endl;
    cout << "Обратная дробь f1: " << f1.reciprocal() << endl;
    cout << "f1 в степени 2: " << f1.power(2) << endl;
    cout << "f1 как десятичная дробь: " << f1.toDouble() << endl;
    
    // Проверки
    cout << "\nПроверки:" << endl;
    cout << "f1 - правильная дробь: " << (f1.isProper() ? "да" : "нет") << endl;
    cout << "f3 - целое число: " << (f3.isInteger() ? "да" : "нет") << endl;
    
    // Работа с смешанными числами
    Fraction mixed(7, 3);   // 7/3 = 2 1/3
    cout << "\nСмешанное число " << mixed << ":" << endl;
    cout << "Целая часть: " << mixed.getIntegerPart() << endl;
    cout << "Дробная часть: " << mixed.getFractionalPart() << endl;
}

/**
 * @brief Основная функция программы
 */
int main() {
    setlocale(LC_ALL, "ru");
    cout << fixed << setprecision(3);
    
    // Заголовок программы
    cout << "==========================================" << endl;
    cout << "  БИБЛИОТЕКА МАТЕМАТИЧЕСКИХ КЛАССОВ" << endl;
    cout << "==========================================" << endl;
    cout << MathLib::getLibraryInfo() << endl;
    
    try {
        // Демонстрация всех классов
        demonstrateComplex();
        demonstrateVector3D();
        demonstrateMatrix();
        demonstrateFraction();
        
       
        
    } catch (const exception& e) {
        cout << "\nОШИБКА: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
