/**
 * @file Complex.h
 * @brief ����� ��� ������ � ������������ �������
 * @author ���� ���
 * @date 2024
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

/**
 * @class Complex
 * @brief ����� ��� ������������� � �������� � ������������ �������
 * 
 * ����� ������������� ������ ����� �������� ��� ������ � ������������ �������:
 * �������������� ��������, ���������� ������, ��������� � ��.
 */
class Complex {
private:
    double real_;  ///< �������������� ����� ������������ �����
    double imag_;  ///< ������ ����� ������������ �����

public:
    /**
     * @brief ����������� �� ���������
     * ������� ����������� ����� 0 + 0i
     */
    Complex();

    /**
     * @brief ����������� � �����������
     * @param real �������������� �����
     * @param imag ������ �����
     */
    Complex(double real, double imag = 0.0);

    /**
     * @brief ����������� �����������
     * @param other ���������� ������
     */
    Complex(const Complex& other);

    /**
     * @brief ����������
     */
    ~Complex();

    // ������ �������
    /**
     * @brief �������� �������������� �����
     * @return �������������� ����� �����
     */
    double getReal() const;

    /**
     * @brief �������� ������ �����
     * @return ������ ����� �����
     */
    double getImag() const;

    /**
     * @brief ���������� �������������� �����
     * @param real ����� �������� �������������� �����
     */
    void setReal(double real);

    /**
     * @brief ���������� ������ �����
     * @param imag ����� �������� ������ �����
     */
    void setImag(double imag);

    // �������������� ���������
    /**
     * @brief �������� ������������
     * @param other ������������� ������
     * @return ������ �� ������� ������
     */
    Complex& operator=(const Complex& other);

    /**
     * @brief �������� ��������
     * @param other ���������
     * @return ��������� ��������
     */
    Complex operator+(const Complex& other) const;

    /**
     * @brief �������� ���������
     * @param other ����������
     * @return ��������� ���������
     */
    Complex operator-(const Complex& other) const;

    /**
     * @brief �������� ���������
     * @param other ���������
     * @return ��������� ���������
     */
    Complex operator*(const Complex& other) const;

    /**
     * @brief �������� �������
     * @param other ��������
     * @return ��������� �������
     * @throw std::invalid_argument ���� �������� ����� ����
     */
    Complex operator/(const Complex& other) const;

    // ��������� ��������� ������������
    /**
     * @brief �������� +=
     * @param other ���������
     * @return ������ �� ������� ������
     */
    Complex& operator+=(const Complex& other);

    /**
     * @brief �������� -=
     * @param other ����������
     * @return ������ �� ������� ������
     */
    Complex& operator-=(const Complex& other);

    /**
     * @brief �������� *=
     * @param other ���������
     * @return ������ �� ������� ������
     */
    Complex& operator*=(const Complex& other);

    /**
     * @brief �������� /=
     * @param other ��������
     * @return ������ �� ������� ������
     */
    Complex& operator/=(const Complex& other);

    // ��������� ���������
    /**
     * @brief �������� ���������
     * @param other ������������ ������
     * @return true ���� ����� �����
     */
    bool operator==(const Complex& other) const;

    /**
     * @brief �������� �����������
     * @param other ������������ ������
     * @return true ���� ����� �� �����
     */
    bool operator!=(const Complex& other) const;

    // �������������� �������
    /**
     * @brief ��������� ������ ������������ �����
     * @return ������ �����
     */
    double magnitude() const;

    /**
     * @brief ��������� �������� ������������ �����
     * @return �������� � ��������
     */
    double argument() const;

    /**
     * @brief �������� ����������-����������� �����
     * @return ����������� �����
     */
    Complex conjugate() const;

    /**
     * @brief �������� � �������
     * @param power ���������� �������
     * @return ��������� ���������� � �������
     */
    Complex power(double power) const;

    /**
     * @brief ��������� ���������� ������
     * @return ������� �������� ����������� �����
     */
    Complex sqrt() const;

    // ������������� ������� ��� �����/������
    /**
     * @brief �������� ������ � �����
     * @param os �������� �����
     * @param complex ����������� ����� ��� ������
     * @return ������ �� �����
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);

    /**
     * @brief �������� ����� �� ������
     * @param is ������� �����
     * @param complex ����������� ����� ��� �����
     * @return ������ �� �����
     */
    friend std::istream& operator>>(std::istream& is, Complex& complex);
};

#endif // COMPLEX_H 