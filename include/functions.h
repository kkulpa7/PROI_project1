#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Number{
private:
    string value;
public:
    void setValue(string);
    string getValue();
    Number operator+(Number);
    Number operator-(Number);
    Number operator*(Number);
    Number operator/(Number);
};
/*class Calculator{
private:
	Number firstNumber;
	Number secondNumber;
public:
}*/
void show(Number);
void show(Number, Number, Number, char);
int octToDec(string);
string decToOct(int);
bool checkingNumer (string);
void giveNumbers(Number, Number);
void whatToDo(Number, Number);
void whatToSee(Number, Number, Number, char);
void menu();
