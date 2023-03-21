#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>
#include<string.h>
#include<cstring>
class Rational {
public:
    Rational(int num = 0, int den = 1); // default constructor

    void set(int num, int den); // sets numerator and denominator
    int num() const; // gets numerator
    int den() const; // gets denominator
    void set_num(int num); // sets numerator
    void set_den(int den); // sets denominator
    Rational add(const Rational &other) const; // adds second rational number, returns result
    Rational subtract(const Rational &other) const; // subtracts second rational number, returns result
    void print() const; // prints number to console
    Rational operator+(const Rational &rhs) const; // rhs - Right Hand Side - right operand
    Rational operator-(const Rational &rhs) const;
    Rational operator*(const Rational &rhs) const;
    Rational operator/(const Rational &rhs) const;
    friend std::ostream &operator<<(std::ostream &str, Rational &rhs);
    friend std::istream &operator>>(std::istream &str, Rational &rhs);
    Rational (double r);
    operator double();
private:
    int num_, den_;
};

#endif // RATIONAL_H
