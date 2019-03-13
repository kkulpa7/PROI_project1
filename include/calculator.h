#include "number.h"
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
    void whatToSee(Calculator);
    void all(Calculator);
};
