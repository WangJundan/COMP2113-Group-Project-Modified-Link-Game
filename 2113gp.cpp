//in this file, we define all the functions needed
#include <iostream>
#include "2113gp.h"
using namespace std;


//check if the input is valid
bool checkvalid(int x1, int y1, int x2, int y2){
  if (x1==x2 && y1==y2) {
    return false;
  }
  else if (x1>6 ||x2>6 ||x1>6 ||x1>6 ||x1<1 ||x2<1 ||y1<1 ||y2<1 ){
    return false;
    
  }
  else{
    return true;
  }
}

// check whether straightly linked by x axis
// bool xlinked donot check whether the number[][] are the same
bool xlinked (int board[][8], int x1, int y1, int x2, int y2){
  if (x1 == x2 && y1 < y2) {
    if (y1+1==y2)
      return true;
    for (int y = y1+1; y < y2; y++) {
      if (board[x1][y]!=0)
        return false;
    }
      return true;
  }

  if (x1 == x2 && y1 > y2) {
    if (y2+1==y1)
      return true;
    for (int y = y2+1; y < y1; y++){
      if (board[x1][y]!=0)
        return false;
    }
      return true;
  }
  else
   return false;
}

// check whether straightly linked by y axis
bool ylinked (int board[][8], int x1, int y1, int x2, int y2){
  if (y1 == y2 && x1 < x2) {
    if (x1+1==x2)
     return true;
    for (int x = x1+1; x < x2; x++) {
      if (board[x][y1]!=0)
        return false;
    }
      return true;
  }

  if (y1 == y2 && x1 > x2) {
    if (x2+1==x1)
     return true;
    for (int x = x2+1; x < x1; x++){
      if (board[x][y1]!=0)
        return false;
    }
      return true;
  }
  else
    return false;
}

// check if a straight line can link
bool zeroturnlinked (int board[][8], int x1, int y1, int x2, int y2) {
  if  (board[x1][y1]==board[x2][y2]) {
    if (xlinked (board, x1, y1, x2, y2)==true|| ylinked (board, x1, y1, x2, y2)==true)
      return true;
    else
      return false;
  }
  else
   return false;
}

// check if one turn can link
bool oneturnlinked (int board[][8], int x1, int y1, int x2, int y2){
  if (board[x1][y1]==board[x2][y2]){
  if (xlinked (board, x1, y1, x1, y2)==true && ylinked (board, x2, y2, x1, y2)==true &&board[x1][y2]==0 )
    return true;
  else if (ylinked (board, x1, y1, x2, y1)==true && xlinked (board, x2, y2, x2, y1)==true  &&board[x2][y1]==0)
    return true;
  else
    return false;
  }
  return false;
}

// check if two turns can link
bool twoturnslinked (int board[][8], int x1, int y1, int x2, int y2){
  if (board[x1][y1]==board[x2][y2]){
  for (int i=0; i<=7; i++){
    if (xlinked (board, x1, y1, x1, i)==true && xlinked (board, x2, y2, x2, i)==true && ylinked (board, x1, i, x2, i)==true && board[x1][i]==0 && board[x2][i]==0)
      return true;
    else if (ylinked (board, x1, y1, i, y1)==true && ylinked (board, x2, y2, i, y2)==true && xlinked (board, i, y1, i, y2)==true && board[i][y1]==0 && board[i][y2]==0)
      return true;
    else
      continue;}
    return false;
  }
  return false;
}


// check if these two coordinates could be eliminated legally
bool iflegal (int board[][8], int x1, int y1, int x2, int y2){
  if (zeroturnlinked (board, x1, y1, x2, y2)==true){
    return true;
  }
  else if (oneturnlinked (board, x1, y1, x2, y2)==true){
    return true;
  }
  else if (twoturnslinked (board, x1, y1, x2, y2)==true){
    return true;
  }
  else{
    return false;
  }
}


//function used to print the array whose elements are int
void printboard(int board[][8]) {
  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      if (j < 7)
        cout<<board[i][j]<<" ";
      if (j==7)
        cout<<board[i][j]<<endl;
    }
  }

}
