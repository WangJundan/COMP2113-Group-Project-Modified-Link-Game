//in this header file we declare the functions needed
#ifndef _2113GP_H_
#define _2113GP_H_


void printlocation (int x1, int y1, int x2, int y2);
bool finishornot (int board[][8]);
bool checkvalid(int x1, int y1, int x2, int y2);
bool xlinked (int board[][8], int x1, int y1, int x2, int y2);
bool ylinked (int board[][8], int x1, int y1, int x2, int y2);
bool zeroturnlinked (int board[][8], int x1, int y1, int x2, int y2);
bool oneturnlinked (int board[][8], int x1, int y1, int x2, int y2);
bool twoturnslinked (int board[][8], int x1, int y1, int x2, int y2);
bool iflegal (int board[][8], int x1, int y1, int x2, int y2);
void printboard(int board[][8]);


#endif