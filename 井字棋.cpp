#include<iostream>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
int i, j;
int Unitlength = 80;//单位长度
class player//玩家类
{
private:
	string name;
public:
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
};
void showBackground()//绘制棋盘
{
	for (i = 1; i <= 4; i++)
	{
		setlinecolor(BLACK);
		line(Unitlength * i, Unitlength, Unitlength * i, Unitlength * 4);
	}
	for (i = 1; i <= 4; i++)
	{
		setlinecolor(BLACK);
		line(Unitlength, Unitlength * i, Unitlength * 4, Unitlength * i);
	}
}

static player p1, p2;
int s[3][3], tf = 0, gofirst = 1, over, mode, x, y, count_1;
bool jieshu = false;
IMAGE image_x, image_o;
int Array_x1 = 0, Array_y1 = 0;
bool rematch = true;
char tellWin[] = "恭喜你赢了!";
char tellLoser[] = "很遗憾,你输了.";
char tellDraw[] = "打平！";
int IsWin()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (s[i][0] == 1 && s[i][1] == 1 && s[i][2] == 1) return 1;
		if (s[i][0] == -1 && s[i][1] == -1 && s[i][2] == -1) return -1;
	}

	for (i = 0; i < 3; i++)
	{
		if (s[0][i] == 1 && s[1][i] == 1 && s[2][i] == 1) return 1;
		if (s[0][i] == -1 && s[1][i] == -1 && s[2][i] == -1) return -1;
	}

	if ((s[0][0] == 1 && s[1][1] == 1 && s[2][2] == 1) || (s[2][0] == 1 && s[1][1] == 1 && s[0][2] == 1)) return 1;
	if ((s[0][0] == -1 && s[1][1] == -1 && s[2][2] == -1) || (s[2][0] == -1 && s[1][1] == -1 && s[0][2] == -1)) return -1;

	return 0;
}

