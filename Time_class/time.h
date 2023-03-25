#ifndef TIME_H
#define TIME_H
#include<iostream>
using namespace std;
class Time
{
private:
    int sec_=0,minu_=0,hours_=0;
public:
    Time(int sec=0);    //Default constructor
    void print() const; //print function
    Time operator+(const Time &rhs)const;
    Time operator-(const Time &rhs)const;
    friend ostream &operator<<(ostream &str, Time &rhs);
    friend istream &operator>>(istream &str, Time &rhs);
    operator int();
};

#endif // TIME_H
