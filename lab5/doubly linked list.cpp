//prgram for dl
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* pre;
    
};

class dl{
    private:
        node* head;
        node* tail;
    public:
        dl(){
            head=nullptr;
            tail=nullptr;
        }

        void insbeg(int val){   //ins first element
            node *newptr= new node{val,nullptr,nullptr};
             
            if(!head){
                head=tail=newptr;
            }else{
                newptr->next=head;
                head->pre=newptr;
                head=newptr;           
            }
        }

        void disp(){        // display elemnts
            node *temp;
            temp=(node*)malloc(sizeof(node));
            temp=head;
            if(!temp){
                cout << "list empty\n";
            }else{
                while(temp){
                    cout<< temp->data << " ";
                    temp=temp->next;
                }
                cout<<"\n";
            }
            temp=tail;
            if(!temp){
                cout << "list empty\n";
            }else{
                while(temp){
                    cout<< temp->data << " ";
                    temp=temp->pre;
                }
                cout<<"\n";
            }
        }     

        void insend(int val){ // ins elemetns in end
            node *temp=head;
            
            while(temp->next){
                temp=temp->next;
            }
            node *newptr= new node{val,nullptr,temp};
            temp->next=newptr;
            tail=newptr;
        }

        void inspos(int val,int pos){       //ins element at pos
            node *temp=head;
            
            if(pos<=1){
                insbeg(val);
                return;
            }else{
                
                int c=1;
                pos--;
                while(temp && pos>c){
                    temp=temp->next;
                    c++;
                }
                if(!temp){
                    insend(val);
                    return;
                }
                node *newptr= new node{val,temp->next,temp}; 
                if(temp->next){
                    temp->next->pre=newptr;
                }
                temp->next=newptr;
                
            }
        }

        void dltbeg(){ // dlt element in beging
            head=head->next;
            
            if(head!=nullptr){
                head->pre=nullptr;
            }else{
                tail=nullptr;
            }
        }

        void dltend(){      //dlt element in end
            node *temp=head;
            if (!temp->next){
                temp=head=nullptr;
                tail=nullptr;
            }else{
             while(temp->next->next){
                temp=temp->next;
            }
            temp->next->pre=nullptr;
            temp->next=nullptr;
            tail=temp;
            }
        }

        void dltpos(int pos){
            if(pos<=1){
                dltbeg();
            }else{
                node *temp=head;
                node *temp2;
                while(temp && pos-1>1){
                    temp=temp->next;
                    pos--;
                }
                cout<<"hii\n";
                if(!temp->next->next){
                    dltend();
                    cout<<"hi1\n";
                    return;
                }
                temp2=temp->next;
                cout<<"hiii\n";
                temp->next=temp2->next;
                cout<<"hi\n";
                if(temp2->next){
                temp2->next->pre=temp;}
            }
        }
};


int main(void){                                            // menu iteration
    bool a=true;
    int value,size,pos,k;
    dl arr;
    while(a){
        cout<<"1.Insert benging\n";
        cout<<"2.Insert at position\n";
        cout<<"3.Insert end\n";
        cout<<"4.Delete begining\n";
        cout<<"5.Delete position\n";
        cout<<"6.Delete end\n";
        cout<<"7.Display\n";
        cout<<"8.Repeat\n";
        cout<<"9.Exit\n";

        cout<<"Enter choice:";
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Enter value:";
            cin>>value;
            arr.insbeg(value);
        }
        if(choice==2){
            cout<<"Enter value:";
            cin>>value;
            cout<<"Enter position:";
            cin>>pos;
            arr.inspos(value,pos);
        }     
        if(choice==3){
            cout<<"Enter value:";
            cin>>value;
            arr.insend(value);
        }
        if(choice==4){
            arr.dltbeg();
        }
        if(choice==5){
            cout<<"Enter position:";
            cin>>pos;
            arr.dltpos(pos);
        }
        if(choice==6){
            arr.dltend();
        }     
        if(choice==7){
            arr.disp();
        }
        if(choice==9){
            a=false;
        }
        if(choice==8){
            cout<<"Enter times to repeat:";
            cin>>k;
            //arr.repeat(k);
        }
    }
}