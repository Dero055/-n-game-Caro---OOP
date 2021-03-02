#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include"time.h"
#include"_Common.h"
using namespace std;
class _Point {
	int _x, _y, _check;
public:
	_Point();
	_Point(int, int);
	bool setCheck(int);
	int getX();
	int getY();
	int getCheck();
	void setX(int);
	void setY(int);

};