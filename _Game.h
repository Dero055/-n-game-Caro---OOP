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
#pragma comment(lib, "winmm.lib")
class _Game {
	_Board* _b;// một bàn cờ
	int _mode;
	int _winX;
	int _winO;
	int _resX;
	int _resO;
	bool _turn;// lượt chơi: true lượt người một & false lượt người thứ hai
	int _x, _y; // Tọa độ hiện hành của nháy chuột
	int _command; // phím gõ từ người dùng
	bool _loop; // Biến quyết định thoát game hay không
public:
	_Game(int, int, int);
	~_Game();
	int mode() {
		return _mode;
	}
	void setmode(int x) { _mode = x; }
	int getCommand();
	bool isContinue();
	char waitKeyBoard(); // Hàm nhận phím từ người dùng
	char askContinue();
	void startGame(); // Hàm bắt đầu game
	void exitGame(); // Hàm thoát game
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void loadGame();
	void saveGame();
	void vsCom();
};