//code for stack using linked list

#include <iostream>
using namespace std;

struct sll{
    char letter;
    struct sll* next;
};

class stack{
    private:
        struct sll* head;

    public:
        
        stack(){
            head=nullptr;
        }

        void push(char c);
        void pop();
        int peek();
};  

/*int main(void){   
                                             // menu iteration
    bool loop_condition=true;
    int size,pos,k;
    char value;
    stack arr;
    
    while(loop_condition){
        cout<<"1.Push\n";
        cout<<"2.Pop\n";
        cout<<"3.Peek\n";
        cout<<"4.Exit\n";
        cout<<"Enter choice:";
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Enter character:";
            cin>>value;
            cout<<'\n';
            arr.push(value);
        }
        if(choice==2){
            arr.pop();
        }     
        if(choice==3){
            arr.peek();
        }
        if(choice==4){
            loop_condition=false;
        }    
        cout<<'\n';
        cout<<"=========================================\n\n";
    }
}*/

void stack::push(char c) {
    sll *newptr= new sll{c,nullptr};
    if(head==nullptr){
        head=newptr;
        return;
    }
    newptr->next=head;
    head=newptr;
}
void stack::pop(){
    if(head==nullptr){
        cout<<"\nStack Underflow\n";
        return;
    }
    
    head=head->next;
}
int stack::peek(){
    if(head==nullptr){
        
        return 1;
    }
    
}