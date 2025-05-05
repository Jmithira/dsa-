#include <iostream>
using namespace std;

class shape{
    private:
        int lenght;
        int breadth;
        int height;
    public:
        shape (int x){
            lenght=x;
            
        }
        shape(int x,int y){
            lenght=x;
            breadth=y;
            
        }
        shape(int x,int y,int z){
            lenght=x;
            breadth=y;
            height=z;
        }
        void square(){
            int area=1;
            area=lenght*lenght;
            cout<<"area of square:"<<area<<'\n';
        }
        void rectangle(){
            int area=1;
            area=lenght*breadth;
            cout<<"area of rectangle:"<<area<<'\n';
        }
        void cube(){
            int area=1;
            area=lenght*lenght*lenght;
            cout<<"area of cube"<<area<<'\n';
        }

};

int main(void){
    bool *con;
    con= (bool*)malloc(sizeof(int));
    *con=true;
    int *choice;
    choice= (int*)malloc(sizeof(int));
    while(*con==true){                //menu driven iteration
        
        int a,b,c;
        
        cout<<"1.square\n";
        cout<<"2.rectangle \n";
        cout<<"3.cube \n";
        cout<<"4.exit \n";
        cout<<"What do you want to do: ";
        cin>>*choice;

        
        if(*choice==1){
                cout<<"Enter side: ";
                cin>>a;
                shape num(a);
                num.square();
                }
         if(*choice==2){
                cout<<"Enter lenght: ";
                cin>>a;
                cout<<"Enter breadth: ";
                cin>>b;
                
                shape num(a,b);
                num.rectangle();
                }
                
         if(*choice==3){
            cout<<"Enter side: ";
                cin>>a;
                shape num(a);
                num.cube();
                
                
         }
         if(*choice==4){
            *con=false;
            
         }
        
    }
}
