#include "round.h"
#include <iostream>
using namespace std;


int main(void){
    cout<<"enter time quanttum:";
    int tq;
    cin>>tq;
    
    bool a=true;
    int value,size,pos,k;
    dl arr(tq);
    while(a){
        cout<<"1.Insert \n";
        cout<<"2.execute\n";
        cout<<"3.end3\n";
        

        cout<<"Enter choice:";
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Enter value:";
            cin>>value;
            arr.insend(value);
        }
        if(choice==2){
            
            arr.execute();
        }     
        if(choice==3){
            a=false;
        }
        
    }  
}