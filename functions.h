#include <iostream>
using namespace std;
class number{
private:
    string value;
public:
    void push(string);
    void show();
    number operator+(number &);
    number operator-(number &);
    number operator*(number &);
    number operator/(number &);
};
int octToDec(string);
string decToOct(int);
int draw();
