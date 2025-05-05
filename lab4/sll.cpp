// Program to perform various operaions: Insertion , Deletion, etc. on Singly Linked List
#include <iostream>
#include <cstdlib>
using namespace std;

class List{

    private:
    struct node{
        int data;
        struct node *next;
    }*head;

    public:
    List():head(nullptr){}

    ~List(){
        struct node *current=head;
        while(current!=NULL){
            struct node *temp=current;
            current=current->next;
            free(temp);
        }
    }

    // Function Prototypes
    void insert_beg(int);
    void insert_end(int);
    void insert_pos(int,int);
    int delete_beg();
    void delete_end();
    int delpos(int);
    int search(int);
    void revdisplay();
    void revdisplay(node* head);
    void reverselink();
    void display();

};

int main(){
    List l;
    int choice, val, pos,ele, index;

    do{
        cout<<"Menu:\n";
        cout<<"1. Insert Beginning\n";
        cout<<"2. Insert End\n";
        cout<<"3. Insert Position\n";
        cout<<"4. Delete Beginning\n";
        cout<<"5. Delete End\n";
        cout<<"6. Delete Position\n";
        cout<<"7. Search\n";
        cout<<"8. Display\n";
        cout<<"9. Display Reverse\n";
        cout<<"10. Reverse Link\n";
        cout<<"11. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter the value to be inserted:";
            cin>>val;
            l.insert_beg(val);
            cout<<"Inserted\n";
            break;

            case 2:
            cout<<"Enter the value to be inserted: ";
            cin>>val;
            l.insert_end(val);
            cout<<"Inserted\n";
            break;

            case 3:
            cout<<"Enter the value to be inserted: ";
            cin>>val;
            cout<<"Enter the position:";
            cin>>pos;
            l.insert_pos(val,pos);
            cout<<"Inserted\n";
            break;

            case 4:
            ele=l.delete_beg();
            if (ele==0){
                cout<<"List is Empty\n";
            }
            cout<<ele<<" deleted from the list\n";
            break;

            case 5:
            l.delete_end();
            cout<<"Deleted last element\n"<<endl;
            break;

            case 6:
            cout <<"Enter position to be deleted: ";
            cin >> pos;
            ele=l.delpos(pos);
            cout <<"The deleted value is: "<<ele<<"\n";
            break;
            

            case 7:
            cout<<"Enter the value to be searched: ";
            cin>>val;
            index=l.search(val);
            if (index==-1){
                cout<<"Element not found\n";
            }
            cout<<val<<" found at index "<<index;
            break;
            

            case 8:
            cout<<"Elements of the list: ";
            l.display();
            cout<<"\n";
            break;

            case 9: 
                cout <<"The list in reverse: ";
                l.revdisplay();
                l.display();
                cout<<"\n";
                break;

            case 10:
                l.reverselink();
                cout <<"The list after reversing ";
                l.display();
                cout <<"\n";
                break;

            case 11:
            cout<<"Exiting\n";
            break;


            default:
            cout<<"Enter a valid option\n";
            break;
        }
    }while(choice!=11);

}

// Function to insert value at the beginning
void List::insert_beg(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

// Function to display elements of the list
void List::display(){
    struct node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


// Function to insert an element at the end
void List::insert_end(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    struct node *temp;
    temp=head;

    if(head==NULL){
        head=newnode;
    }
    else{
        while (temp->next !=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}


// Function to insert element at a position
void List::insert_pos(int val,int pos){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if (pos==1){
        newnode->data=val;
        newnode->next=head;
        head=newnode;
        return;
    }
    newnode->data=val;
    newnode->next=NULL;
    struct node *temp=head;

    for (int i=1; temp!=NULL && i<pos-1; i++){
        temp=temp->next;
    }
    if (temp==NULL){
        cout<<"position out of bounds\n"<<endl;
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;

}

// Function to delete element at given position
int List::delete_beg(){
    if (head==NULL){
        return 0;
    }
    struct node *temp=head;
    head=head->next;
    return temp->data;
    free(temp);

}

// Function to delete element at the end
void List::delete_end(){
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}


// Function to delete element at a given positon
int List::delpos(int pos){
    if(head->next==NULL){
        int v=head->data;
        head=NULL;
        return v;
    }
    node *temp=head;
    for(int i=1;i<pos-1;i++){
        if(temp->next==NULL){
            cout <<"Index out of range";
            return 0;
        }
        temp=temp->next;
    }
    int val=temp->next->data;
    temp->next=temp->next->next;
    return val;
}

// Function to search an element 
int List::search(int val){
    struct node *temp=head;
    int idx=0;
    while (temp!=NULL){
        if (temp->data==val){
            return idx;
        }
        else{
            temp=temp->next;
            idx++;
        }
    }return -1;

}

// Function to display the list in reverse
void List::revdisplay(node* head) {
    if (head == NULL) return;
    revdisplay(head->next);
    cout << head->data << " ";
}

// Function to display list in reverse
void List::revdisplay() {
    revdisplay(head);
}

// Function to reverse link all elements and display in reverse
void List::reverselink(){
    node *prev=NULL,*curr=head, *next=NULL;
    while (curr){
        next=curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}