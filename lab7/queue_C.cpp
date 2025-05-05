// Program to implement queue using linked list
#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Function prototypes
    bool isEmpty(); 
    int enqueue(int); 
    int dequeue(); 
    void peek(); 
    void display(); 
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "Menu\n";
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Peek\n";
        cout << "4.Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be Queued: ";
                cin >> val;
                cout << q.enqueue(val) << "\n";
                q.display();
                cout << "\n";
                break;
            
            case 2:
                cout << q.dequeue() << "\n";
                q.display();
                cout << "\n";
                break;
            
            case 3:
                q.peek();
                break;
            
            case 4:
                cout << "Exiting...\n";
                break;
            
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 4);
}

// Function to check if the queue is empty
bool Queue::isEmpty() {
    return (front == nullptr);
}

// Function to insert an element at the rear of the queue
int Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    return 1;
}

// Function to remove an element from the front of the queue
int Queue::dequeue() {
    if (isEmpty()) {
        return 0;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return 1;
}

// Function to view the front element of the queue
void Queue::peek() {
    if (!isEmpty()) {
        cout << front->data << "\n";
    } else {
        cout << "Queue is empty!\n";
    }
}

// Function to display all elements in the queue
void Queue::display() {
    if (!isEmpty()) {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    } else {
        cout << "Queue is empty!\n";
    }
}
