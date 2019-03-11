#include "functions.h"
void number::push(string num){
    this->value=num;
}
void number::show(){
    cout<<this->value;
}
number number::operator+(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)+octToDec(num.value));
    return result;
}
number number::operator-(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)-octToDec(num.value));
    return result;
}
number number::operator*(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)*octToDec(num.value));
    return result;
}
number number::operator/(number &num){
    number result;
    result.value=decToOct(octToDec(this->value)/octToDec(num.value));
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
