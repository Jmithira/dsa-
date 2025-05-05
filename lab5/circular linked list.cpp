//prgram for dl
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

class dl{
    private:
        node* head;
        int count;
        node* tail;
    public:
        dl(){
            head=nullptr;
            tail=nullptr;
            count=0;
        }

        void insbeg(int val){   //ins first element
            node *newptr= new node{val,nullptr};
             
            if(!head){
                head=tail=newptr;
                head->next=tail;
                tail->next=head;
            }else{
                newptr->next=head;
                head=newptr;       
                tail->next=head;    
            }
            count++;
        }

        void disp(){        // display elemnts
            node *temp;
            int tep=count;
            temp=(node*)malloc(sizeof(node));
            temp=head;
            if(!temp){
                cout << "list empty\n";
            }else{
                while(tep){
                    cout<< temp->data << " ";
                    temp=temp->next;
                    tep--;
                }
                cout<<"\n";
            }
        }     

        void insend(int val){ // ins elemetns in end
            node *temp=head;
            int tep=count;
            while(tep>1){
                temp=temp->next;
                cout<<"hi\n";
                tep--;
            }
            node *newptr= new node{val,nullptr};
            temp->next=newptr;
            tail=newptr;
            tail->next=head;
            count++;
            return;
        }

        void inspos(int val,int pos){       //ins element at pos
            node *temp=head;
            
            if(pos<=1){
                insbeg(val);
                return;
            }
            else if(pos==count){
                insend(val);
                return;
            }else{
                
                int c=1;
                pos--;
                while(pos>c){
                    temp=temp->next;
                    c++;
                }
                
                
                node *newptr= new node{val,temp->next}; 
                temp->next=newptr;
                count++;        
            }
        
        }

        void dltbeg(){ // dlt element in beging
            head=head->next;
            tail->next=head;
            count--;
            
        }

        void dltend(){      //dlt element in end
            node *temp =head;
            int tep=count;
            

            if (tep<=1){
                dltbeg();
                return;
            }else{
             while(tep>2){
                temp=temp->next;
                tep--;
            }
            tail=temp;
            tail->next=head;
            cout<<head->data<<'\n';
            count--;
            
            }
        }

        void dltpos(int pos){
            cout<<count<<"\n";
            if(pos<=1){
                dltbeg();
                return;
            }
            else if(count==pos){
                dltend();
                cout<<"hi\n";
                return;
            }
            else{
                node *temp=head;
                node *temp2;
                while(temp && pos-1>1){
                    temp=temp->next;
                    pos--;
                }
                temp2=temp->next;
                
                temp->next=temp2->next;
                count--;
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