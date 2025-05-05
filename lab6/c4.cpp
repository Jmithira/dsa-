#include "ex.h"
#include <iostream>
using namespace std;


int main(void){
    cout<<"Enter the equation: ";
    char arr[100];
    cin.getline(arr,'$');
    stack ar;
    
    for(int i=0;i<100;i++){
        if (arr[i]=='('){
            ar.push(arr[i]);
        }
        if (arr[i]==')'){
            ar.pop();
        }
    }

    if (ar.peek()==1){
        printf("Balanced");
    }else{
        printf("not balanced");
    }

}