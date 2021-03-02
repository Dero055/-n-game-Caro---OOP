#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include"time.h"
#include"_Common.h"
#include"_Point.h"
#include"_Board.h"
using namespace std;

int _Board::get_size() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }
int _Board::getXAt(int i, int j) { return _pArr[i][j].getX(); }
int _Board::getYAt(int i, int j) { return _pArr[i][j].getY(); }
_Board::_Board(int p_size, int pX, int pY) {
	_size = p_size;
	_left = pX;
	_top = pY;
	_pArr = new _Point*[p_size];
	for (int i = 0; i < p_size; i++) _pArr[i] = new _Point[p_size];

}
void _Board::saveGame()
{
	ofstream f;
	f.open("Game.txt");
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
			f << _pArr[i][j].getX() << " " << _pArr[i][j].getY() << " " << _pArr[i][j].getCheck() << endl;

	}
	f.close();
}
void _Board::loadGame()
{
	ifstream f;
	f.open("Game.txt");
	int x, y, mark;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			f >> x >> y >> mark;
			_pArr[i][j].setX(x);
			_pArr[i][j].setY(y);
			_pArr[i][j].setCheck(mark);
			_Common::gotoXY(x, y);
			_Common::txtColor(12);
			if (mark == -1) cout << "X";
			if (mark == 1) cout << "O";
		}
	}


	f.close();
}
_Board::~_Board()
{
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}
void _Board::resetData() {
	if (_size == 0) return; // Phải gọi constructor trước khi resetData
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ
			_pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ
			_pArr[i][j].setCheck(0);

		}

	}

}
void _Board::drawBoard() {
	if (_pArr == NULL) return; // phải gọi constructor trước
	/*for (int i = 0; i <= _size; i++) {
		for (int j = 0; j <= _size; j++) {
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			printf(".");

		}
		*/
	_Common::txtColor(3);
	for (int i = 0; i <= _size; i++) {
		_Common::gotoXY(_left + 4 * i, _top + 2 * _size);
		if (i != _size)
			cout << char(219) << char(219) << char(219) << char(219);
	}
	for (int i = 0; i <= _size; i++) {
		for (int j = 0; j <= _size; j++) {
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			if (i != _size)
			{
				if (j == _size)
					cout << char(223) << char(223) << char(223) << char(223) << char(223);
				else
					cout << char(205) << char(205) << char(205) << char(205);
			}

			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			if (j != _size)
			{

				_Common::gotoXY(_left + 4 * i, _top + 2 * j);
				cout << char(186);
				_Common::gotoXY(_left + 4 * i, _top + 2 * j + 1);
				cout << char(186);

			}

			//if (i != _size&&j==0)
				//cout << char(223) << char(223) << char(223) << char(223) << char(223);
		}
		for (int i = 0; i < _size; i++)
		{
			_Common::gotoXY(_left + 4 * i, _top);
			cout << char(220) << char(220) << char(220) << char(220) << char(220);

		}

	}
	for (int i = 0; i < 100; i++)
	{
		_Common::gotoXY(i, 30);
		cout << char(205) << endl;
	}

	for (int i = 0; i < 42; i++)
	{
		_Common::gotoXY(58, i);
		cout << char(186) << endl;
	}
	/////////////////////////////////////
	for (int i = 0; i < 38; i++)
	{
		_Common::gotoXY(59 + i, 15);
		cout << char(205) << endl;
	}
	_Common::txtColor(6);
	_Common::gotoXY(72, 17);
	cout << "W: Move Up";
	_Common::gotoXY(72, 19);
	cout << "S: Move Down";
	_Common::gotoXY(72, 21);
	cout << "A: Move Left";
	_Common::gotoXY(72, 23);
	cout << "D: Move Right";
	_Common::gotoXY(72, 25);
	cout << "Space: Save";
	_Common::gotoXY(72, 27);
	cout << "Esc: Exit";
	_Common::gotoXY(69, 34);
	cout << "Nguyen Do Chi Thao ";
	_Common::gotoXY(71, 36);
	cout << "MSSV: 1712159";




	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());// di chuyển vào ô đầu
}
int _Board::checkBoard(int pX, int pY, bool pTurn)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn) _pArr[i][j].setCheck(-1);// Nếu lượt hiện hành là true: c = -1
				else _pArr[i][j].setCheck(1);// Nếu lượt hiện hành là false: c = 1
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}
int _Board::testBoard(int pX, int pY)//pX va pY la toa do cua con tro chuot
{
	int X, Y;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
			{
				X = i; Y = j;
			}
		}

	}
	//Kiem tra hang ngang
	int cnt1 = 0; int cnt2 = 0;
	for (int i = X; i < _size; i++)
	{
		if (_pArr[i][Y].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[i][Y].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	for (int i = X - 1; i >= 0; i--)
	{
		if (_pArr[i][Y].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[i][Y].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	if (cnt1 == 5 && cnt2 != 2) return _pArr[X][Y].getCheck();

	//Kiem tra hang doc
	cnt1 = 0;
	cnt2 = 0;
	for (int i = Y; i < +_size; i++)
	{
		if (_pArr[X][i].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[X][i].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	for (int i = Y - 1; i >= 0; i--)
	{
		if (_pArr[X][i].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[X][i].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	if (cnt1 == 5 && cnt2 != 2) return _pArr[X][Y].getCheck();
	//Kiem tra duong cheo chinh
	cnt1 = 0;
	cnt2 = 0;
	/*
	int x = X, y = Y;
	while (x < _size && y < _size)
	{
		if (_pArr[x][y].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[x][y].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
		x++; y++;
	}
	x = X - 1; y = Y - 1;
	while (x >= 0 && y >= 0)
	{
		if (_pArr[x][y].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[x][y].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
		x--; y--;
	}
	*/
	for (int i = 0; X + i < _size&&Y + i < _size; i++)
	{
		if (_pArr[X + i][Y + i].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[X + i][Y + i].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	for (int i = 1; X - i >= 0 && Y - i >= 0; i++)
	{
		if (_pArr[X - i][Y - i].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[X - i][Y - i].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	if (cnt1 == 5 && cnt2 != 2) return _pArr[X][Y].getCheck();

	//Kiem tra duong cheo phu
	cnt1 = 0;
	cnt2 = 0;
	for (int i = 0; X - i >= 0 && Y + i < _size; i++)
	{
		if (_pArr[X - i][Y + i].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[X - +i][Y + i].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	for (int i = 1; X + i < _size && Y - i >= 0; i++)
	{
		if (_pArr[X + i][Y - i].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[X + i][Y - i].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
	}
	/*while (x < _size && y >= 0)
	{
		if (_pArr[x][y].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[x][y].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
		x++; y--;
	}
	x = X - 1; y = Y - 1;
	while (x >= 0 && y < _size)
	{
		if (_pArr[x][y].getCheck() == _pArr[X][Y].getCheck()) cnt1++;
		else
		{
			if (_pArr[x][y].getCheck() == -1 * _pArr[X][Y].getCheck()) cnt2++;
			break;
		}
		x--; y++;
	}
	*/
	if (cnt1 == 5 && cnt2 != 2) return _pArr[X][Y].getCheck();
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == 0) return 2;
		}
	}
	return 0;
} // Trả mặc định
_Point _Board::Random()
{
	srand(time(NULL));
	int x, y;
	do
	{
		x = rand() % 13;
		y = rand() % 13;
	} while (_pArr[x][y].getCheck() != 0);
	return _Point(_pArr[x][y].getX(), _pArr[x][y].getY());
}
//nguoi X,-1  may O,1
_Point* _Board::findBestMove()
{

	long Max = 0;
	int x, y;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == 0)
			{
				long Diem_TC = Diem_TC_Doc(i, j) + Diem_TC_Ngang(i, j) + Diem_TC_CheoChinh(i, j) + Diem_TC_CheoNguoc(i, j);
				long Diem_PT = Diem_PT_Doc(i, j) + Diem_PT_Ngang(i, j) + Diem_PT_CheoChinh(i, j) + Diem_PT_CheoNguoc(i, j);
				long temp = Diem_TC > Diem_PT ? Diem_TC : Diem_PT;
				if (temp > Max)
				{
					Max = temp;
					x = i;
					y = j;
				}
			}

		}
	}
	if (Max == 0) return new _Point(_pArr[6][6].getX(), _pArr[6][6].getY());
	_Point*p = new _Point(_pArr[x][y].getX(), _pArr[x][y].getY());
	return p;
}
//TC
long _Board::Diem_TC_Ngang(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = x; i < _size; i++)
	{
		if (_pArr[i][y].getCheck() == 1) cntO++;
		else if (_pArr[i][y].getCheck() == -1)
		{
			cntX++; break;
		}
		else
			break;

	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (_pArr[i][y].getCheck() == 1) cntO++;
		else if (_pArr[i][y].getCheck() == -1)
		{
			cntX++; break;
		}
		else
			break;

	}
	if (cntX == 2) return 0;
	return Mangdiemtancong[cntO];
}
//nguoi X,-1  may O,1
long _Board::Diem_TC_Doc(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = y; i < _size; i++)
	{
		if (_pArr[x][i].getCheck() == 1) cntO++;
		else if (_pArr[x][i].getCheck() == -1)
		{
			cntX++; break;
		}
		else
			break;

	}
	for (int i = y - 1; i >= 0; i--)
	{
		if (_pArr[x][i].getCheck() == 1) cntO++;
		else if (_pArr[i][y].getCheck() == -1)
		{
			cntX++; break;
		}
		else
			break;

	}
	if (cntX == 2) return 0;
	return Mangdiemtancong[cntO];
}
long _Board::Diem_TC_CheoChinh(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = 0; i + x < _size&&i + y < _size; i++)
	{
		if (_pArr[x + i][y + i].getCheck() == 1) cntO++;
		else if (_pArr[x + i][y + i].getCheck() == -1)
		{
			cntX++; break;
		}
		else break;
	}
	for (int i = 1; x - i >= 0 && y - i >= 0; i++)
	{
		if (_pArr[x - i][y - i].getCheck() == 1) cntO++;
		else if (_pArr[x - i][y - i].getCheck() == -1)
		{
			cntX++; break;
		}
		else break;
	}
	if (cntX == 2) return 0;
	return Mangdiemtancong[cntO];
}
//nguoi X,-1  may O,1
long _Board::Diem_TC_CheoNguoc(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = 0; i + x < _size&&y - i >= 0; i++)
	{
		if (_pArr[x + i][y - i].getCheck() == 1) cntO++;
		else if (_pArr[x + i][y - i].getCheck() == -1)
		{
			cntX++; break;
		}
		else break;
	}
	for (int i = 1; x - i >= 0 && y + i < _size; i++)
	{
		if (_pArr[x - i][y + i].getCheck() == 1) cntO++;
		else if (_pArr[x - i][y + i].getCheck() == -1)
		{
			cntX++; break;
		}
		else break;
	}
	if (cntX == 2) return 0;
	return Mangdiemtancong[cntO];
}
//PT
//nguoi X,-1  may O,1
long _Board::Diem_PT_Ngang(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = x; i < _size; i++)
	{
		if (_pArr[i][y].getCheck() == -1) cntX++;
		else if (_pArr[i][y].getCheck() == 1)
		{
			cntO++; break;
		}
		else
			break;

	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (_pArr[i][y].getCheck() == -1) cntX++;
		else if (_pArr[i][y].getCheck() == 1)
		{
			cntO++; break;
		}
		else
			break;

	}
	if (cntO == 2) return 0;
	return Mangdiemphongthu[cntX];
}
//nguoi X,-1  may O,1
long _Board::Diem_PT_Doc(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = y; i < _size; i++)
	{
		if (_pArr[x][i].getCheck() == -1) cntX++;
		else if (_pArr[x][i].getCheck() == 1)
		{
			cntO++; break;
		}
		else
			break;

	}
	for (int i = y - 1; i >= 0; i--)
	{
		if (_pArr[x][i].getCheck() == -1) cntX++;
		else if (_pArr[i][y].getCheck() == 1)
		{
			cntO++; break;
		}
		else
			break;

	}
	if (cntO == 2) return 0;
	return Mangdiemtancong[cntX];
}
long _Board::Diem_PT_CheoChinh(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = 0; i + x < _size&&i + y < _size; i++)
	{
		if (_pArr[x + i][y + i].getCheck() == -1) cntX++;
		else if (_pArr[x + i][y + i].getCheck() == 1)
		{
			cntO++; break;
		}
		else break;
	}
	for (int i = 1; x - i >= 0 && y - i >= 0; i++)
	{
		if (_pArr[x - i][y - i].getCheck() == -1) cntX++;
		else if (_pArr[x - i][y - i].getCheck() == 1)
		{
			cntO++; break;
		}
		else break;
	}
	if (cntO == 2) return 0;
	return Mangdiemphongthu[cntX];
}
//nguoi X,-1  may O,1
long _Board::Diem_PT_CheoNguoc(int x, int y)
{
	int cntX = 0, cntO = 0;
	for (int i = 0; i + x < _size&&y - i >= 0; i++)
	{
		if (_pArr[x + i][y - i].getCheck() == -1) cntX++;
		else if (_pArr[x + i][y - i].getCheck() == 1)
		{
			cntO++; break;
		}
		else break;
	}
	for (int i = 1; x - i >= 0 && y + i < _size; i++)
	{
		if (_pArr[x - i][y + i].getCheck() == -1) cntX++;
		else if (_pArr[x - i][y + i].getCheck() == 1)
		{
			cntO++; break;
		}
		else break;
	}
	if (cntO == 2) return 0;
	return Mangdiemtancong[cntX];
}

// Trả mặc định là hòa // Chua cai