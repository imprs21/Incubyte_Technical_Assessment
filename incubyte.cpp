#include<bits/stdc++.h>
using namespace std;



//class representing chandrayaan3 
class ch3{

    int x,y,z;
    char direction;

    public:
        ch3(){
            x=y=z=0;
            direction='O';
        }

        //paramaterised constructor to set the values of the instance of ch3 class
        ch3(int a,int b,int c,char ch){
            x=a;
            y=b;
            z=c;
            direction=ch;
        }


        //method to get x-coordinate of chandrayaan3
        int get_x(){
            return x;
        }


        //method to get y-coordinate of chandrayaan3
        int get_y(){
            return y;
        }

        //method to get x-coordinate of chandrayaan3
        int get_z(){
            return z;
        }


        //method to get direction of chandrayaan3
        char get_direction(){
            return direction;
        }


        //method to add passed value to x-coordinate
        void add_to_x(int a){
            x+=a;
        }


        //method to add passed value to y-coordinate
        void add_to_y(int a){
            y+=a;
        }


        //method to add passed value to z-coordinate
        void add_to_z(int a){
            z+=a;
        }


        //method to change the direction of chandrayaan3 based of the command received
        void set_direction(char a){
            direction=a;
        }

        //method to print configuration of chandrayaan3
        void print_status(){
            cout<<"Coordinates : "<<"("<<x<<","<<y<<","<<z<<")"<<endl;
            cout<<"Direction : "<<direction<<endl;
        }
};


int main(){

    //Taking initial input of the chandrayaan3
    cout<<"Enter initial coordinates(x,y,z)"<<endl;
    int a,b,c;
    cout<<"Enter x coordinate : ";
    cin>>a;
    cout<<"Enter y coordinate : ";
    cin>>b;
    cout<<"Enter z coordinate : ";
    cin>>c;

    //Taking initial direction
    char ch,temp;
    cout<<"Enter initial direction : ";
    cin>>ch;

    //Creating object of the custom datatype ch3
    ch3 obj(a,b,c,ch);


    //Taking the commands
    cout<<"Enter commnads and 0 to end taking commnads : "<<endl;

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


    //Iterating over commands array to perform calculation and updating the configuration of the chandrayaan3
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

        cout<<"\n\nAfter Command \""<<c<<"\" configuration is : "<<endl;
        obj.print_status();
        cout<<"\n\n";

        
    }

    cout<<"\nFinal Configuraton of Chandrayaan3\n"<<endl;

    obj.print_status();

    return 0;

}


/*

    *************************************OUTPUT****************************************


    
    *************************************INPUT1****************************************
    PS D:\DS\Placements\Codes\Incubyte> cd "d:\DS\Placements\Codes\Incubyte\\incubyte }
    Enter initial coordinates(x,y,z)
    Enter x coordinate : 0
    Enter y coordinate : 0
    Enter z coordinate : 0
    Enter initial direction : N
    Enter commnads and 0 to end taking commnads : 
    f
    r
    u
    b
    l
    0


    After Command "f" configuration is :
    Coordinates : (0,1,0)
    Direction : N




    After Command "r" configuration is :
    Coordinates : (0,1,0)
    Direction : E




    After Command "u" configuration is :
    Coordinates : (0,1,0)
    Direction : U




    After Command "b" configuration is :
    Coordinates : (0,1,-1)
    Direction : U




    After Command "l" configuration is :
    Coordinates : (0,1,-1)
    Direction : N



    Final Configuraton of Chandrayaan3

    Coordinates : (0,1,-1)
    Direction : N


    ***************************************INPUT 2**************************************
    PS D:\DS\Placements\Codes\Incubyte> cd "d:\DS\Placements\Codes\Incubyte\\incubyte }
    Enter initial coordinates(x,y,z)
    Enter x coordinate : -1
    Enter y coordinate : -1
    Enter z coordinate : -1
    Enter initial direction : S
    Enter commnads and 0 to end taking commnads : 
    f
    l
    r
    u
    b
    d
    0


    After Command "f" configuration is :
    Coordinates : (-1,-2,-1)
    Direction : S




    After Command "l" configuration is :
    Coordinates : (-1,-2,-1)
    Direction : E




    After Command "r" configuration is :
    Coordinates : (-1,-2,-1)
    Direction : S




    After Command "u" configuration is :
    Coordinates : (-1,-2,-1)
    Direction : U




    After Command "b" configuration is :
    Coordinates : (-1,-2,-2)




    After Command "d" configuration is :
    Coordinates : (-1,-2,-2)
    Direction : D



    Final Configuraton of Chandrayaan3

    Coordinates : (-1,-2,-2)
    Direction : D
*/