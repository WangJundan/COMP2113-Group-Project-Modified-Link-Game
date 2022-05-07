//in this file we have the main part of the program
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "2113gp.h"

using namespace std;


int board[8][8];
//first we may storing all the map infomation by initializing all the arrays
//initialize map1
int map1[8][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,1,2,3,4,5,6,0},
    {0,7,8,9,1,2,3,0},
    {0,4,5,6,7,8,9,0},
    {0,1,2,3,4,5,6,0},
    {0,7,8,9,1,2,3,0},
    {0,4,5,6,7,8,9,0},
    {0,0,0,0,0,0,0,0}
};

//initialize map2
int map2[8][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,1,7,4,1,7,4,0},
    {0,2,8,5,2,8,5,0},
    {0,3,9,6,3,9,6,0},
    {0,4,1,7,4,1,7,0},
    {0,5,2,8,5,2,8,0},
    {0,6,3,9,6,3,9,0},
    {0,0,0,0,0,0,0,0}
};

//initialize map3
int map3[8][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,1,2,3,4,5,6,0},
    {0,4,5,6,7,8,9,0},
    {0,1,2,3,4,5,6,0},
    {0,7,8,9,1,2,3,0},
    {0,7,8,9,1,2,3,0},
    {0,4,5,6,7,8,9,0},
    {0,0,0,0,0,0,0,0}
};

//initialize map4
int map4[8][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,1,2,3,4,5,6,0},
    {0,1,2,3,4,5,6,0},
    {0,7,8,9,1,2,3,0},
    {0,4,5,6,7,8,9,0},
    {0,7,8,9,1,2,3,0},
    {0,4,5,6,7,8,9,0},
    {0,0,0,0,0,0,0,0}
};

//initialize map5
int map5[8][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,6,3,9,6,3,9,0},
    {0,1,7,4,1,7,4,0},
    {0,2,8,5,2,8,5,0},
    {0,3,9,6,3,9,6,0},
    {0,4,1,7,4,1,7,0},
    {0,5,2,8,5,2,8,0},
    {0,0,0,0,0,0,0,0}
};



int main(){
    //check whether the last game is finished. If not, then continue the last round. If finished, then start a new game.
    ifstream ifs("data.txt",ios::in);
    char ch;
    ifs>>ch;
    //count the number of times that the player use the super remove button
    int numofsv=0;
    //if finished, then the gamestatus file should be empty. Thus start a new game.
    if(ifs.eof()){
        ifs.close();
        int number;
        //first input a number to choose the map
        cout << "Enter a number from 1 to 5 to choose a map: "<<endl;
        cin >> number;
        //while loop here for avoiding invalid input
        while (number != 1 && number != 2 && number != 3 && number != 4 && number != 5){
            cout << "Invalid input. Please enter a number from 1 to 5 agian to choose a map: "<<endl;
            cin >> number;
        }

            if (number==1){
                for (int i = 0; i<8; i++ ){
                    for (int j = 0; j<8; j++){
                        board[i][j]=map1[i][j];
                    }
                }
            }

            else if (number==2){
                for (int i = 0; i<8; i++ ){
                    for (int j = 0; j<8; j++){
                        board[i][j]=map2[i][j];
                    }
                }
            }

            else if (number==3){
                for (int i = 0; i<8; i++ ){
                    for (int j = 0; j<8; j++){
                        board[i][j]=map3[i][j];
                    }
                }
            }

            else if (number==4){
                for (int i = 0; i<8; i++ ){
                    for (int j = 0; j<8; j++){
                        board[i][j]=map4[i][j];
                    }
                }
            }

            else if (number==5){
                for (int i = 0; i<8; i++ ){
                    for (int j = 0; j<8; j++){
                        board[i][j]=map5[i][j];
                    }
                }
            }
            ofstream out("data.txt");
            for(int i=0;i<8;i++){
                for(int j=0;j<7;j++){
                    out<<board[i][j]<<' ';
                }
                out<<board[i][7];
                out << endl;
            }
            out.close();



    }
    else{
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                ifs>>board[i][j];

            }

        }
        ifs.close();


    }

    printboard(board);



    //then start play the link game
    //while loop here to examine when finish the game
    while ( finishornot (board)==false ){
        int x1, x2, y1, y2;
        cout<<"Please input two locations you want to operate in this 6*6 board."<<endl;
        cout<<"each number should be between 1 and 6."<<endl;
        cout<<"location 1: (first row then column)"<<endl;
        cin>>x1>>y1;
        cout<<"location 2: (first row then column)"<<endl;
        cin>>x2>>y2;

        //when the input is 0,0,0,9, then generate a random number and elimate all of this number in the map (super remove operation)
        if (x1==0 && y1==0 && x2==0 && y2==9){
            int key = rand()% 9 + 1;

            //add a random punishment for using super-remove.
            numofsv += 1;
            int k=0;
            //k use to judge whether to conduct punishment.
            //If there exist p[i] larger than 7, the punishment will be imposed. Every time using super remove, the player will increase the risk of intriguing punishment.
           //the puniment is fill in all the 0 in the board with key value
            int * p = new int [numofsv];
            for (int i = 0; i < numofsv; ++i) {
                p[i] = rand()% 9 + 1;
            }

            for (int i=1; i< numofsv; i++) {
                if (p[i] > 7){
                    k=1;
                }
            }

            if( k==1 ){
                cout<<"HA HA! This is the punishment for U!"<<endl;
                for (int i=1; i<7; i++){
                    for (int j=1; j<7; j++){
                        if (board[i][j]==0){
                            board[i][j]=key;
                        }
                    }
                }
                //store the change in the file
                ofstream out("data.txt");
                for(int i=0;i<8;i++){
                    for(int j=0;j<7;j++){
                        out<<board[i][j]<<' ';
                    }
                    out<<board[i][7];
                    out << endl;
                }
                out.close();
                printboard(board);
            }

            if( k==0 ) {
                cout<<"We would super-remove the number "<< key <<endl;
                for (int i=1; i<7; i++){
                    for (int j=1; j<7; j++){
                        if (board[i][j]==key){
                            board[i][j]=0;
                        }
                    }
                }
            //store the change in the file
                ofstream out("data.txt");
                for(int i=0;i<8;i++){
                    for(int j=0;j<7;j++){
                        out<<board[i][j]<<' ';
                    }
                    out<<board[i][7];
                    out << endl;
                }
                out.close();
                printboard(board);
            }
        }


        //when the input is not 0,0,0,9 and is also valid, check if the 2 coordinates can be legally eliminated.
        else if (checkvalid(x1, y1, x2, y2)==true){
            //if it is legal, implement the elimination
            if (iflegal (board, x1, y1, x2, y2)==true){
                board[x1][y1]=0;
                board[x2][y2]=0;
                cout<<"Bingo! Successful elimination!"<<endl;
                ofstream out("data.txt");
                for(int i=0;i<8;i++){
                    for(int j=0;j<7;j++){
                        out<<board[i][j]<<' ';
                    }
                    out<<board[i][7];
                    out << endl;
                }
                out.close();
                printboard(board);
            }
            //if not, do nothing to the map and recurse the while loop again
            else{
                cout<<"OH NO! Try Again"<<endl;
            }
        }
        else{
            cout<<"Invalid coordinates input QwQ. Please re-input the location."<<endl;
        }

    }
      cout<<"Congratulate for passing the game! owo"<<endl;
      //when the game is finished, delete the gamestatus file to make it empty
      ofstream delete1;
      delete1.open("data.txt");
      delete1.close();
      return 0;
}