void loadingChessPictures()//加载棋子图片
{
	loadimage(&image_o, _T("IMAGE"), _T("O"), Unitlength - 10, Unitlength - 10);
	loadimage(&image_x, _T("IMAGE"), _T("X"), Unitlength - 10, Unitlength - 10);
}
void showchesspieces()//绘制棋子
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (s[i][j] == 1)
			{
				putimage(Unitlength * (j + 1.6) - Unitlength * 0.5, Unitlength * (i + 1.6) - Unitlength * 0.5, &image_x, SRCCOPY);
			}
			if (s[i][j] == -1)
			{
				putimage(Unitlength * (j + 1.6) - Unitlength * 0.5, Unitlength * (i + 1.6) - Unitlength * 0.5, &image_o, SRCCOPY);
			}
		}
	}
}
int check()
{

	for (int x = 0; x < 3; x++)
	{
		if (s[x][0] == -1 && s[x][1] == -1 && s[x][2] == -1)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellWin);
			}
			if (over == 2) { cout << p1.getName() + "赢了！强！" << endl << endl; }

			jieshu = true;
			return -1;
			break;
		}
		if (s[x][0] == 1 && s[x][1] == 1 && s[x][2] == 1)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellLoser);
			}
			if (over == 2) { cout << p2.getName() + "赢了！强！" << endl << endl; }
			jieshu = true;
			return 1;
			break;
		}
	}
	for (int x = 0; x < 3; x++)
	{
		if (s[0][x] == -1 && s[1][x] == -1 && s[2][x] == -1)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellWin);
			}
			if (over == 2) { cout << p1.getName() + "赢了！强！" << endl << endl; }
			jieshu = true;
			return -1;
			break;
		}
		if (s[0][x] == 1 && s[1][x] == 1 && s[2][x] == 1)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellLoser);
			}
			if (over == 2) { cout << p2.getName() + "赢了！强！" << endl << endl; }
			jieshu = true;
			return 1;
			break;
		}
	}


	if (s[0][0] == -1 && s[1][1] == -1 && s[2][2] == -1 || s[2][0] == -1 && s[1][1] == -1 && s[0][2] == -1)
	{
		if (over == 0) {
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellWin);
		}
		if (over == 2) { cout << p1.getName() + "赢了！强！" << endl << endl; }
		jieshu = true;
		return -1;
	}
	else if (s[0][0] == 1 && s[1][1] == 1 && s[2][2] == 1 || s[2][0] == 1 && s[1][1] == 1 && s[0][2] == 1)
	{
		if (over == 0) {
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellLoser);
		}
		if (over == 2) { cout << p2.getName() + "赢了！强！" << endl << endl; }
		return 1;
	}

	else
	{
		int count = 0;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (s[x][y] == -1 || s[x][y] == 1) count++;
			}
		}
		if (count == 9)
		{
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellDraw);
			jieshu = true;
			return 0;
		}
	}
}
int Evaluation()
{
	int i, j, temp[3][3];

	x = y = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (s[i][j] == 0) temp[i][j] = 1;
			else temp[i][j] = s[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		x += (temp[i][0] + temp[i][1] + temp[i][2]) / 3;
	}

	for (i = 0; i < 3; i++)
	{
		x += (temp[0][i] + temp[1][i] + temp[2][i]) / 3;
	}

	x += (temp[0][0] + temp[1][1] + temp[2][2]) / 3;
	x += (temp[2][0] + temp[1][1] + temp[0][2]) / 3;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (s[i][j] == 0) temp[i][j] = -1;
			else temp[i][j] = s[i][j];
		}
	}


	for (i = 0; i < 3; i++)
	{
		y += (temp[i][0] + temp[i][1] + temp[i][2]) / 3;
	}

	for (i = 0; i < 3; i++)
	{
		y += (temp[0][i] + temp[1][i] + temp[2][i]) / 3;
	}

	y += (temp[0][0] + temp[1][1] + temp[2][2]) / 3;
	y += (temp[2][0] + temp[1][1] + temp[0][2]) / 3;

	return x + y;
}
void Initialize()//初始化棋盘背景
{
	initgraph(8 * Unitlength, 8 * Unitlength);
	setbkcolor(WHITE);
	cleardevice();
	loadingChessPictures();
	clearrectangle(0, 0, 10 * Unitlength, 11 * Unitlength);
	BeginBatchDraw();
	showBackground();
	showchesspieces();
	EndBatchDraw();
	char z[3];
	char choicemode[3];
	char gofirst[3];
	InputBox(z, 3, "选择游戏模式 电脑模式（0） 双人模式（1） 结束游戏（2）");
	// 将用户输入转换为数字
	sscanf(z, "%d", &over);
	if (over == 0)
	{
		InputBox(choicemode, 3, "选择电脑难度 简单模式(0) 普通模式（1）困难模式（2）");
		sscanf(choicemode, "%d", &mode);
		InputBox(gofirst, 3, "你想先手（0）还是电脑先手（1）");
		sscanf(gofirst, "%d", &tf);
	}
}
int AlphaBeta(int& value, int deep, bool MAX)
{
	bool prune = false;
	int i, j, flag, temp;

	if (deep == 3 || deep + count_1 == 9)
	{
		return Evaluation();
	}

	if (IsWin() == 1)
	{
		value = 10000;
		return 0;
	}

	if (MAX)
		flag = 10000;
	else
		flag = -10000;
	for (i = 0; i < 3 && !prune; i++)
	{
		for (j = 0; j < 3 && !prune; j++)
		{
			if (s[i][j] == 0)
			{
				if (MAX)
				{
					s[i][j] = -1;

					if (IsWin() == -1)
						temp = -10000;
					else
						temp = AlphaBeta(flag, deep + 1, !MAX);

					if (temp < flag) flag = temp;
					if (flag <= value) prune = true;
				}
				else
				{
					s[i][j] = 1;

					if (IsWin() == 1)
						temp = 10000;
					else
						temp = AlphaBeta(flag, deep + 1, !MAX);

					if (temp > flag) flag = temp;
					if (flag >= value) prune = true;

				}
				s[i][j] = 0;
			}
		}
	}
	if (MAX)
	{
		if (flag > value)
			value = flag;
	}
	else
	{
		if (flag < value)
			value = flag;
	}


	return flag;
}

