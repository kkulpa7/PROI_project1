#include "calculator.h"
using namespace std;
void menu(){
    srand(time(NULL));
    cout<<"MAGIC CALCULATOR (octal)"<<endl;
    Calculator calculator;
    short int option;
    char sign;
    while(1){
        calculator.giveData(&calculator);
        calculator.whatToSee(calculator);
        cout<<"\nWhat do you want to do?\n1. Continue.\n2. Finish program.\nChoose option: ";
        cin>>option;
        while(option<1 || option>2){
            cout<<"Wrong option! Choose option again: ";
            cin>>option;
        }
        cout<<endl;
    }
}
