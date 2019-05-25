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
int s[3][3], tf = 0, gofirst = 1, row, column, over,mode;
bool jieshu = false;
IMAGE image_x, image_o;
int Array_x1 = 0, Array_y1 = 0;

void loadingChessPictures()//加载棋子图片
{
	loadimage(&image_o, _T("E:\\o.jpg"), Unitlength - 10, Unitlength - 10);
	loadimage(&image_x, _T("E:\\x.jpg"), Unitlength - 10, Unitlength - 10);
}
void showchesspieces()//绘制棋子
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (s[i][j] == 2)
			{
				putimage(Unitlength * (j + 1.6) - Unitlength * 0.5, Unitlength * (i + 1.6) - Unitlength * 0.5, &image_x, SRCCOPY);
			}
			if (s[i][j] == 1)
			{
				putimage(Unitlength * (j + 1.6) - Unitlength * 0.5, Unitlength * (i + 1.6) - Unitlength * 0.5, &image_o, SRCCOPY);
			}
		}
	}
}
void computer(int mode)
{
	if (mode == 1)
	{
		int breaktf = 0;
		if (s[0][0] == 0)
		{
			s[0][0] = 2;
		}
		else
		{
			if (s[1][1] == 1 && s[2][0] == 1 && s[0][2] == 2 && s[2][2] == 0) s[2][2] = 2;
			else if (s[0][0] == 2 && s[0][1] == 2 && s[0][2] == 0) s[0][2] = 2;
			else if (s[0][0] == 2 && s[0][2] == 2 && s[0][1] == 0) s[0][1] = 2;
			else if (s[0][0] == 2 && s[2][2] == 2 && s[1][1] == 0) s[1][1] = 2;
			else if (s[0][0] == 2 && s[2][0] == 2 && s[1][0] == 0) s[1][0] = 2;
			else if (s[0][0] == 2 && s[1][0] == 2 && s[2][0] == 0) s[2][0] = 2;
			else if (s[0][0] == 2 && s[1][1] == 2 && s[2][2] == 0) s[2][2] = 2;
			else if (s[0][2] == 2 && s[0][0] == 2 && s[0][1] == 0) s[0][1] = 2;
			else if (s[0][2] == 2 && s[0][1] == 2 && s[0][0] == 0) s[0][0] = 2;
			else if (s[0][2] == 2 && s[1][2] == 2 && s[2][2] == 0) s[2][2] = 2;
			else if (s[0][2] == 2 && s[2][2] == 2 && s[1][2] == 0) s[1][2] = 2;
			else if (s[0][2] == 2 && s[2][0] == 2 && s[1][1] == 0) s[1][1] = 2;
			else if (s[0][2] == 2 && s[1][1] == 2 && s[2][0] == 0) s[2][0] = 2;
			else if (s[2][0] == 2 && s[1][0] == 2 && s[0][0] == 0) s[0][0] = 2;
			else if (s[2][0] == 2 && s[0][0] == 2 && s[1][0] == 0) s[1][0] = 2;
			else if (s[2][0] == 2 && s[2][1] == 2 && s[2][2] == 0) s[2][2] = 2;
			else if (s[2][0] == 2 && s[2][2] == 2 && s[2][1] == 0) s[2][1] = 2;
			else if (s[2][0] == 2 && s[1][2] == 2 && s[1][1] == 0) s[1][1] = 2;
			else if (s[2][0] == 2 && s[1][1] == 2 && s[1][2] == 0) s[1][2] = 2;
			else if (s[2][2] == 2 && s[1][2] == 2 && s[0][2] == 0) s[0][2] = 2;
			else if (s[2][2] == 2 && s[0][2] == 2 && s[1][2] == 0) s[1][2] = 2;
			else if (s[2][2] == 2 && s[2][0] == 2 && s[2][1] == 0) s[2][1] = 2;
			else if (s[2][2] == 2 && s[2][1] == 2 && s[2][0] == 0) s[2][0] = 2;
			else if (s[2][2] == 2 && s[0][0] == 2 && s[1][1] == 0) s[1][1] = 2;
			else if (s[2][2] == 2 && s[1][1] == 2 && s[0][0] == 0) s[0][0] = 2;
			else if (s[0][1] == 2 && s[2][1] == 2 && s[1][1] == 0) s[1][1] = 2;
			else if (s[1][0] == 2 && s[1][2] == 2 && s[1][1] == 0) s[1][1] = 2;
			else if (s[1][2] == 2 && s[1][1] == 2 && s[1][0] == 0) s[1][0] = 2;
			else if (s[2][1] == 2 && s[1][1] == 2 && s[0][1] == 0) s[0][1] = 2;
			else if (s[1][0] == 2 && s[1][1] == 2 && s[1][2] == 0) s[1][2] = 2;
			else if (s[0][1] == 2 && s[1][1] == 2 && s[2][1] == 0) s[2][1] = 2;
			else if (s[0][0] == 1 && s[0][1] == 1 && s[0][2] == 0) s[0][2] = 2;
			else if (s[0][0] == 1 && s[0][2] == 1 && s[0][1] == 0) s[0][1] = 2;
			else if (s[0][0] == 1 && s[2][2] == 1 && s[1][1] == 0) s[1][1] = 2;
			else if (s[0][0] == 1 && s[2][0] == 1 && s[1][0] == 0) s[1][0] = 2;
			else if (s[0][0] == 1 && s[1][0] == 1 && s[2][0] == 0) s[2][0] = 2;
			else if (s[0][0] == 1 && s[1][1] == 1 && s[2][2] == 0) s[2][2] = 2;
			else if (s[0][2] == 1 && s[0][0] == 1 && s[0][1] == 0) s[0][1] = 2;
			else if (s[0][2] == 1 && s[0][1] == 1 && s[0][0] == 0) s[0][0] = 2;
			else if (s[0][2] == 1 && s[1][2] == 1 && s[2][2] == 0) s[2][2] = 2;
			else if (s[0][2] == 1 && s[2][2] == 1 && s[1][2] == 0) s[1][2] = 2;
			else if (s[0][2] == 1 && s[2][0] == 1 && s[1][1] == 0) s[1][1] = 2;
			else if (s[0][2] == 1 && s[1][1] == 1 && s[2][0] == 0) s[2][0] = 2;
			else if (s[2][0] == 1 && s[1][0] == 1 && s[0][0] == 0) s[0][0] = 2;
			else if (s[2][0] == 1 && s[0][0] == 1 && s[1][0] == 0) s[1][0] = 2;
			else if (s[2][0] == 1 && s[2][1] == 1 && s[2][2] == 0) s[2][2] = 2;
			else if (s[2][0] == 1 && s[2][2] == 1 && s[2][1] == 0) s[2][1] = 2;
			else if (s[2][0] == 1 && s[1][2] == 1 && s[1][1] == 0) s[1][1] = 2;
			else if (s[2][0] == 1 && s[1][1] == 1 && s[1][2] == 0) s[1][2] = 2;
			else if (s[2][2] == 1 && s[1][2] == 1 && s[0][2] == 0) s[0][2] = 2;
			else if (s[2][2] == 1 && s[0][2] == 1 && s[1][2] == 0) s[1][2] = 2;
			else if (s[2][2] == 1 && s[2][0] == 1 && s[2][1] == 0) s[2][1] = 2;
			else if (s[2][2] == 1 && s[2][1] == 1 && s[2][0] == 0) s[2][0] = 2;
			else if (s[2][2] == 1 && s[0][0] == 1 && s[1][1] == 0) s[1][1] = 2;
			else if (s[2][2] == 1 && s[1][1] == 1 && s[0][0] == 0) s[0][0] = 2;
			else if (s[0][1] == 1 && s[2][1] == 1 && s[1][1] == 0) s[1][1] = 2;
			else if (s[1][0] == 1 && s[1][2] == 1 && s[1][1] == 0) s[1][1] = 2;
			else if (s[1][2] == 1 && s[1][1] == 1 && s[1][0] == 0) s[1][0] = 2;
			else if (s[2][1] == 1 && s[1][1] == 1 && s[0][1] == 0) s[0][1] = 2;
			else if (s[1][0] == 1 && s[1][1] == 1 && s[1][2] == 0) s[1][2] = 2;
			else if (s[0][1] == 1 && s[1][1] == 1 && s[2][1] == 0) s[2][1] = 2;
			else if (s[0][0] == 1 && s[2][2] == 1 && s[1][1] == 2 && s[2][1] == 0) s[2][1] = 2;
			else if (s[0][2] == 1 && s[2][0] == 1 && s[1][1] == 2 && s[2][1] == 0) s[2][1] = 2;
			else if (s[0][0] == 1 && s[1][1] == 2 && s[0][2] == 0) s[0][2] = 2;
			else if (s[0][2] == 1 && s[1][1] == 2 && s[0][0] == 0) s[0][0] = 2;
			else if (s[2][0] == 1 && s[1][1] == 2 && s[2][2] == 0) s[2][2] = 2;
			else if (s[2][2] == 1 && s[1][1] == 2 && s[2][0] == 0) s[2][0] = 2;
			else
			{
				for (int x = 0; x < 3; x++)
				{
					for (int y = 0; y < 3; y++)
					{
						if (s[x][y] == 0)
						{
							s[x][y] = 2;
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
					s[x][y] = 2;
					breaktf = 1;
					break;
				}
			}
			if (breaktf == 1) break;
		}
	}

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
	InputBox(z, 3, "选择游戏模式 电脑模式（0） 双人模式（1） 结束游戏（2）");
	// 将用户输入转换为数字
	sscanf(z, "%d", &over);
	if (over == 0)
		{
		InputBox(choicemode, 3, "选择电脑难度 简单模式(0) 普通模式（1）");
		sscanf(choicemode, "%d", &mode);
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
		sprintf(a, _T("%05d"), point.x);
		settextcolor(BLACK);
		outtextxy(Unitlength * 5, Unitlength * 5, a);//横坐标
		sprintf(a, _T("%05d"), point.y);//纵坐标
		outtextxy(Unitlength * 5, Unitlength * 6, a);
		sprintf(a, _T("%05d"), Array_x1);
		outtextxy(Unitlength * 5, Unitlength * 7, a);
		sprintf(a, _T("%05d"), Array_y1);//纵坐标
		outtextxy(Unitlength * 5, Unitlength * 7.5, a);

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
									s[i][j] = 1;
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
									s[i][j] = 1;
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
									s[i][j] = 2;
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
		}
	}
}


int check()
{
	char tellWin[] = "恭喜你赢了!";
	char tellLoser[] = "很遗憾,你输了.";
	char tellDraw[] = "打平！";
	for (int x = 0; x < 3; x++)
	{
		if (s[x][0] == 1 && s[x][1] == 1 && s[x][2] == 1)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellWin);
			}
			if (over == 2) { cout << p1.getName() + "赢了！强！" << endl << endl; }

			jieshu = true;
			return 0;
			break;
		}
		if (s[x][0] == 2 && s[x][1] == 2 && s[x][2] == 2)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellLoser);
			}
			if (over == 2) { cout << p2.getName() + "赢了！强！" << endl << endl; }
			jieshu = true;
			return 0;
			break;
		}
	}
	for (int x = 0; x < 3; x++)
	{
		if (s[0][x] == 1 && s[1][x] == 1 && s[2][x] == 1)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellWin);
			}
			if (over == 2) { cout << p1.getName() + "赢了！强！" << endl << endl; }
			jieshu = true;
			return 0;
			break;
		}
		if (s[0][x] == 2 && s[1][x] == 2 && s[2][x] == 2)
		{
			if (over == 0) {
				settextstyle(Unitlength, 0, _T("黑体"));
				settextcolor(RED);
				outtextxy(Unitlength, Unitlength * 5, tellLoser);
			}
			if (over == 2) { cout << p2.getName() + "赢了！强！" << endl << endl; }
			jieshu = true;
			return 0;
			break;
		}
	}


	if (s[0][0] == 1 && s[1][1] == 1 && s[2][2] == 1 || s[2][0] == 1 && s[1][1] == 1 && s[0][2] == 1)
	{
		if (over == 0) {
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellWin);
		}
		if (over == 2) { cout << p1.getName() + "赢了！强！" << endl << endl; }
		jieshu = true;
		return 0;
	}
	else if (s[0][0] == 2 && s[1][1] == 2 && s[2][2] == 2 || s[2][0] == 2 && s[1][1] == 2 && s[0][2] == 2)
	{
		if (over == 0) {
			settextstyle(Unitlength, 0, _T("黑体"));
			settextcolor(RED);
			outtextxy(Unitlength, Unitlength * 5, tellLoser);
		}
		if (over == 2) { cout << p2.getName() + "赢了！强！" << endl << endl; }
		return 0;
	}

	else
	{
		int count = 0;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (s[x][y] == 1 || s[x][y] == 2) count++;
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


int main()
{

	Initialize();


	while (!jieshu)
	{
		User_relatedinput();
		check();
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

		while (jieshu == false)
		{
			bool inputtf = true;
			if (tf % 2 == 0)
			{
				while (inputtf)
				{
					cout << p1.getName() + "你想下在哪一步?" << endl;
					cout << "行: ";
					cin >> row;
					cout << "列: ";
					cin >> column;
					row--;
					column--;
					if (row < 0 || row >= 3 || column < 0 || column >= 3 || s[row][column] != 0)
					{
						cout << "啊，那里不行~" << endl;
					}
					else inputtf = false;
				}
				s[row][column] = 1;
			}
			else {
				cout << p2.getName() + "你想下在哪一步？" << endl;
				cout << "行: ";
				cin >> row;
				cout << "列: ";
				cin >> column;
				row--;
				column--;
				if (row < 0 || row >= 3 || column < 0 || column >= 3 || s[row][column] != 0)
				{
					cout << "啊，哪里不行~" << endl; tf--;
				}

				else s[row][column] = 2;
			};


			check();
			tf++;
		}
		cout << "如果你想再玩一次请扣 2, 不想就扣 1: ";
		cin >> over;
	}
	return 0;
}