void computer(int mode)
{
	if (mode == 1)
	{
		int breaktf = 0;
		if (s[0][0] == 0)
		{
			s[0][0] = 1;
		}
		else
		{
			if (s[1][1] == -1 && s[2][0] == -1 && s[0][2] == 1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[0][0] == 1 && s[0][1] == 1 && s[0][2] == 0) s[0][2] = 1;
			else if (s[0][0] == 1 && s[0][2] == 1 && s[0][1] == 0) s[0][1] = 1;
			else if (s[0][0] == 1 && s[2][2] == 1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[0][0] == 1 && s[2][0] == 1 && s[1][0] == 0) s[1][0] = 1;
			else if (s[0][0] == 1 && s[1][0] == 1 && s[2][0] == 0) s[2][0] = 1;
			else if (s[0][0] == 1 && s[1][1] == 1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[0][2] == 1 && s[0][0] == 1 && s[0][1] == 0) s[0][1] = 1;
			else if (s[0][2] == 1 && s[0][1] == 1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[0][2] == 1 && s[1][2] == 1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[0][2] == 1 && s[2][2] == 1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[0][2] == 1 && s[2][0] == 1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[0][2] == 1 && s[1][1] == 1 && s[2][0] == 0) s[2][0] = 1;
			else if (s[2][0] == 1 && s[1][0] == 1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[2][0] == 1 && s[0][0] == 1 && s[1][0] == 0) s[1][0] = 1;
			else if (s[2][0] == 1 && s[2][1] == 1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[2][0] == 1 && s[2][2] == 1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[2][0] == 1 && s[1][2] == 1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[2][0] == 1 && s[1][1] == 1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[2][2] == 1 && s[1][2] == 1 && s[0][2] == 0) s[0][2] = 1;
			else if (s[2][2] == 1 && s[0][2] == 1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[2][2] == 1 && s[2][0] == 1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[2][2] == 1 && s[2][1] == 1 && s[2][0] == 0) s[2][0] = 1;
			else if (s[2][2] == 1 && s[0][0] == 1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[2][2] == 1 && s[1][1] == 1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[0][1] == 1 && s[2][1] == 1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[1][0] == 1 && s[1][2] == 1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[1][2] == 1 && s[1][1] == 1 && s[1][0] == 0) s[1][0] = 1;
			else if (s[2][1] == 1 && s[1][1] == 1 && s[0][1] == 0) s[0][1] = 1;
			else if (s[1][0] == 1 && s[1][1] == 1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[0][1] == 1 && s[1][1] == 1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[0][0] == -1 && s[0][1] == -1 && s[0][2] == 0) s[0][2] = 1;
			else if (s[0][0] == -1 && s[0][2] == -1 && s[0][1] == 0) s[0][1] = 1;
			else if (s[0][0] == -1 && s[2][2] == -1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[0][0] == -1 && s[2][0] == -1 && s[1][0] == 0) s[1][0] = 1;
			else if (s[0][0] == -1 && s[1][0] == -1 && s[2][0] == 0) s[2][0] = 1;
			else if (s[0][0] == -1 && s[1][1] == -1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[0][2] == -1 && s[0][0] == -1 && s[0][1] == 0) s[0][1] = 1;
			else if (s[0][2] == -1 && s[0][1] == -1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[0][2] == -1 && s[1][2] == -1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[0][2] == -1 && s[2][2] == -1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[0][2] == -1 && s[2][0] == -1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[0][2] == -1 && s[1][1] == -1 && s[2][0] == 0) s[2][0] = 1;
			else if (s[2][0] == -1 && s[1][0] == -1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[2][0] == -1 && s[0][0] == -1 && s[1][0] == 0) s[1][0] = 1;
			else if (s[2][0] == -1 && s[2][1] == -1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[2][0] == -1 && s[2][2] == -1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[2][0] == -1 && s[1][2] == -1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[2][0] == -1 && s[1][1] == -1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[2][2] == -1 && s[1][2] == -1 && s[0][2] == 0) s[0][2] = 1;
			else if (s[2][2] == -1 && s[0][2] == -1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[2][2] == -1 && s[2][0] == -1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[2][2] == -1 && s[2][1] == -1 && s[2][0] == 0) s[2][0] = 1;
			else if (s[2][2] == -1 && s[0][0] == -1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[2][2] == -1 && s[1][1] == -1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[0][1] == -1 && s[2][1] == -1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[1][0] == -1 && s[1][2] == -1 && s[1][1] == 0) s[1][1] = 1;
			else if (s[1][2] == -1 && s[1][1] == -1 && s[1][0] == 0) s[1][0] = 1;
			else if (s[2][1] == -1 && s[1][1] == -1 && s[0][1] == 0) s[0][1] = 1;
			else if (s[1][0] == -1 && s[1][1] == -1 && s[1][2] == 0) s[1][2] = 1;
			else if (s[0][1] == -1 && s[1][1] == -1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[0][0] == -1 && s[2][2] == -1 && s[1][1] == 1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[0][2] == -1 && s[2][0] == -1 && s[1][1] == 1 && s[2][1] == 0) s[2][1] = 1;
			else if (s[0][0] == -1 && s[1][1] == 1 && s[0][2] == 0) s[0][2] = 1;
			else if (s[0][2] == -1 && s[1][1] == 1 && s[0][0] == 0) s[0][0] = 1;
			else if (s[2][0] == -1 && s[1][1] == 1 && s[2][2] == 0) s[2][2] = 1;
			else if (s[2][2] == -1 && s[1][1] == 1 && s[2][0] == 0) s[2][0] = 1;
			else
			{
				for (int x = 0; x < 3; x++)
				{
					for (int y = 0; y < 3; y++)
					{
						if (s[x][y] == 0)
						{
							s[x][y] = 1;
							breaktf = 1;
							break;
						}
					}
					if (breaktf == 1) break;
				}
			}
		}
	}
	if (mode == 0)
	{
		int breaktf = 0;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (s[x][y] == 0)
				{
					s[x][y] = 1;
					breaktf = 1;
					break;
				}
			}
			if (breaktf == 1) break;
		}
	}
	if (mode == 2)
	{
		int row, col, temp;
		int m = -10000, value = -10000, deep = 1;
		count_1 = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s[i][j] == 0)
				{
					s[i][j] = 1;
					AlphaBeta(value, deep, 1);
					if (IsWin() == 1)
					{
						settextstyle(Unitlength, 0, _T("黑体"));
						settextcolor(RED);
						outtextxy(Unitlength, Unitlength * 5, tellLoser);
						jieshu = true;
					}
					if (value > m)
					{
						m = value;
						row = i; col = j;
					}


					value = -10000;
					s[i][j] = 0;
				}
			}
		}
		
		s[row][col] = 1;

		value = -10000; m = -10000; deep = 1;

		count_1++;

		Evaluation();
		if (x == 0)
		{
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellDraw);
			jieshu = true;
		}
		if (IsWin() == -1)
		{
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellWin);
			jieshu = true;
		}
	}


}


