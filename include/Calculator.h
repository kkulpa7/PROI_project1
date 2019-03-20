#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Number.h"
class Calculator{
private:
    Number firstNumber;
	Number secondNumber;
	char operation;
	Number resultNumber;
public:
    void setValue(Number, Number, char);
    void show();
    bool checkingNumber(std::string);
    void giveData(Calculator *);
    void whatToDo(char *);
    void whatToSee();
};
#endif
