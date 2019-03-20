#include "Calculator.h"
#include "functions.h"
using namespace std;
void menu(){
    srand(time(NULL));
    cout<<"MAGIC CALCULATOR (octal)"<<endl;
    Calculator calculator;
    short int option;
    while(1){
        calculator.giveData(&calculator);
        calculator.whatToSee(calculator);
        cout<<"\nDo you want to continue program?\n1. Yes.\n2. No.\nChoose option: ";
        cin>>option;
        while(option<1 || option>2){
            cout<<"Wrong option! Choose option again: ";
            cin>>option;
        }
	if (option==2)
		return;
        cout<<endl;
    }
}