void User_relatedinput()//玩家动作
{
	TCHAR a[20];
	HWND hwnd = GetHWnd();//获取绘图窗口句柄
	POINT point;
	MOUSEMSG m;//定义鼠标消息
	POINT ok;
	while (MouseHit())
	{
		m = GetMouseMsg();
		GetCursorPos(&point);//获取鼠标指针位置（屏幕坐标）
		ScreenToClient(hwnd, &point);//将鼠标指针位置转换为窗口坐标


		if (over == 0)
		{

			if (tf == 0)
			{
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (s[i][j] == 0)
						{
							if ((point.x - Unitlength * (j + 1.5)) * (point.x - Unitlength * (j + 1.5)) + (point.y - Unitlength * (i + 1.5)) * (point.y - Unitlength * (i + 1.5)) < 1000)
							{
								if (m.uMsg == WM_LBUTTONDOWN)
								{
									Array_x1 = i;
									Array_y1 = j;
									putimage(Unitlength * (j + 1.1), Unitlength * (i + 1.1), &image_o, SRCCOPY);
									s[i][j] = -1;
									tf = 1;

								}
								break;
							}
						}
					}
				}
			}

			else if (tf == 1)
			{
				computer(mode);
				showchesspieces();

				tf = 0;
			}



		}

		if (over == 1)
		{
			if (tf == 0)
			{
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (s[i][j] == 0)
						{
							if ((point.x - Unitlength * (j + 1.5)) * (point.x - Unitlength * (j + 1.5)) + (point.y - Unitlength * (i + 1.5)) * (point.y - Unitlength * (i + 1.5)) < 1000)
							{
								if (m.uMsg == WM_LBUTTONDOWN)
								{
									Array_x1 = i;
									Array_y1 = j;
									putimage(Unitlength * (j + 1.1), Unitlength * (i + 1.1), &image_o, SRCCOPY);
									s[i][j] = -1;
									tf = 1;
								}
								break;
							}
						}
					}
				}
			}
			if (tf == 1)
			{
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (s[i][j] == 0)
						{
							if ((point.x - Unitlength * (j + 1.5)) * (point.x - Unitlength * (j + 1.5)) + (point.y - Unitlength * (i + 1.5)) * (point.y - Unitlength * (i + 1.5)) < 1000)
							{
								if (m.uMsg == WM_LBUTTONDOWN)
								{
									Array_x1 = i;
									Array_y1 = j;
									putimage(Unitlength * (j + 1.1), Unitlength * (i + 1.1), &image_x, SRCCOPY);
									s[i][j] = 1;
									tf = 0;
								}
								break;
							}
						}
					}
				}
			}
		}
		if (over == 2)
		{
			closegraph();
			exit(0);
		}
	}
}

