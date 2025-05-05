#include <iostream>
using namespace std;

#define SIZE 5
class stack{
    public:
    int arr[SIZE];
    int top;
    stack(){
        top=-1;
    }

    //Function Prototypes
    void push(char);
    void peek();
    void pop();
};

int main(){
    stack s;
    int choice;
    char c;
    do{
        cout<<"\nStack operations:\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter a character:";
            cin>>c;
            s.push(c);
            break;

            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

            case 4:
            cout<<"Exiting\n";
            break;
        }
    }while(choice !=4);
}

void stack::push(char c){
    if (top==SIZE-1){
        cout<<"Overflow\n";
        return;
    }
    arr[++top]=c;
}

void stack::pop(){
    if (top==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    char p=arr[top--];
    cout<<p;
}

void stack::peek(){
    if (top==-1){
        cout<<"Stack empty\n";
        return;
    }
    char p=arr[top];
    cout<<p<<endl;
}
