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


int _Common::get_code(void)
{
	int ch = _getch();

	if (ch == 0 || ch == 224)
		ch = 256 + _getch();

	return ch;
}
void _Common::menu(int arrow, string menu_options[], int menu_size, int x, int y)
{
	int i;

	for (i = 0; i < menu_size; i++) {
		_Common::txtColor(12);
		_Common::gotoXY(x, y + i);
		if (i == arrow)
		{
			_Common::txtColor(5);
			cout << "-->";
			cout << menu_options[i] << endl;;
		}
		else
			// printf(" ");
			cout << menu_options[i] << "                                      " << endl;;
	}
}
int _Common::Menu(int X, int Y)
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
	Sleep(500);
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
	Sleep(500);
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
	Sleep(500);
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
	Sleep(100);
	_Common::gotoXY(X + 30, y + _sizeY + 4);
	int action;
	int arrow = 0;
	string menu_option[5] = { "1.Play","2.Load Game","3.Sound", "4.Introduction","5.Exit" };
	int menu_size = 5;
	_Common::menu(arrow, menu_option, menu_size, X + 30, y + _sizeY + 4);
	while ((action = get_code()) != KEY_ESC)
	{
		switch (action)
		{
		case ARROW_UP:
			if (--arrow < 0)
				arrow = menu_size - 1;
			break;
		case ARROW_DOWN:
			if (++arrow == menu_size)
				arrow = 0;
			break;
		case '\r':
			//system("cls");
			return arrow + 1;
			break;
		default:
			break;
		}
		//system("cls");
		//_Common::Caro(X, Y);
		_Common::gotoXY(X + 30, y + _sizeY + 4);
		_Common::menu(arrow, menu_option, menu_size, X + 30, y + _sizeY + 4);
	}
	/*
		cout << "1.Người Vs Người";
	_Common::gotoXY(X + 30, y + _sizeY + 6);
	cout << "2.Exit";
	_Common::gotoXY(X + 30, y + _sizeY + 8);
	cout << "3.Introduction";
	_Common::gotoXY(X + 30, y + _sizeY + 10);
	cout << "4.Load Game";
	_Common::gotoXY(X + 30, y + _sizeY + 12);
	cout << "5.Người Vs Com";
	*/

}
int _Common::Menu1(int X, int Y)
{
	int _sizeX = 12;
	int _sizeY = 7;
	int Delta = 5;

	int x = X;
	int y = Y;

	_Common::gotoXY(X + 30, y + _sizeY + 4);
	int action;
	int arrow = 0;
	int i;

	for (i = 0; i < 5; i++) {
		_Common::gotoXY(X + 30, y + _sizeY + 4 + i);
		cout << "                                         " << endl;

	}
	string menu_option[2] = { "1.X vs O","2.Vs Com" };
	int menu_size = 2;
	_Common::menu(arrow, menu_option, menu_size, X + 30, y + _sizeY + 4);
	while ((action = get_code()) != KEY_ESC)
	{
		switch (action)
		{
		case ARROW_UP:
			if (--arrow < 0)
				arrow = menu_size - 1;
			break;
		case ARROW_DOWN:
			if (++arrow == menu_size)
				arrow = 0;
			break;
		case '\r':
			//system("cls");
			return arrow + 1;
			break;
		default:
			break;
		}
		//system("cls");
		//_Common::Caro(X, Y);
		_Common::gotoXY(X + 30, y + _sizeY + 4);
		_Common::menu(arrow, menu_option, menu_size, X + 30, y + _sizeY + 4);
	}

}
int _Common::Menu3(int X, int Y)
{
	int _sizeX = 12;
	int _sizeY = 7;
	int Delta = 5;

	int x = X;
	int y = Y;

	_Common::gotoXY(X + 30, y + _sizeY + 4);
	int action;
	int arrow = 0;
	int i;

	for (i = 0; i < 5; i++) {
		_Common::gotoXY(X + 30, y + _sizeY + 4 + i);
		cout << "                                         " << endl;

	}
	string menu_option[3] = { "1.On","2.Off","3. Return Menu" };
	int menu_size = 3;
	_Common::menu(arrow, menu_option, menu_size, X + 30, y + _sizeY + 4);
	while ((action = get_code()) != KEY_ESC)
	{
		switch (action)
		{
		case ARROW_UP:
			if (--arrow < 0)
				arrow = menu_size - 1;
			break;
		case ARROW_DOWN:
			if (++arrow == menu_size)
				arrow = 0;
			break;
		case '\r':
			//system("cls");
			return arrow + 1;
			break;
		default:
			break;
		}
		//system("cls");
		//_Common::Caro(X, Y);
		_Common::gotoXY(X + 30, y + _sizeY + 4);
		_Common::menu(arrow, menu_option, menu_size, X + 30, y + _sizeY + 4);
	}

}
int _Common::Menu4(int X, int Y)
{
	int _sizeX = 12;
	int _sizeY = 7;
	int Delta = 5;

	int x = X;
	int y = Y;

	_Common::gotoXY(X + 30, y + _sizeY + 4);
	int action;
	int arrow = 0;
	int i;

	for (i = 0; i < 5; i++) {
		_Common::gotoXY(X + 30, y + _sizeY + 4 + i);
		cout << "                                         " << endl;

	}
	_Common::gotoXY(X + 20, y + _sizeY + 4);
	cout << "Nguoi thuc hien: Nguyen Do Chi Thao";
	_Common::gotoXY(X + 20, y + _sizeY + 5);
	cout << "		MSSV: 1712159			    ";
	_Common::gotoXY(X + 20, y + _sizeY + 6);
	cout << "***********************************";

	_Common::gotoXY(4, y + _sizeY + 9);
	cout << "Huong dan: ";
	_Common::gotoXY(4, y + _sizeY + 10);
	cout << "Ban hay su dung 4 phim A: qua trai, D: qua phai, S: di xuong, W: di len";
	_Common::gotoXY(4, y + _sizeY + 11);
	cout << "Neu ban dat duoc 5 quan tren mot duong thang ma khong bi chan hai dau, ban se chien thang";
	_Common::gotoXY(X + 30, y + _sizeY + 12);
	string menu_option[1] = { "Menu" };
	int menu_size = 1;
	_Common::menu(arrow, menu_option, menu_size, 4, y + _sizeY + 12);
	while ((action = get_code()) != KEY_ESC)
	{
		switch (action)
		{
		case ARROW_UP:
			if (--arrow < 0)
				arrow = menu_size - 1;
			break;
		case ARROW_DOWN:
			if (++arrow == menu_size)
				arrow = 0;
			break;
		case '\r':
			//system("cls");
			return arrow + 1;
			break;
		default:
			break;
		}
		//system("cls");
		//_Common::Caro(X, Y);
		_Common::gotoXY(X + 30, y + _sizeY + 4);
		_Common::menu(arrow, menu_option, menu_size, 4, y + _sizeY + 12);
	}

}
void _Common::Introduction(int x, int y)
{
	_Common::gotoXY(x, y);
	cout << "Su dung 4 phim A: " << char(17) << "D: " << char(16) << "S: " << char(31) << "W: " << char(30) << endl;
}

