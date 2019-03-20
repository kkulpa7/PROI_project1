#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <cstdlib>
class Number{
private:
    std::string value;
public:
    void setValue(std::string);
    std::string getValue();
    void show();
    Number operator+(Number);
    Number operator-(Number);
    Number operator*(Number);
    Number operator/(Number);
    int octToDec(std::string);
    std::string decToOct(int);
};
#endif
