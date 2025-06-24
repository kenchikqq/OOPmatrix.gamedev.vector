/**
 * @file MathLibrary.h
 * @brief Главный заголовочный файл библиотеки математических классов
 * @author Ваше имя
 * @date 2024
 * @version 1.0
 */

#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

/**
 * @mainpage Библиотека математических классов
 * 
 * Эта библиотека предоставляет набор классов для выполнения различных математических операций:
 * 
 * @section classes_sec Классы библиотеки
 * 
 * - @ref Complex "Complex" - класс для работы с комплексными числами
 * - @ref Vector3D "Vector3D" - класс для работы с трехмерными векторами  
 * - @ref Matrix "Matrix" - класс для работы с матрицами
 * - @ref Fraction "Fraction" - класс для работы с обыкновенными дробями
 * 
 * @section usage_sec Пример использования
 * 
 * @code
 * #include "MathLibrary.h"
 * 
 * int main() {
 *     // Работа с комплексными числами
 *     Complex c1(3, 4);
 *     Complex c2(1, 2);
 *     Complex sum = c1 + c2;
 *     
 *     // Работа с векторами
 *     Vector3D v1(1, 2, 3);
 *     Vector3D v2(4, 5, 6);
 *     double dot = v1.dotProduct(v2);
 *     
 *     // Работа с матрицами
 *     Matrix m1(2, 2);
 *     m1[0][0] = 1; m1[0][1] = 2;
 *     m1[1][0] = 3; m1[1][1] = 4;
 *     
 *     // Работа с дробями
 *     Fraction f1(1, 2);
 *     Fraction f2(1, 3);
 *     Fraction sum_f = f1 + f2;
 *     
 *     return 0;
 * }
 * @endcode
 * 
 * @section features_sec Особенности
 * 
 * - Все классы поддерживают стандартные арифметические операторы
 * - Реализованы операторы ввода/вывода для удобной работы
 * - Предусмотрена обработка исключительных ситуаций
 * - Код снабжен подробными Doxygen комментариями
 * 
 * @section requirements_sec Требования
 * 
 * - Компилятор с поддержкой C++11 или новее
 * - Стандартная библиотека C++
 */

// Включаем все заголовочные файлы библиотеки
#include <string>
#include "Complex.h"
#include "Vector3D.h"
#include "Matrix.h"
#include "Fraction.h"

/**
 * @namespace MathLib
 * @brief Пространство имен библиотеки математических классов
 */
namespace MathLib {
    
    /**
     * @brief Версия библиотеки
     */
    const char* const VERSION = "1.0.0";
    
    /**
     * @brief Автор библиотеки
     */
    const char* const AUTHOR = "Ваше имя";
    
    /**
     * @brief Дата создания
     */
    const char* const DATE = "2024";
    
    /**
     * @brief Получить информацию о библиотеке
     * @return Строка с информацией о версии и авторе
     */
    inline std::string getLibraryInfo() {
        return std::string("Библиотека математических классов v") + VERSION + 
               " (автор: " + AUTHOR + ", " + DATE + ")";
    }
    
    /**
     * @brief Получить информацию о библиотеке в виде строки
     * @return Строка с подробной информацией о всех классах
     */
    inline std::string getDetailedInfo() {
        return std::string("Библиотека содержит 4 основных класса:\n") +
               "1. Complex - комплексные числа\n" +
               "2. Vector3D - трехмерные векторы\n" + 
               "3. Matrix - матрицы\n" +
               "4. Fraction - обыкновенные дроби\n" +
               "Все классы поддерживают основные математические операции.";
    }
    
} // namespace MathLib

#endif // MATHLIBRARY_H 