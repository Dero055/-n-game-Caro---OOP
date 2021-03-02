#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include"time.h"
using namespace std;

class _Common {
public:

	static void fixConsoleWindow();
	enum
	{
		KEY_ESC = 27,
		ARROW_UP = 256 + 72,
		ARROW_DOWN = 256 + 80,
		ARROW_LEFT = 256 + 75,
		ARROW_RIGHT = 256 + 77,
		ENTER = 32
	};
	static void gotoXY(int, int);
	static void txtColor(int color);
	static void re_sizeConsole(int width, int height);
	static void X(int x, int y);
	static void O(int x, int y);
	static int Menu(int x, int y);
	static void Introduction(int x, int y);
	static int get_code(void);
	static int Menu1(int, int);
	static int Menu3(int, int);
	static int Menu4(int, int);
	static void menu(int arrow, string menu_options[], int menu_size, int x, int y);
	static void Caro(int X, int Y)
	{
		int _sizeX = 12;
		int _sizeY = 7;
		int Delta = 5;

		int x = X;
		int y = Y;
		//C
		//Tren 
		_Common::txtColor(12);
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y);
			cout << char(219);
		}
		//Trai
		for (int i = 0; i < _sizeY; i++)
		{
			_Common::gotoXY(x, y + i);
			cout << char(219) << char(219);
		}
		//duoi
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y + _sizeY);
			cout << char(219);
		}
		//A
		//trai
		x += _sizeX + Delta - 1;
		for (int i = 0; i < _sizeY + 1; i++)
		{
			_Common::gotoXY(x, y + i);
			cout << char(219) << char(219);
		}
		//tren
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y);
			cout << char(219);
		}
		//phai
		for (int i = 0; i < _sizeY + 1; i++)
		{
			_Common::gotoXY(x + _sizeX, y + i);
			cout << char(219) << char(219);
		}
		//duoi
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y + 3);
			cout << char(219);
		}
		//R
		x += _sizeX + Delta + 1;
		//trai
		for (int i = 0; i < _sizeY + 1; i++)
		{
			_Common::gotoXY(x, y + i);
			cout << char(219) << char(219);
		}
		//tren
		for (int i = 2; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y);
			cout << char(219);
		}
		//phai
		for (int i = 1; i < _sizeY + 1; i++)
		{
			if (i == 3)continue;
			_Common::gotoXY(x + _sizeX, y + i);
			cout << char(219) << char(219);
		}
		//duoi
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y + 3);
			cout << char(219);
		}
		//O
		x += _sizeX + Delta + 1;
		//Tren 
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y);
			cout << char(219);
		}
		//Trai
		for (int i = 0; i < _sizeY; i++)
		{
			_Common::gotoXY(x, y + i);
			cout << char(219) << char(219);
		}
		//duoi
		for (int i = 0; i < _sizeX; i++)
		{
			_Common::gotoXY(x + i, y + _sizeY);
			cout << char(219);
		}
		//phai
		for (int i = 0; i < _sizeY + 1; i++)
		{
			_Common::gotoXY(x + _sizeX - 1, y + i);
			cout << char(219) << char(219);
		}
	}

};