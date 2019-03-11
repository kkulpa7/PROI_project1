#include "functions.h"
void number::push(string num){
    this->value=num;
}
void number::showValue(){
    cout<<this->value;
}
void show(number num){
    num.showValue();
}
void show(number num1, number num2, number num3){
     num1.showValue();
     num2.showValue();
     cout<<"=";
     num3.showValue();
}
number number::operator+(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)+octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
number number::operator-(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)-octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
number number::operator*(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)*octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
number number::operator/(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)/octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
int octToDec(string num){
    int result=0;
    int multiplier=1;
    for (int a=num.length()-1; a>=0; a--){
        result+=(num[a]-'0')*multiplier;
        multiplier*=8;
    }
    return result;
}
string decToOct(int num){
    string result="";
    int divider=1;
    char sign;
    while(divider<=num)
        divider*=8;
    while(num>0 || divider!=1){
        divider/=8;
        sign=num/divider+'0';
        num-=(sign-'0')*divider;
        result+=sign;
    }
    if(result=="")
        return "0";
    return result;
}
bool checkingNumber(string num){
    if (num[0]=='0')
        return false;
    for (int a=0; a<num.length(); a++)
        if (num[a]>='8' || num[a]<'0')
            return false;
    return true;
}
void giveNumbers(number *number1, number *number2){
    string num1, num2;
    cout<<"First number: ";
    cin>>num1;
    while(!checkingNumber(num1)){
        cout<<"Wrong data! Give first number again: ";
        cin>>num1;
    }
    (*number1).push(num1);
    cout<<"Second number: ";
    cin>>num2;
    while(!checkingNumber(num2)){
        cout<<"Wrong data! Give second number again: ";
        cin>>num2;
    }
    (*number2).push(num2);
}
void menu(){
    srand(time(NULL));
    number n1, n2;
    giveNumbers(&n1, &n2);
}