void _Common::O(int x, int y)
{
	_Common::gotoXY(x, y);
	cout << "==========================";
	_Common::gotoXY(x, y + 1);
	cout << "==========================";
	_Common::gotoXY(x, y + 2);
	cout << "==========================";
	_Common::gotoXY(x, y + 3);
	cout << "=======            =======";
	_Common::gotoXY(x, y + 4);
	cout << "=======            =======";
	_Common::gotoXY(x, y + 5);
	cout << "=======            =======";
	_Common::gotoXY(x, y + 6);
	cout << "=======            =======";
	_Common::gotoXY(x, y + 7);
	cout << "=======            =======";
	_Common::gotoXY(x, y + 8);
	cout << "==========================";
	_Common::gotoXY(x, y + 9);
	cout << "==========================";
	_Common::gotoXY(x, y + 10);
	cout << "==========================";
}

void _Common::txtColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void _Common::gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void _Common::X(int x, int y)
{
	_Common::gotoXY(x, y);
	cout << "========          ========";
	_Common::gotoXY(x + 2, y + 1);
	cout << "========      ========";
	_Common::gotoXY(x + 4, y + 2);
	cout << "========  ========";
	_Common::gotoXY(x + 6, y + 3);
	cout << "==============";
	_Common::gotoXY(x + 8, y + 4);
	cout << "==========";
	_Common::gotoXY(x + 9, y + 5);
	cout << "========";
	_Common::gotoXY(x + 8, y + 6);
	cout << "==========";
	_Common::gotoXY(x + 6, y + 7);
	cout << "==============";
	_Common::gotoXY(x + 4, y + 8);
	cout << "========  ========";
	_Common::gotoXY(x + 2, y + 9);
	cout << "========      ========";
	_Common::gotoXY(x, y + 10);
	cout << "========          ========";

}
void _Common::re_sizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void _Common::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}