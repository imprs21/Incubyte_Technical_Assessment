#include<bits/stdc++.h>
using namespace std;

class ch3{

    int x,y,z;
    char direction;

    public:
        ch3(){
            x=y=z=0;
            direction='O';
        }

        ch3(int a,int b,int c,char ch){
            x=a;
            y=b;
            z=c;
            direction=ch;
        }

        int get_x(){
            return x;
        }

        int get_y(){
            return y;
        }

        int get_z(){
            return z;
        }

        char get_direction(){
            return direction;
        }

        void add_to_x(int a){
            x+=a;
        }

        void add_to_y(int a){
            y+=a;
        }

        void add_to_z(int a){
            z+=a;
        }

        void set_direction(char a){
            direction=a;
        }

        void print_final_status(){
            cout<<"Final Coordinates : "<<"("<<x<<","<<y<<","<<z<<")"<<endl;
            cout<<"Final Direction : "<<direction<<endl;
        }
};


int main(){

    cout<<"Enter initial coordinates(x,y,z)"<<endl;
    int a,b,c;
    cout<<"Enter x coordinate : ";
    cin>>a;
    cout<<"Enter y coordinate : ";
    cin>>b;
    cout<<"Enter z coordinate : ";
    cin>>c;

    char ch,temp;
    cout<<"Enter initial direction : ";
    cin>>ch;

    ch3 obj(a,b,c,ch);

    cout<<"Enter commnads and enter 0 after inputting all commands to terminate taking input : "<<endl;

    vector<char> commands;

    while(1){
        cin>>ch;
        if(ch=='0'){
            break;
        }

        else{
            commands.push_back(ch);
        }
    }


    for(char c: commands){

        switch (c)
        {
        case 'u':
            obj.set_direction('U');
            break;

        case 'd':
            obj.set_direction('D');
            break;

        case 'l':
            temp=obj.get_direction();
            if(temp=='N'){
                obj.set_direction('W');
            }
            else if(temp=='E'){
                obj.set_direction('N');
            }
            else if(temp=='S'){
                obj.set_direction('E');
            }
            else if(temp=='W'){
                obj.set_direction('S');
            }
            else if(temp=='U'){
                obj.set_direction('N');
            }
            else if(temp=='D'){
                obj.set_direction('S');
            }
            break;

        case 'r':

            temp=obj.get_direction();
            if(temp=='N'){
                obj.set_direction('E');
            }
            else if(temp=='E'){
                obj.set_direction('S');
            }
            else if(temp=='S'){
                obj.set_direction('W');
            }
            else if(temp=='W'){
                obj.set_direction('N');
            }
            else if(temp=='U'){
                obj.set_direction('S');
            }
            else if(temp=='D'){
                obj.set_direction('N');
            }
            break;

        case 'f':

            temp=obj.get_direction();

            if(temp=='N'){
                obj.add_to_y(1);
            }
            else if(temp=='E'){
                obj.add_to_x(1);
            }
            else if(temp=='S'){
                obj.add_to_y(-1);
            }
            else if(temp=='W'){
                obj.add_to_x(-1);
            }
            else if(temp=='U'){
                obj.add_to_z(1);
            }
            else if(temp=='D'){
                obj.add_to_z(-1);
            }

            break;

        case 'b':
            temp=obj.get_direction();

            if(temp=='N'){
                obj.add_to_y(-1);
            }
            else if(temp=='E'){
                obj.add_to_x(-1);
            }
            else if(temp=='S'){
                obj.add_to_y(1);
            }
            else if(temp=='W'){
                obj.add_to_x(1);
            }
            else if(temp=='U'){
                obj.add_to_z(-1);
            }
            else if(temp=='D'){
                obj.add_to_z(1);
            }

        
        default:
            break;
        }

        
    }

    cout<<"\nFinal Configuraton of Chandrayaan3\n"<<endl;

    obj.print_final_status();









}