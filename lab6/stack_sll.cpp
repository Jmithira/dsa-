// Program to perform stack operations using singly linked list
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
    stack(){head=nullptr;}

    ~stack(){
        struct sll *current = head;
        while (current!=NULL){
            struct sll *temp=current;
            current=current->next;
            free(temp);
        }
    }

    // Function Prototypes
    void push(char);
    char pop();
    char peek();
};

int main(){
    int choice;
    char c,k;
    stack s;
    do{
        cout<<"\nStack Operations:\n";
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
            cout<<c<<" pushed into the stack\n";
            break;
            
            case 2:
            k=s.pop();
            if (k=='\0'){
                cout<<"Stack Underflow\n";
            }
            else{
                cout<<k<<" popped from the stack\n";
            }
            break;


            case 3:
            k=s.peek();
            if (k=='\0'){
                cout<<"Stack is empty\n";
            }
            else{
                cout<<k<<endl;
            }
            break;

            case 4:
            cout<<"Exiting\n";
            break;

            default:
            cout<<"Enter a valid choice\n";
            break;
        }
    }while (choice!=4);

    return 0;
}

// Function to push a character to a stack
void stack::push(char c){
    sll* newptr = new sll{c, nullptr};
    if (head==nullptr){
        head=newptr;
        return;
    }
    newptr->next=head;
    head=newptr;
}

// Function to pop the element from stack
char stack::pop(){
    if (head==nullptr){
        return '\0';
    }
    struct sll *temp = (struct sll*)malloc(sizeof(struct sll));
    temp=head;
    head=head->next;
    return temp->letter;

}

// Function to peek the top element
char stack::peek(){
    if (head==nullptr){
        return '\0';
    }
    return head->letter;
}