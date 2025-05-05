#include <iostream>
using namespace std;

struct node{
    int time;
    struct node* next;
};

class dl{
    private:
        node* head;
        int timequantum;
        node* tail;
        int count;
    public:
        dl(int tc){
            head=nullptr;
            tail=nullptr;
            timequantum=tc;
            count=0;
        }

        void insend(int val){ // ins elemetns in end
            
            node *newptr= new node{val,nullptr};
            if(!head){
                head=tail=newptr;
                cout << "Process added with time: " << val << " ms\n";
                count++;
                return;
            }
            node *temp=head;
            int tep=count;
            while(tep>1){
                temp=temp->next;
                cout<<"hi\n";
                tep--;
            }
            
            
            temp->next=newptr;
            tail=newptr;
            tail->next=head;
            count++;
            cout << "Process added with time: " << val << " ms\n";
            return;
        }


        void execute(){
            if(!head){
                cout<<"lsit emoty\n";
                
                return;
            }
            if(head->time>timequantum){
                head->time-=timequantum;
                cout<<"remainging time:"<<head->time<<"added to queue"<<'\n';
                insend(head->time);
                head=head->next;
                tail->next=head;
                count--;
                
                return;
            }else{
                 cout << "Process executed succefull\n";
                if(head==tail){
                    head=tail=nullptr;
                    count--;
                    
                    return;
                }else{
                    head=head->next;
                    tail->next=head;
                    count--;
                    
                }
            }

        }
};