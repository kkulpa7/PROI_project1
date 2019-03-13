#include "functions.h"
//using namespace std;
void Number::getValue(string num){
    this->value=num;
}
string Number::getValue(){
    return this->value;
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
void show(Number num){
    cout<<num.getValue();
}
void show(Number num1, Number num2, Number num3, char sign){
     cout<<num1.getValue()<<sign<<num2.getValue()<<"="<<num3.getValue();
}
int octToDec(string num){
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
string decToOct(int num){
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
bool checkingNumber(string num){
    if (num.length()>1 && (num[0]=='0' || (num[0]=='-' && num[1]=='0')))
        return false;
    for (int a=0; a<num.length(); a++){
        if (num[a]=='-' && a==0)
            continue;
        if (num[a]>='8' || num[a]<'0')
            return false;
    }
    return true;
}
void giveNumbers(Number *number1, Number *number2){
    string num1, num2;
    cout<<"First number: ";
    cin>>num1;
    while(!checkingNumber(num1)){
        cout<<"Wrong data! Give first number again: ";
        cin>>num1;
    }
    (*number1).setValue(num1);
    cout<<"Second number: ";
    cin>>num2;
    while(!checkingNumber(num2)){
        cout<<"Wrong data! Give second number again: ";
        cin>>num2;
    }
    (*number2).setValue(num2);
}
void whatToDo(Number num1, Number num2){
    short int option;
    Number num3;
    char sign;
    while(1){
        cout<<"\nWhat do you want to do?\n1. Add numbers.\n2. Subtract numbers.\n3. Multiply numbers.\n4. Divide numbers.\n5. Give another numbers.\n6. Exit.\nChose option: ";
        cin>>option;
        while (option<1 || option>6){
            cout<<"Wrong option! Chose option again: ";
            cin>>option;
        }
        switch(option){
        case 1:
            num3=num1+num2;
            sign='+';
            whatToSee(num1, num2, num3, sign);
            break;
        case 2:
            num3=num1-num2;
            sign='-';
            whatToSee(num1, num2, num3, sign);
            break;
        case 3:
            num3=num1*num2;
            sign='*';
            whatToSee(num1, num2, num3, sign);
            break;
        case 4:
            num3=num1/num2;
            sign='/';
            whatToSee(num1, num2, num3, sign);
            break;
        case 5:
            cout<<endl;
            giveNumbers(&num1, &num2);
            break;
        case 6:
            return;
        }
    }
}
void whatToSee(Number num1, Number num2, Number num3, char sign){
    short int option;
    cout<<"\nWhat do you what to see?\n1. Just result.\n2. All steps.\nChose option: ";
    cin>>option;
    while(option<1 || option>2){
        cout<<"Wrong option! Chose option again: ";
        cin>>option;
    }
    switch(option){
    case 1:
        show(num3);
        cout<<endl;
        return;
    case 2:
        show(num1, num2, num3, sign);
        cout<<endl;
        return;
    }
}
void menu(){
    srand(time(NULL));
    Number n1, n2;
    cout<<"MAGIC CALCULATOR (octal)"<<endl;
    giveNumbers(&n1, &n2);
    whatToDo(n1, n2);
}
