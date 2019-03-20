#include "Number.h"
using namespace std;
void Number::setValue(string num){
    this->value=num;
}
string Number::getValue(){
    return this->value;
}
void Number::show(){
    cout<<this->value;
}
Number Number::operator+(Number num){
    Number result;
    result.value=decToOct(octToDec(this->value)+octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
Number Number::operator-(Number num){
    Number result;
    result.value=decToOct(octToDec(this->value)-octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
Number Number::operator*(Number num){
    Number result;
    result.value=decToOct(octToDec(this->value)*octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
Number Number::operator/(Number num){
    Number result;
    result.value=decToOct(octToDec(this->value)/octToDec(num.value));
    int randomNumber=rand();
    if (randomNumber%2!=0)
        result.value=decToOct(randomNumber);
    return result;
}
int Number::octToDec(string num){
    int result=0;
    int multiplier=1;
    short int mod=1;
    if (num[0]=='-'){
        mod=-1;
        num=num.substr(1, num.length()-1);
    }
    for (int a=num.length()-1; a>=0; a--){
        result+=(num[a]-'0')*multiplier;
        multiplier*=8;
    }
    return mod*result;
}
string Number::decToOct(int num){
    string result="";
    int divider=1;
    char sign;
    short int mod=1;
    if (num<0){
        mod=-1;
        num*=-1;
    }
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
    if (mod==-1)
        result='-'+result;
    return result;
}