void playAgain()
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			s[i][j] = 0;
		}
	}
	char rematch_yn[3];
	InputBox(rematch_yn, 3, "再来一局？（1） 退出游戏（0）");
	sscanf(rematch_yn, "%d", &rematch);
	if (rematch == 1)
	{
		jieshu = false;
	}
	else if (rematch == 0)
	{
		exit(0);
	}
}




int main()
{
	while (rematch)
	{
		Initialize();
		while (!jieshu)
		{
			User_relatedinput();
			
			check();
		}
		playAgain();
	}


	cout << "电脑模式（0），结束游戏（1），双人模式（2）: ";
	cin >> over;


	while (over == 2)
	{

		string a, b;
		jieshu = false;
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++) s[x][y] = 0;
		cout << "请输入玩家1的名字" << endl;
		cin >> a;
		cout << "请输入玩家2的名字" << endl;
		cin >> b;
		while (a == b)
		{
			cout << "你们不能用同一个名字哦" << endl;
			cout << "请重新输入玩家1的名字" << endl;
			cin >> a;
			cout << "请重新输入玩家2的名字" << endl;
			cin >> b;
		}
		p1.setName(a); p2.setName(b);
		cout << p1.getName() + "先走请按1," + p2.getName() + "先走请按0" << endl;
		cin >> gofirst;
		if (gofirst == 1) tf = 0;
		else if (gofirst == 0) tf = 1;


		cout << "如果你想再玩一次请扣 2, 不想就扣 1: ";
		cin >> over;
	}
	return 0;
}

