#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include"time.h"
#include"_Common.h"
#include"_Point.h"
using namespace std;
class _Board {
private:
	int _size;
	int _left, _top;
	_Point** _pArr;
public:
	int get_size();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	_Board(int, int, int);
	~_Board();
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard(int, int);
	void saveGame();
	void loadGame();
	_Point* findBestMove();
	long Diem_TC_Doc(int x, int y);
	long Diem_TC_Ngang(int, int);
	long Diem_TC_CheoNguoc(int, int);
	long Diem_TC_CheoChinh(int, int);
	long Diem_PT_Doc(int x, int y);
	long Diem_PT_Ngang(int, int);
	long Diem_PT_CheoNguoc(int, int);
	long Diem_PT_CheoChinh(int, int);
	_Point Random();
	//long Mangdiemtancong[13] = { 0,3,15,75,375,1875,9375,46875,234375,1171875,5859375,29296875,146484375 };
	//long Mangdiemphongthu[13] = { 0,1, 6,36,216,1296,7776,46656,279936,1679616,10077696,604666176,362797056 };
	//long Mangdiemphongthu[13] = { 0,1, 9, 81, 729, 6561,59049,531441,4782969,43046721,387420489,387420489,387420489 };
	//long Mangdiemtancong[13] = { 1,3,5,7,9,11,13,15,17,19,21,23,25 };
	//long Mangdiemphongthu[13] = { 2,4,6,8,10,12,14,16,18,20,22,24,26 };

	long Mangdiemphongthu[13] = { 0,3,24,192,1536,12288,98304,786432,6291456,50331648,402653184,402653184,402653184};
	long Mangdiemtancong[13] ={0,1, 9, 81, 729, 6561,59049,531441,4782969,43046721,387420489,387420489,387420489 };
	

	//long Mangdiemphongthu[13] = { 1, 6,36,216,1296,7776,46656,279936,1679616,10077696,604666176,362797056,362797056 };
	//long Mangdiemtancong[13] = {0,3,24,192,1536,12288,98304,786432,6291456,50331648,402653184,402653184,402653184 };
	//long Mangdiemphongthu[13] ={0,1, 9, 81, 729, 6561,59049,531441,4782969,43046721,387420489,387420489,387420489 };
	//long Mangdiemtancong[13] = { 0,1, 6,36,216,1296,7776, 46656, 279936, 1679616, 10077696, 604666176,362797056 };
	//long Mangdiemphongthu[13] = { 0,1, 9,81,729,6561,59049,531441,4782969,43046721,387420489,387420489,387420489 };

};