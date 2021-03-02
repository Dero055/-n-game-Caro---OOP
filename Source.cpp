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
using namespace std;

void main() {
	//_Common::re_sizeConsole(97, 43);
	PlaySound(TEXT("PopStars.wav"),NULL, SND_LOOP | SND_ASYNC);
	//PlaySound(NULL, 0, 0);
	//PlaySound(TEXT("PopStars.wav"), NULL, SND_LOOP | SND_ASYNC);



	_Common::fixConsoleWindow();
Menu:
	//_Common::Menu(18, 5);
	_Game g(13, 2, 2); // Sinh viên tự định nghĩa các hằng số
	_Common::txtColor(6);
//Menu:
	switch (_Common::Menu(18, 5))
{
	case 1:
	{
		switch (_Common::Menu1(18, 5))
		{
			case 1:
			{
				system("cls");
				{
					start:
						g.startGame();
						_Common::gotoXY(4, 3);
						while (g.isContinue()) {
							g.waitKeyBoard();
							if (g.getCommand() == 27)
							{
								//Save
								g.exitGame();
							}
							else
							{
								switch (g.getCommand()) {
								case 'A':
									g.moveLeft();
									break;
								case 'W':
									g.moveUp();
									break;
								case 'S':
									g.moveDown();
									break;
								case 'D':
									g.moveRight();
									break;
								case 32:
									g.saveGame();
									g.exitGame();
								case 13:
									//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
									if (g.processCheckBoard()) {
										switch (g.processFinish()) {
										case -1: case 1: case 0: {
											if (g.askContinue() != 'Y')
											{
												g.exitGame();
											}
											else
											{
												goto start;
											}
										}
										}

									}

								}

							}

						}
					}
				_getch();
					break;
				}
			case 2:
			{
			start2:
				g.setmode(1);
				g.startGame();
				_Common::gotoXY(4, 3);

				while (g.isContinue())
				{
					Sleep(100);
					g.vsCom();
					if (g.processCheckBoard())
					{
						switch (g.processFinish())
						{
						case -1: case 1: case 0:
						{
							if (g.askContinue() != 'Y')
							{
								g.exitGame();
							}
							else
							{
								goto start2;
							}
						}


						}
					}
					while (1)
					{
						int win = 0;
						g.waitKeyBoard();
						if (g.getCommand() == 27)
						{
							//Save
							g.exitGame();
						}
						else
						{

							switch (g.getCommand())
							{
							case 'A':
								g.moveLeft();
								break;
							case 'W':
								g.moveUp();
								break;
							case 'S':
								g.moveDown();
								break;
							case 'D':
								g.moveRight();
								break;
							case 32:
								g.saveGame();
								g.exitGame();
								break;
							case 13:
							{
								//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
								win = 1;
								if (g.processCheckBoard())
								{
									switch (g.processFinish())
									{
									case -1: case 1: case 0:
									{
										if (g.askContinue() != 'Y')
										{
											g.exitGame();
										}
										else
										{
											goto start2;
										}
									}

									}


								}
									}
							}
						}
						if (win == 1) break;
					}
				}
				
				//_getch();
				break;
			}
			default:
				break;
		}
	break;
	}
	case 2:
	{

		g.loadGame();
		if (g.mode() == 0)
		{
			_Common::gotoXY(4, 3);
			while (g.isContinue()) {
				g.waitKeyBoard();
				if (g.getCommand() == 27)
				{
					//Save
					g.exitGame();
				}
				else {
					switch (g.getCommand()) {
					case 'A':
						g.moveLeft();
						break;
					case 'W':
						g.moveUp();
						break;
					case 'S':
						g.moveDown();
						break;
					case 'D':
						g.moveRight();
						break;
					case 32:
						g.saveGame();
						g.exitGame();
					case 13:
						//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
						if (g.processCheckBoard()) {
							switch (g.processFinish()) {
							case -1: case 1: case 0: {
								if (g.askContinue() != 'Y')
								{
									g.exitGame();
								}
								else
								{
									goto start;
								}
							}
							}

						}

					}
					_getch();

				}
			}
		}
		if(g.mode() == 1)
		{
			g.setmode(1);
			_Common::gotoXY(4, 3);

			/* while (g.isContinue())
			{
				g.waitKeyBoard();
				if (g.getCommand() == 27)
				{
					//Save
					g.exitGame();
				}
				else
				{
					switch (g.getCommand()) {
					case 'A':
						g.moveLeft();
						break;
					case 'W':
						g.moveUp();
						break;
					case 'S':
						g.moveDown();
						break;
					case 'D':
						g.moveRight();
						break;
					case 32:
						g.saveGame();
						g.exitGame();
						break;
					case 13:
					{
						//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
						if (g.processCheckBoard())
						{
							switch (g.processFinish())
							{
							case -1: case 1: case 0:
							{
								if (g.askContinue() != 'Y')
								{
									g.exitGame();
								}
								else
								{
									goto start2;
								}
							}


							}


						}
						Sleep(100);
						g.vsCom();
						if (g.processCheckBoard())
						{
							switch (g.processFinish())
							{
							case -1: case 1: case 0:
							{
								if (g.askContinue() != 'Y')
								{
									g.exitGame();
								}
								else
								{
									goto start2;
								}
							}


							}


						}
					}


					}


				}

			} */
			while (g.isContinue())
			{
				Sleep(100);
				g.vsCom();
				if (g.processCheckBoard())
				{
					switch (g.processFinish())
					{
					case -1: case 1: case 0:
					{
						if (g.askContinue() != 'Y')
						{
							g.exitGame();
						}
						else
						{
							goto start2;
						}
					}


					}
				}
				while (1)
				{
					int win = 0;
					g.waitKeyBoard();
					if (g.getCommand() == 27)
					{
						//Save
						g.exitGame();
					}
					else
					{

						switch (g.getCommand())
						{
						case 'A':
							g.moveLeft();
							break;
						case 'W':
							g.moveUp();
							break;
						case 'S':
							g.moveDown();
							break;
						case 'D':
							g.moveRight();
							break;
						case 32:
							g.saveGame();
							g.exitGame();
							break;
						case 13:
						{
							//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
							win = 1;
							if (g.processCheckBoard())
							{
								switch (g.processFinish())
								{
								case -1: case 1: case 0:
								{
									if (g.askContinue() != 'Y')
									{
										g.exitGame();
									}
									else
									{
										goto start2;
									}
								}

								}


							}
						}
						}
					}
					if (win == 1) break;
				}
			}
			_getch();
		}

		
		break;
	
	}
	case 3:
	{
	Menu3:
		switch (_Common::Menu3(18, 5))
		{
			case 1:
			{
				PlaySound(TEXT("PopStars.wav"), NULL, SND_LOOP | SND_ASYNC);
				goto Menu3;
			break;
			}
			case 2:
			{
				PlaySound(NULL, 0, 0);
				goto Menu3;
				break;
			}
			case 3:
			{
				goto Menu;
				break;
			}
			default:
				break;
		}

		break;
	}
	case 4:
	{
		switch (_Common::Menu4(18, 5))
		{
		case 1:
		
		{	
			system("cls");
			goto Menu;
				break;
		}
			default:
				break;
		}
	
			break;
	}
	case 5:
	{
		g.exitGame();
		break;
	}
	default:
		break;
}


	
	
	
	/*
	switch (g.waitKeyBoard())
	{
	case '5':
	{

	start2:
		g.startGame();
		_Common::gotoXY(4, 3);

		while (g.isContinue())
		{
			g.waitKeyBoard();
			if (g.getCommand() == 27)
			{
				//Save
				g.exitGame();
			}
			else
			{
				switch (g.getCommand()) {
				case 'A':
					g.moveLeft();
					break;
				case 'W':
					g.moveUp();
					break;
				case 'S':
					g.moveDown();
					break;
				case 'D':
					g.moveRight();
					break;
				case 32:
					g.saveGame();
					g.exitGame();
					break;
				case 13:
				{
					//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
					if (g.processCheckBoard())
					{
						switch (g.processFinish())
						{
						case -1: case 1: case 0:
						{
							if (g.askContinue() != 'Y')
							{
								g.exitGame();
							}
							else
							{
								goto start2;
							}
						}


						}


					}
					Sleep(100);
					g.vsCom();
					if (g.processCheckBoard())
					{
						switch (g.processFinish())
						{
						case -1: case 1: case 0:
						{
							if (g.askContinue() != 'Y')
							{
								g.exitGame();
							}
							else
							{
								goto start2;
							}
						}


						}


					}
				}


				}


			}

		}
		break;
	}
	case '4':
	{
		g.loadGame();
		_Common::gotoXY(4, 3);
		while (g.isContinue()) {
			g.waitKeyBoard();
			if (g.getCommand() == 27)
			{
				//Save
				g.exitGame();
			}
			else {
				switch (g.getCommand()) {
				case 'A':
					g.moveLeft();
					break;
				case 'W':
					g.moveUp();
					break;
				case 'S':
					g.moveDown();
					break;
				case 'D':
					g.moveRight();
					break;
				case 32:
					g.saveGame();
					g.exitGame();
				case 13:
					//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
					if (g.processCheckBoard()) {
						switch (g.processFinish()) {
						case -1: case 1: case 0: {
							if (g.askContinue() != 'Y')
							{
								g.exitGame();
							}
							else
							{
								goto start;
							}
						}
						}

					}

				}

			}

		}

		_getch();
		break;
	}
	case '3':
	{
		system("cls");
		_Common::Introduction(20, 20);
		if (g.waitKeyBoard() == '1')
		{
			system("cls");
			goto Menu;
		}
		_getch();
		break;
	}
	case '2':
	{
		g.exitGame();
		break;
	}

	case '1':
	{
		if (g.waitKeyBoard() == '1')
		{
		start:
			g.startGame();
			_Common::gotoXY(4, 3);
			while (g.isContinue()) {
				g.waitKeyBoard();
				if (g.getCommand() == 27)
				{
					//Save
					g.exitGame();
				}
				else
				{
					switch (g.getCommand()) {
					case 'A':
						g.moveLeft();
						break;
					case 'W':
						g.moveUp();
						break;
					case 'S':
						g.moveDown();
						break;
					case 'D':
						g.moveRight();
						break;
					case 32:
						g.saveGame();
						g.exitGame();
					case 13:
						//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
						if (g.processCheckBoard()) {
							switch (g.processFinish()) {
							case -1: case 1: case 0: {
								if (g.askContinue() != 'Y')
								{
									g.exitGame();
								}
								else
								{
									goto start;
								}
							}
							}

						}

					}

				}

			}
		}
		break;
	}

	}
	*/
	_getch();
}

