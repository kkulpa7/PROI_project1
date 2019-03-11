#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class number{
private:
    string value;
public:
    void push(string);
    void showValue();
    number operator+(number &);
    number operator-(number &);
    number operator*(number &);
    number operator/(number &);
};
void show(number);
void show(number, number, number);
int octToDec(string);
string decToOct(int);
bool checkingNumer (string);
void giveData(number, number);
void menu();
