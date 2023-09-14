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
    char ch,current_direction,prev_direction;
    cout<<"Enter initial direction (from N,S,E,W,U,D) in uppercase as a single character : ";
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

        else if(ch=='f' || ch=='b' || ch=='u' || ch=='d'|| ch=='l' || ch=='r'){
            commands.push_back(ch);
        }
        else{
            cout<<"\nNot a valid command"<<endl;
        }
    }


    //Iterating over commands array to perform calculation and updating the configuration of the chandrayaan3
    for(char c: commands){

        switch (c)
        {
        case 'u':
            prev_direction=obj.get_direction();
            obj.set_direction('U');
            break;

        case 'd':
            prev_direction=obj.get_direction();
            obj.set_direction('D');
            break;

        case 'l':
            current_direction=obj.get_direction();
            if(current_direction=='N'){
                obj.set_direction('W');
            }
            else if(current_direction=='E'){
                obj.set_direction('N');
            }
            else if(current_direction=='S'){
                obj.set_direction('E');
            }
            else if(current_direction=='W'){
                obj.set_direction('S');
            }
            else if(current_direction=='U'){
                if(prev_direction=='E'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('W');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('E');
                }
            }
            else if(current_direction=='D'){
                if(prev_direction=='E'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('W');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('E');
                }
            }
            break;

        case 'r':

            current_direction=obj.get_direction();
            if(current_direction=='N'){
                obj.set_direction('E');
            }
            else if(current_direction=='E'){
                obj.set_direction('S');
            }
            else if(current_direction=='S'){
                obj.set_direction('W');
            }
            else if(current_direction=='W'){
                obj.set_direction('N');
            }
            else if(current_direction=='U'){
                if(prev_direction=='E'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('E');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('W');
                }
            }
            else if(current_direction=='D'){

                if(prev_direction=='E'){
                    obj.set_direction('S');
                }
                else if(prev_direction=='N'){
                    obj.set_direction('E');
                }
                else if(prev_direction=='W'){
                    obj.set_direction('N');
                }
                else if(prev_direction=='S'){
                    obj.set_direction('W');
                }
            }
            break;

        case 'f':

            current_direction=obj.get_direction();

            if(current_direction=='N'){
                obj.add_to_y(1);
            }
            else if(current_direction=='E'){
                obj.add_to_x(1);
            }
            else if(current_direction=='S'){
                obj.add_to_y(-1);
            }
            else if(current_direction=='W'){
                obj.add_to_x(-1);
            }
            else if(current_direction=='U'){
                obj.add_to_z(1);
            }
            else if(current_direction=='D'){
                obj.add_to_z(-1);
            }

            break;

        case 'b':
            current_direction=obj.get_direction();

            if(current_direction=='N'){
                obj.add_to_y(-1);
            }
            else if(current_direction=='E'){
                obj.add_to_x(-1);
            }
            else if(current_direction=='S'){
                obj.add_to_y(1);
            }
            else if(current_direction=='W'){
                obj.add_to_x(1);
            }
            else if(current_direction=='U'){
                obj.add_to_z(-1);
            }
            else if(current_direction=='D'){
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
    PS D:\DS\Placements\Codes\Incubyte> cd "d:\DS\Placements\Codes\Incubyte\" ; if ($?) { g++ incubyte.cpp -o incubyte } ; if ($?) { .\incubyte }
    Enter initial coordinates(x,y,z)
    Enter x coordinate : 0
    Enter y coordinate : 0
    Enter z coordinate : 0
    Enter initial direction (from N,S,E,W,U,D) in uppercase as a single character : N
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




    After Command "l" configuration is :
    Coordinates : (0,1,-1)
    Direction : N



    Final Configuraton of Chandrayaan3

    Coordinates : (0,1,-1)
    Direction : N
    PS D:\DS\Placements\Codes\Incubyte> cd "d:\DS\Placements\Codes\Incubyte\" ; if ($?) { g++ incubyte.cpp -o incubyte } ; if ($?) { .\incubyte }
    Enter initial coordinates(x,y,z)
    Enter x coordinate : -1
    Enter y coordinate : -1
    Enter z coordinate : -1
    Enter initial direction (from N,S,E,W,U,D) in uppercase as a single character : S
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
    Direction : U




    After Command "d" configuration is :
    Coordinates : (-1,-2,-2)
    Direction : D



    Final Configuraton of Chandrayaan3

    Coordinates : (-1,-2,-2)
    Direction : D
*/