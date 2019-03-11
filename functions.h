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
    number operator+(number);
    number operator-(number);
    number operator*(number);
    number operator/(number);
};
void show(number);
void show(number, number, number, char);
int octToDec(string);
string decToOct(int);
bool checkingNumer (string);
void giveNumbers(number, number);
void whatToDo(number, number);
void whatToSee(number, number, number, char);
void menu();
