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
#include"_Board.h"
#include"_Game.h"
#pragma comment(lib, "winmm.lib")

_Game::_Game(int p_size, int pLeft, int pTop) {
	_b = new _Board(p_size, pLeft, pTop);
	_loop = _turn = true;
	_command = -1; // Gán lượt và phím mặc định
	_x = pLeft; _y = pTop;
	_winX = 0;
	_winO = 0;
	_resX = 0;
	_resO = 0;
	_mode = 0;
}
void _Game::saveGame()
{
	ofstream f;
	f.open("Turn.txt");
	f << _turn << endl;
	f << _winX << endl;
	f << _winO << endl;
	f << _resX << endl;
	f << _resO << endl;
	f << _mode << endl;
	f.close();
	_b->saveGame();
}

_Game::~_Game() { delete _b; }
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard() {
	do {
		_command = toupper(_getch());
	} while (_command == 0);
	return _command;
}
char _Game::askContinue() {
	_Common::txtColor(12);
	for (int i = 0; i < 12; i++)
	{
		_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4 + i);
		cout << "                                                      ";
	}

	_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 5);
	cout << "Do you want continue?";
	_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 6);
	return waitKeyBoard();
}
//////////////////////////////////
void _Game::loadGame() {
	system("cls");
	_b->resetData(); // Khởi tạo dữ liệu gốc
	_b->drawBoard(); // Vẽ màn hình game
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	ifstream f;
	f.open("Turn.txt");
	f >> _turn;
	f >> _winX;
	f >> _winO;
	f >> _resX;
	f >> _resO;
	f >> _mode;
	f.close();
	_Common::txtColor(8);
	_Common::O(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
	_Common::txtColor(12);
	_Common::X(28, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
	if (_mode == 1)
	{
		_Common::txtColor(6);
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 18, 2);
		cout << "1 Player(X)";
	}
	else
	{
		_Common::txtColor(6);
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 18, 2);
		cout << "2 Player(X vs O)";

	}
	_Common::txtColor(6);
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 4);
	cout << "#Nguoi choi X da thang : " << _winX;
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 6);
	_Common::txtColor(6);
	cout << "#Nguoi choi X da di duoc: " << _resX;
	_Common::txtColor(6);
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 8);
	cout << "#Nguoi choi O da thang : " << _winO;
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 10);
	_Common::txtColor(6);
	cout << "#Nguoi choi O da di duoc: " << _resO;
	_b->loadGame();


}
void _Game::startGame() {
	_Common::txtColor(12);
	system("cls");
	_turn = -1;
	_resX = 0;
	_resO = 0;
	_b->resetData(); // Khởi tạo dữ liệu gốc
	_b->drawBoard(); // Vẽ màn hình game
	_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
	_Common::txtColor(8);
	_Common::O(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
	_Common::txtColor(12);
	_Common::X(28, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
	if (_mode == 1)
	{
		//_turn = 1;
		_Common::txtColor(6);
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 18, 2);
		cout << "1 Player(X)";
	}
	else
	{
		_Common::txtColor(6);
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 18, 2);
		cout << "2 Player(X vs O)";

	}
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 4);
	_Common::txtColor(6);
	cout << "#Nguoi choi X da thang : " << _winX;
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 6);
	_Common::txtColor(6);
	cout << "#Nguoi choi X da di duoc: " << _resX;
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 8);
	_Common::txtColor(6);
	cout << "#Nguoi choi O da thang : " << _winO;
	_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 10);
	_Common::txtColor(6);
	cout << "#Nguoi choi O da di duoc: " << _resO;
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);


}
void _Game::exitGame() {
	system("cls");
	//Có thể lưu game trước khi exit
	_loop = false;

}
bool _Game::processCheckBoard() {
	switch (_b->checkBoard(_x, _y, _turn)) {
	case -1:
		_Common::txtColor(12);
		printf("X");
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 6);
		_Common::txtColor(6);
		cout << "#Nguoi choi X da di duoc: " << ++_resX;
		_Common::txtColor(12);
		_Common::O(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
		_Common::txtColor(8);
		_Common::X(28, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
		break;
	case 1:
		_Common::txtColor(12);
		printf("O");
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 10);
		_Common::txtColor(6);
		cout << "#Nguoi choi O da di duoc: " << ++_resO;
		_Common::txtColor(8);
		_Common::O(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
		_Common::txtColor(12);
		_Common::X(28, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
		break;
	case 0: return false; // Khi đánh vào ô đã đánh rồi

	}
	return true;

}
int _Game::processFinish() {
	// Nhảy tới vị trí thích hợp để in chuỗi thắng/thua/hòa
	_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4);
	int pWhoWin = _b->testBoard(_x, _y);
	int x = 0, y = _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4;
	switch (pWhoWin) {

	case -1:
		for (int i = 0; i < 12; i++)
		{
			_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4 + i);
			cout << "                                                      ";
		}
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 4);
		_Common::txtColor(6);
		cout << "#Nguoi choi X da thang : " << ++_winX;
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("GameOver.wav"), NULL, SND_ASYNC);
		for (int i = 0; i < 17; i++)
		{
			Sleep(200);
			_Common::gotoXY(x, y);
			_Common::txtColor(i % 16);
			printf("Nguoi choi %d da thang va nguoi choi %d da thua", true, false);
			_Common::X(x + 6, y + 1);
		}
		PlaySound(TEXT("PopStars.wav"), NULL, SND_LOOP | SND_ASYNC);
		break;
	case 1:
		for (int i = 0; i < 12; i++)
		{
			_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4 + i);
			cout << "                                                      ";
		}
		_Common::gotoXY(_b->getXAt(_b->get_size() - 1, _b->get_size() - 1) + 14, 8);
		_Common::txtColor(6);
		cout << "#Nguoi choi O da thang : " << ++_winO;
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("GameOver.wav"), NULL, SND_ASYNC);
		for (int i = 0; i < 17; i++)
		{
			Sleep(200);
			_Common::gotoXY(x, y);
			_Common::txtColor(i % 16);
			printf("Nguoi choi %d da thang va nguoi choi %d da thua", false, true);
			_Common::O(x + 6, y + 1);
		}
		PlaySound(TEXT("PopStars.wav"), NULL, SND_LOOP | SND_ASYNC);
		break;
	case 0:
		for (int i = 0; i < 12; i++)
		{
			_Common::gotoXY(0, _b->getYAt(_b->get_size() - 1, _b->get_size() - 1) + 4 + i);
			cout << "                                                                                  ";
		}
		for (int i = 0; i < 17; i++)

		{
			Sleep(200);
			_Common::gotoXY(x, y);
			_Common::txtColor(rand() % 16);
			printf("Nguoi choi %d da hoa nguoi choi %d", false, true);
		}
		break;
	case 2:
		_turn = !_turn; // Đổi lượt nếu không có gì xảy ra
		break;
	}
	_Common::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;

}
void _Game::moveRight() {
	if (_x < _b->getXAt(_b->get_size() - 1, _b->get_size() - 1)) {
		_x += 4;
		_Common::gotoXY(_x, _y);

	}

}
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->get_size() - 1, _b->get_size() - 1))
	{
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::vsCom()
{
	//_b->findBestMove();
	_Point*p = new _Point(*_b->findBestMove());
	//_Point p = _b->Random();
	_x = p->getX();
	_y = p->getY();
	_Common::gotoXY(_x, _y);
	//printf("O");

}