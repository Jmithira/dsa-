// Program to implement Circular Queue ADT
#include <iostream>
using namespace std;

class adt {
private:
    int arrr[5];
    int front, rear, pos;
public:
    adt() {
        front = -1;
        rear = -1;
        pos = 0;
    }
    void enqueue(int n);  
    void dequeue();      
    void peek();        
};

int main(void) { 
    bool loop_condition = true;
    int value;
    adt arr;
    
    while (loop_condition) {
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Peek\n";
        cout << "4.Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number: ";
            cin >> value;
            cout << '\n';
            arr.enqueue(value);
        }
        if (choice == 2) {
            arr.dequeue();
        }     
        if (choice == 3) {
            arr.peek();
        }
        if (choice == 4) {
            loop_condition = false;
        }
        
        cout << '\n';
        cout << "=========================================\n\n";
    }
}

// Function to insert an element into the circular queue
void adt::enqueue(int n) {
    if ((rear + 1) % 5 == front) { 
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % 5;
    }
    arrr[rear] = n;
    cout << "Enqueued: " << n << endl;
}

// Function to remove an element from the circular queue
void adt::dequeue() {
    if (front == -1) { 
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Dequeued: " << arrr[front] << '\n';
    
    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % 5; 
    }
}

// Function to display the front element of the circular queue
void adt::peek() {
    if (front == -1) { 
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Front element: " << arrr[front] << '\n';
}
