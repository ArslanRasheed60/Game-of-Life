#include <iostream>
#include "GameOfLife.h";
#include "Coins.h";
#include "mygraphics.h"
#include "myconsole.h";

using namespace std;

static bool flag_7 = false;
static bool flag_9 = false;
static bool flag_11 = false;
static bool win_flag = false;

int main()
{
	Maximized();
	cout << "  *****************************************************************************\n";
	cout << "  ***                                                                       ***\n";
	cout << "  ***                          Game Of Life                                 ***\n";
	cout << "  ***                                                                       ***\n";
	cout << "  *****************************************************************************\n";

	cout << "\n1: Load Previous Game: ";
	cout << "\n2: Start New Game: ";
	cout << "\n3: Exit: ";
	cout << "\nEnter choice:  ";
	int choice_1 = 0;
	cin >> choice_1;
	while (choice_1 < 1 || choice_1 > 3)
	{
		cout << "\n *****  INVALID CHOICE *****  Enter Again:  ";
		cin >> choice_1;
	}
	if (choice_1 == 1)
	{
		while (true)
		{
			cout << "\n\n*-*-*-*-* Game Loaded Successfully *-*-*-*-*";
			cout << "\n\nPlayer 1 move starts from bottom left to right and to upward till goal: ";
			cout << "\nPlayer 2 move starts from top right to left and to downward till goal: ";
			Sleep(3000);
			Gameoflife board_2;
			board_2.read_data();

			while (true)
			{
				system("cls");
				board_2.output();
				cout << "\nPlayer 1 turn:  ";
				board_2.getting_player_1_move();
				if (board_2.exit == 'e')
				{
					
					break;
				}
				if (board_2.win_check() == true)					//winning check
				{
					if (board_2.get_size() == 5)						//moving to the next level
					{
						flag_7 = true;
					}
					else if (board_2.get_size() == 7)
					{
						flag_7 = false;
						flag_9 = true;
					}
					else if (board_2.get_size() == 9)
					{
						flag_9 = false;
						flag_11 = true;
					}
					else
					{
						flag_11 = false;
					}
					break;
				}
				system("cls");
				board_2.output();
				cout << "\nPlayer 2 turn:  ";
				board_2.getting_player_2_move();
				if (board_2.exit == 'e')
				{
					
					break;
				}
				if (board_2.win_check() == true)					//winning check
				{
					if (board_2.get_size() == 5)						//moving to the next level
					{
						flag_7 = true;
					}
					else if (board_2.get_size() == 7)
					{
						flag_7 = false;
						flag_9 = true;
					}
					else if (board_2.get_size() == 9)
					{
						flag_9 = false;
						flag_11 = true;
					}
					else
					{
						flag_11 = false;
					}
					break;
				}
			}
			if (board_2.win_check() == false)
			{
				char save = 0;
				cout << "\n\nTo save the game press 's' for exit press 'e': ";
				cin >> save;
				while (save != 's' && save != 'e')
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> save;
				}
				if (save == 's')
				{
					board_2.Save_data();							//save data
					cout << "\n\n**** Game Saved Successfully ****";
					break;
				}
				else
				{
					cout << "\n\n***** Game Exited *****";
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (choice_1 == 2)
	{
		while (true)
		{
			cout << "\n\n*-*-*-*-* New Game Started *-*-*-*-*";
			cout << "\n\nPlayer 1 move starts from bottom left to right and to upward till goal: ";
			cout << "\nPlayer 2 move starts from top right to left and to downward till goal: ";
			Sleep(3000);
			Gameoflife board_1;
			board_1.row_of_player_1 = board_1.get_size() - 1;
			board_1.col_of_player_1 = 0;
			board_1.row_of_player_2 = 0;
			board_1.col_of_player_2 = board_1.get_size() - 1;

			board_1.set_object_in_board(board_1.row_of_player_1, board_1.col_of_player_1, board_1.player_id);
			board_1.set_object_in_board(board_1.row_of_player_2, board_1.col_of_player_2, board_1.player_id);

			while (true)
			{
				
				system("cls");
				board_1.output();
				cout << "\nPlayer 1 turn:  ";
				board_1.getting_player_1_move();
				if (board_1.exit == 'e')
				{
					
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 5)						//moving to the next level
					{
						flag_7 = true;
					}
					break;
				}
				system("cls");
				board_1.output();
				cout << "\nPlayer 2 turn:  ";
				board_1.getting_player_2_move();
				if (board_1.exit == 'e')
				{
					
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 5)						//moving to the next level
					{
						flag_7 = true;
					}
					break;
				}
			}
			if (board_1.win_check() == false)
			{
				char save = 0;
				cout << "\n\nTo save the game press 's' for exit press 'e': ";
				cin >> save;
				while (save != 's' && save != 'e')
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> save;
				}
				if (save == 's')
				{
					board_1.Save_data();							//save data
					cout << "\n\n**** Game Saved Successfully ****";
					break;
				}
				else
				{
					cout << "\n\n***** Game Exited *****";
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (choice_1 == 3)
	{
		cout << "\n  **  Exited  **  ";
	}

	//level 7
	if (flag_7 == true)
	{
		while (true)
		{
			cout << "\n\n*-*-*-*-* New Game Started of 7 by 7*-*-*-*-*";
			cout << "\n\nPlayer 1 move starts from bottom left to right and to upward till goal: ";
			cout << "\nPlayer 2 move starts from top right to left and to downward till goal: ";
			Sleep(3000);
			Gameoflife board_1(7);

			board_1.row_of_player_1 = board_1.get_size() - 1;
			board_1.col_of_player_1 = 0;
			board_1.row_of_player_2 = 0;
			board_1.col_of_player_2 = board_1.get_size() - 1;

			board_1.set_object_in_board(board_1.row_of_player_1, board_1.col_of_player_1, board_1.player_id);
			board_1.set_object_in_board(board_1.row_of_player_2, board_1.col_of_player_2, board_1.player_id);

			while (true)
			{

				system("cls");
				board_1.output();
				cout << "\nPlayer 1 turn:  ";
				board_1.getting_player_1_move();
				if (board_1.exit == 'e')
				{
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 7)						//moving to the next level
					{
						flag_7 = false;
						flag_9 = true;
					}
					break;
				}
				system("cls");
				board_1.output();
				cout << "\nPlayer 2 turn:  ";
				board_1.getting_player_2_move();
				if (board_1.exit == 'e')
				{
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 7)						//moving to the next level
					{
						flag_7 = false;
						flag_9 = true;
					}
					break;
				}
			}
			if (board_1.win_check() == false)
			{
				char save = 0;
				cout << "\n\nTo save the game press 's' for exit press 'e': ";
				cin >> save;
				while (save != 's' && save != 'e')
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> save;
				}
				if (save == 's')
				{
					board_1.Save_data();							//save data
					cout << "\n\n**** Game Saved Successfully ****";
					break;
				}
				else
				{
					cout << "\n\n***** Game Exited *****";
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	//level 9
	if (flag_9 == true)
	{
		while (true)
		{
			cout << "\n\n*-*-*-*-* New Game Started of 9 by 9*-*-*-*-*";
			cout << "\n\nPlayer 1 move starts from bottom left to right and to upward till goal: ";
			cout << "\nPlayer 2 move starts from top right to left and to downward till goal: ";
			Sleep(3000);
			Gameoflife board_1(9);

			board_1.row_of_player_1 = board_1.get_size() - 1;
			board_1.col_of_player_1 = 0;
			board_1.row_of_player_2 = 0;
			board_1.col_of_player_2 = board_1.get_size() - 1;

			board_1.set_object_in_board(board_1.row_of_player_1, board_1.col_of_player_1, board_1.player_id);
			board_1.set_object_in_board(board_1.row_of_player_2, board_1.col_of_player_2, board_1.player_id);

			while (true)
			{

				system("cls");
				board_1.output();
				cout << "\nPlayer 1 turn:  ";
				board_1.getting_player_1_move();
				if (board_1.exit == 'e')
				{
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 9)						//moving to the next level
					{
						flag_9 = false;
						flag_11 = true;
					}
					break;
				}
				system("cls");
				board_1.output();
				cout << "\nPlayer 2 turn:  ";
				board_1.getting_player_2_move();
				if (board_1.exit == 'e')
				{
					
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 9)						//moving to the next level
					{
						flag_9 = false;
						flag_11 = true;
					}
					break;
				}
			}
			if (board_1.win_check() == false)
			{
				char save = 0;
				cout << "\n\nTo save the game press 's' for exit press 'e': ";
				cin >> save;
				while (save != 's' && save != 'e')
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> save;
				}
				if (save == 's')
				{
					board_1.Save_data();							//save data
					cout << "\n\n**** Game Saved Successfully ****";
					break;
				}
				else
				{
					cout << "\n\n***** Game Exited *****";
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	//level 11
	if (flag_11 == true)
	{
		while (true)
		{
			cout << "\n\n*-*-*-*-* New Game Started of 11 by 11*-*-*-*-*";
			cout << "\n\nPlayer 1 move starts from bottom left to right and to upward till goal: ";
			cout << "\nPlayer 2 move starts from top right to left and to downward till goal: ";
			Sleep(3000);
			Gameoflife board_1(11);

			board_1.row_of_player_1 = board_1.get_size() - 1;
			board_1.col_of_player_1 = 0;
			board_1.row_of_player_2 = 0;
			board_1.col_of_player_2 = board_1.get_size() - 1;

			board_1.set_object_in_board(board_1.row_of_player_1, board_1.col_of_player_1, board_1.player_id);
			board_1.set_object_in_board(board_1.row_of_player_2, board_1.col_of_player_2, board_1.player_id);

			while (true)
			{

				system("cls");
				board_1.output();
				cout << "\nPlayer 1 turn:  ";
				board_1.getting_player_1_move();
				if (board_1.exit == 'e')
				{
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 11)						//moving to the next level
					{
						flag_11 = false;
						cout << "\n\n ************ (  Game Ended  ) *************\n";
					}
					break;
				}
				system("cls");
				board_1.output();
				cout << "\nPlayer 2 turn:  ";
				board_1.getting_player_2_move();
				if (board_1.exit == 'e')
				{
					break;
				}
				if (board_1.win_check() == true)					//winning check
				{
					if (board_1.get_size() == 11)						//moving to the next level
					{
						flag_11 = false;
						cout << "\n\n ************ (  Game Ended  ) *************\n";
					}
					break;
				}
			}
			if (board_1.win_check() == false)
			{
				char save = 0;
				cout << "\n\nTo save the game press 's' for exit press 'e': ";
				cin >> save;
				while (save != 's' && save != 'e')
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> save;
				}
				if (save == 's')
				{
					board_1.Save_data();							//save data
					cout << "\n\n**** Game Saved Successfully ****";
					break;
				}
				else
				{
					cout << "\n\n***** Game Exited *****";
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

}