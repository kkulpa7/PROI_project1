#include "calculator.h"
using namespace std;
void Calculator::setValue(Number num1, Number num2, char sign){
    this->firstNumber=num1;
    this->secondNumber=num2;
    this->operation=sign;
    if (sign=='+')
        this->resultNumber=num1+num2;
    if (sign=='-')
        this->resultNumber=num1-num2;
    if (sign=='*')
        this->resultNumber=num1*num2;
    if (sign=='/')
        this->resultNumber=num1/num2;
}
void Calculator::show(){
    cout<<this->firstNumber.getValue()<<this->operation<<this->secondNumber.getValue()<<"="<<this->resultNumber.getValue();
}
void Calculator::giveData(Calculator *calculator){
    Number number1, number2;
    string num;
    char sign;
    cout<<"First number: ";
    cin>>num;
    while(!checkingNumber(num)){
        cout<<"Wrong data! Give first number again: ";
        cin>>num;
    }
    number1.setValue(num);
    cout<<"Second number: ";
    cin>>num;
    while(!checkingNumber(num)){
        cout<<"Wrong data! Give second number again: ";
        cin>>num;
    }
    whatToDo(&sign);
	while (num=="0" && sign=='/'){
		cout<<"\nYou can not divide by 0!\nGive second number again: ";
		cin>>num;
		while(!checkingNumber(num)){
        		cout<<"\nWrong data! Give second number again: ";
			cin>>num;
		}
    }
    number2.setValue(num);
    (*calculator).setValue(number1, number2, sign);
}
void Calculator::whatToDo(char *sign){
    short int option;
    cout<<"\nWhat do you want to do?\n1. Add numbers.\n2. Subtract numbers.\n3. Multiply numbers.\n4. Divide numbers.\nChoose option: ";
    cin>>option;
    while (option<1 || option>4){
        cout<<"Wrong option! Choose option again: ";
        cin>>option;
    }
    switch(option){
    case 1:
        (*sign)='+';
        break;
    case 2:
        (*sign)='-';
        break;
    case 3:
        (*sign)='*';
        break;
    case 4:
        (*sign)='/';
    }

}
bool Calculator::checkingNumber(string num){
    if (num.length()>1 && (num[0]=='0' || (num[0]=='-' && num[1]=='0')))
        return false;
    for (unsigned int a=0; a<num.length(); a++){
        if (num[a]=='-' && a==0)
            continue;
        if (num[a]>='8' || num[a]<'0')
            return false;
    }
    return true;
}
void Calculator::whatToSee(Calculator calculator){
    short int option;
    cout<<"\nWhat do you what to see?\n1. Just result.\n2. All steps.\nChoose option: ";
    cin>>option;
    while(option<1 || option>2){
        cout<<"Wrong option! Choose option again: ";
        cin>>option;
    }
    switch(option){
    case 1:
        (calculator.resultNumber).show();
        cout<<endl;
        return;
    case 2:
        calculator.show();
        cout<<endl;
        return;
    }
}
