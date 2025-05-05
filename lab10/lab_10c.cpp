#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;

    void heapifyUp(int);
    void heapifyDown(int);
    void heapSortHelper(vector<int>&);

public:
    PriorityQueue() {}
    void insert(int);
    void deleteMax();
    void display();
    void search(int);
    void heapSort();
};

int main()
{
    int choice;
    int val;
    PriorityQueue pq;
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Delete\n 3. Display\n 4. Search\n 5. Sort (Heap Sort)\n 6. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> val;
            pq.insert(val);
            cout << "Insertion Successful." << endl;
            break;

        case 2:
            pq.deleteMax();
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Enter element to search for : ";
            cin >> val;
            pq.search(val);
            break;

        case 5:
            pq.heapSort();
            break;

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}

// Function to maintain heap property by moving element up
void PriorityQueue::heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index])
        {
            swap(heap[parent], heap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

// Function to maintain heap property by moving element down
void PriorityQueue::heapifyDown(int index)
{
    int size = heap.size();
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else
        {
            break;
        }
    }
}

// Function to insert an element into priority queue
void PriorityQueue::insert(int val)
{
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

// Function to delete maximum element from priority queue
void PriorityQueue::deleteMax()
{
    if (heap.empty())
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!heap.empty())
    {
        heapifyDown(0);
    }

    cout << "Deleted element: " << maxVal << endl;
}

// Function to display priority queue elements
void PriorityQueue::display()
{
    if (heap.empty())
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    cout << "Priority Queue elements: ";
    for (int val : heap)
    {
        cout << val << " ";
    }
    cout << endl;
}

// Function to search for an element in priority queue
void PriorityQueue::search(int val)
{
    auto it = find(heap.begin(), heap.end(), val);
    if (it != heap.end())
    {
        cout << "Element " << val << " found in priority queue." << endl;
    }
    else
    {
        cout << "Element " << val << " not found." << endl;
    }
}

// Helper function for heap sort
void PriorityQueue::heapSortHelper(vector<int>& temp)
{
    if (temp.empty()) return;
    
    cout << temp[0] << " ";
    swap(temp[0], temp.back());
    temp.pop_back();
    
    if (!temp.empty())
    {
        heapifyDown(0);
        heapSortHelper(temp);
    }
}

// Function to perform heap sort
void PriorityQueue::heapSort()
{
    if (heap.empty())
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    vector<int> temp = heap;
    cout << "Sorted elements (descending order): ";
    heapSortHelper(temp);
    cout << endl;
}