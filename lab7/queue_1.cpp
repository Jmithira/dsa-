//Program to implement Queue ADT using an Array with fixed size.
#include <iostream>
using namespace std;
#define SIZE 5

class Queue{
    
    private:
    int front;
    int rear;
    int a[SIZE];
    
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    
    //Function prototypes
    bool isfull();
    
    bool isempty();
    
    int enque(int);
    
    int deque();
    
    void peek();
    
    void disp();
};

int main(){
    class Queue q;
    int choice,val;
    do{
        cout<<"Menu\n";
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Peek\n";
        cout<<"4.Exit\n";
        cout<<"Enter Choice: \n";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter the value to be Queued: \n";
            cin>>val;
            cout<<q.enque(val)<<"\n";
            q.disp();
            cout<<"\n";
            break;
            
            case 2:
            cout<<q.deque()<<"\n";
            q.disp();
            cout<<"\n";
            break;
            
            case 3:
            q.peek();
            break;
        
            case 4:
            cout<<"Exiting...\n";
            break;

            default:
            cout<<"Invalid Choice!\n";
        }

    }
while(choice!=4);
}

//Function to check if the Queue is Full.
bool Queue::isfull(){
    return(rear==SIZE-1);
}

//Function to check if the Queue is Empty.
bool Queue::isempty(){
    return(front==-1||front>rear);
}

//Function to insert user input value at the back of the Queue(rear).
int Queue::enque(int val){
    if(isfull()){
        return 0;
    }
    if(front==-1){
        front=0;
    }
    a[++rear]=val;
    return 1;
}

//Function to remove the element in the front of the Queue.
int Queue::deque(){
    if(isempty()){
        return 0;
    }
    front++;
    if(front>rear){
        front=rear=-1;
    }
    return 1;
}

//Function to view the front most value in the Queue.
void Queue::peek(){
    if(!isempty()){
        cout<<a[front];
    }
    }
//Function to display the elements of the Queue.
void Queue::disp(){
    if (!isempty()){
    for(int i=front;i<=rear;i++){
        cout<<a[i]<<" ";
    }
    }
}