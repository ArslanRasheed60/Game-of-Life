//#include <iostream>
//#include "myconsole.h"
//#include "mygraphics.h"
//#include <time.h>
//#include <fstream>
//using namespace std;
//int const row = 9, col = 9;
//
//void graphical_output(int board[][col])
//{
//	int c_count = 0;
//	int y_incre = 70;
//	int x_incre = 70;
//	for (int i = 0; i < row; i++)								//graphical output
//	{
//		x_incre = 70;
//		for (int j = 0; j < col; j++)
//		{
//			if (c_count > (row) * (col) / 2)
//			{
//				myRect(700 + x_incre, 70 + y_incre, 770 + x_incre, 140 + y_incre, RGB(255, 255, 255), RGB(255, 0, 64));
//
//				if (board[i][j] == 1)				//gold coin printing
//				{
//					myEllipse(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(255, 255, 0), RGB(255, 255, 0));
//				}
//				else if (board[i][j] == 2)			//silver coin printing
//				{
//					myEllipse(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(192, 192, 192), RGB(192, 192, 192));
//				}
//				else if (board[i][j] == 14)			//player printing
//				{
//					myEllipse(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(0, 215, 100), RGB(77, 0, 0));
//				}
//				else if (board[i][j] == 7)			//fire printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(255, 255, 0), RGB(255, 128, 0));
//				}
//				else if (board[i][j] == 8)			//snake printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(255, 191, 0), RGB(0, 255, 128));
//				}
//				else if (board[i][j] == 9)			//ghost printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(26, 0, 0), RGB(172, 83, 83));
//				}
//				else if (board[i][j] == 10)			//lion printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(232, 235, 102), RGB(255, 35, 35));
//				}
//				else if (board[i][j] == 11)			//lock printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(111, 117, 102), RGB(111, 42, 102));
//				}
//
//
//			}
//			else if (c_count == (row) * (col) / 2)
//			{
//				myRect(700 + x_incre, 70 + y_incre, 770 + x_incre, 140 + y_incre, RGB(255, 255, 255), RGB(0, 255, 0));
//			}
//			else
//			{
//				myRect(700 + x_incre, 70 + y_incre, 770 + x_incre, 140 + y_incre, RGB(255, 255, 255), RGB(0, 0, 255));
//
//				if (board[i][j] == 1)					//gold coin printing
//				{
//					myEllipse(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(255, 255, 0), RGB(255, 255, 0));
//				}
//				else if (board[i][j] == 2)				//silver coin printing
//				{
//					myEllipse(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(192, 192, 192), RGB(192, 192, 192));
//				}
//				else if (board[i][j] == 14)			//player printing
//				{
//					myEllipse(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(0, 215, 100), RGB(77, 0, 0));
//				}
//				else if (board[i][j] == 7)			//fire printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(255, 255, 0), RGB(255, 128, 0));
//				}
//				else if (board[i][j] == 8)			//snake printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(255, 191, 0), RGB(0, 255, 128));
//				}
//				else if (board[i][j] == 9)			//ghost printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(26, 0, 0), RGB(172, 83, 83));
//				}
//				else if (board[i][j] == 10)			//lion printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(232, 235, 102), RGB(255, 35, 35));
//				}
//				else if (board[i][j] == 11)			//lock printing
//				{
//					myRect(715 + x_incre, 85 + y_incre, 755 + x_incre, 125 + y_incre, RGB(111, 117, 102), RGB(111, 42, 102));
//				}
//
//			}
//			c_count++;
//			x_incre = x_incre + 70;
//		}
//		y_incre = y_incre + 70;
//	}
//
//}
//
//void fileinput(int arr[][col])
//{
//	ifstream fin;
//	fin.open("test.txt");
//	if (!fin)
//	{
//		cout << "error";
//	}
//	else
//	{
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				fin >> arr[i][j];
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[row][col];
//	fileinput(arr);
//
//	Maximized();
//	graphical_output(arr);
//	Sleep(50000);
//	system("pause");
//}