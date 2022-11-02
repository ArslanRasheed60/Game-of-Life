#include "GameOfLife.h";
#include "Coins.h";
#include "hurdle.h";
#include "player.h";
#include "mygraphics.h";
#include "myconsole.h";
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int Gameoflife::player_id = 14;
int Gameoflife::row_of_player_1 = 0;
int Gameoflife::col_of_player_1 = 0;
int Gameoflife::row_of_player_2 = 0;
int Gameoflife::col_of_player_2 = 0;
char Gameoflife::exit = '\0';

int Gameoflife::p_1_backward = 0;
int Gameoflife::p_1_forward = 1;
int Gameoflife::p_1_count = 0;
Player_obj Gameoflife::player_1;						//player 1 object
bool Gameoflife::p_1_flag = false;

int Gameoflife::p_2_backward = 0;
int Gameoflife::p_2_forward = 1;
int Gameoflife::p_2_count = 0;
Player_obj Gameoflife::player_2;						//player 2 object
bool Gameoflife::p_2_flag = false;


//storage of previous position when hurdles come
int Gameoflife::temp_row_of_player_1 = 0;
int Gameoflife::temp_col_of_player_1 = 0;
int Gameoflife::temp_row_of_player_2 = 0;
int Gameoflife::temp_col_of_player_2 = 0;

Gameoflife::Gameoflife()					//default board size 5*5
{
	size = new int(5);
	board = new int* [*size];
	for (int i = 0; i < *size; i++)
	{
		board[i] = new int[*size];
	}
	//random coins generator
	int count_coin = 0;
	int counter = 0;
	srand(time(0));

	if (rand() % 2 == 0)
	{
		while (count_coin != *size)
		{
			count_coin = 0;
			for (int i = 0; i < (*size) / 2; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != (((*size) * (*size)) / 2) && counter != 0 )
					{
						if (count_coin != *size )
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
		count_coin = 0;
		for (int m = *size / 2, n = 0; n < *size; n++)
		{
			board[m][n] = 0;
		}
		while (count_coin != *size)
		{
			count_coin = 0;
			for (int i = (*size/2) + 1; i < *size; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != ((*size) * (*size))-1)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
	}
	else
	{
		while (count_coin != *size-1)
		{
			count_coin = 0;
			for (int i = 0; i < (*size) / 2; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != (((*size) * (*size)) / 2) && counter != 0)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
		count_coin = 0;
		for (int m = *size / 2, n = 0; n < *size; n++)
		{
			board[m][n] = 0;
		}
		while (count_coin != *size - 1)
		{
			count_coin = 0;
			for (int i = (*size / 2) + 1; i < *size; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != ((*size) * (*size)) - 1)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
		board[*size / 2][*size / 2 - 1] = 1;
		board[*size / 2][*size / 2 + 1] = 1;
	}

	board[*size / 2][*size / 2] = 15;
	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size; j++)
		{
			if (board[i][j] != 1 && board[i][j] != 2 && board[i][j] != 15)
				board[i][j] = 0;
		}
	}

}

Gameoflife::Gameoflife(int siz)	 //update board on every win
{
	size = new int(siz);
	board = new int* [siz];
	for (int i = 0; i < *size; i++)
	{
		board[i] = new int[*size];
	}

	//random coins generator
	int count_coin = 0;
	int counter = 0;
	srand(time(0));

	if (rand() % 2 == 0)
	{
		while (count_coin != *size)
		{
			count_coin = 0;
			for (int i = 0; i < (*size) / 2; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != (((*size) * (*size)) / 2) && counter != 0)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
		count_coin = 0;
		for (int m = *size / 2, n = 0; n < *size; n++)
		{
			board[m][n] = 0;
		}
		while (count_coin != *size)
		{
			count_coin = 0;
			for (int i = (*size / 2) + 1; i < *size; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != ((*size) * (*size)) - 1)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
	}
	else
	{
		while (count_coin != *size - 1)
		{
			count_coin = 0;
			for (int i = 0; i < (*size) / 2; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != (((*size) * (*size)) / 2) && counter != 0)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
		count_coin = 0;
		for (int m = *size / 2, n = 0; n < *size; n++)
		{
			board[m][n] = 0;
		}
		while (count_coin != *size - 1)
		{
			count_coin = 0;
			for (int i = (*size / 2) + 1; i < *size; i++)
			{
				for (int j = 0; j < *size; j++)
				{
					if (counter != ((*size) * (*size)) - 1)
					{
						if (count_coin != *size)
						{
							board[i][j] = rand() % 5;
							if (board[i][j] == 1 || board[i][j] == 2)
							{
								count_coin++;
							}
						}
						else
						{
							board[i][j] = 0;
						}
					}
					counter++;
				}
			}
		}
		board[*size / 2][*size / 2 - 1] = 1;
		board[*size / 2][*size / 2 + 1] = 1;
	}

	board[*size / 2][*size / 2] = 15;
	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size; j++)
		{
			if (board[i][j] != 1 && board[i][j] != 2 && board[i][j] != 15)
				board[i][j] = 0;
		}
	}
}

int Gameoflife::get_size()
{
	return *size;
}

void Gameoflife::set_object_in_board(int r, int c, int val)
{
	board[r][c] = val;
}
int Gameoflife::get_object_from_board(int r, int c)
{
	return board[r][c];
}
					//player 1 will place hurdle on player 2's board
void Gameoflife::player_1_place_hurdle_check(int r, int c, int hurdle_id)
{
	int tempo = ((*size) * (*size)) / 2;
	r--;
	c--;
	int block_num =  (*size) * r + c;
	if (block_num < tempo )
	{
		board[r][c] = hurdle_id;
		cout << "\n-------- Hurdle Successfully placed --------";		
	}
	else
	{
		cout << "\n------- Invalid block ---------";
	}
}

void Gameoflife::move_validation_check(int& nn)
{
	while (nn < 1 || nn > *size)
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
		cin >> nn;
	}
}

void Gameoflife::getting_player_1_move()
{
	cout << "\nYou are on " << row_of_player_1 + 1 << " row and " << col_of_player_1 + 1 << " column ";

	cout << "\n\n>>> player 1 Points Status <<<\n";								//player point
	cout << "player 1 currently has " << player_1.get_player_points() << " points.";

	cout << "\n\n>>>  player 1 Coins Status  <<<";
	player_1.display_player_coins();								//player coins status

	cout << "\n\n>>>  Player 1 Garage <<<\n";
	player_1.display_player_objects();								//player silver status

	cout << "\n\n *** Want to buy something? ";
	int n = 0;
	cout << "\n1: Helping objects: \n2: Obstacles: \n-1: To buy nothing: \nEnter choice:   ";
	cin >> n;
	while (n != 1 && n != 2 && n != -1)
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: "; 
		cin >> n;
	}
	if (n == 1)
	{
		int n_2 = 0;
		cout << "\n\nIn Helping Objects: ";
		cout << "\n1: Sword  --> Lose 40 points  --> To kill snake or lion --> Used only twice ";
		cout << "\n2: Shield --> Lose 30 points  --> To protect from ghost --> Used only once ";
		cout << "\n3: Water  --> Lose 50 points  --> To protect from fire  --> Used only once ";
		cout << "\n4: key    --> Lose 70 points  --> To unlock the door    --> Used only once ";
		cout << "\nEnter choice: ";
		cin >> n_2;
		while (n_2 < 1 || n_2 > 4)
		{
			cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
			cin >> n_2;
		}
		if (n_2 == 1)
		{
			// for sword
			if (player_1.get_player_points() >= player_1.get_sword_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_sword_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_sword_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 4);
						player_1.set_sword_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins() * player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins()* player_1.get_silver_points() >= player_1.get_sword_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_sword_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 8);
						player_1.set_sword_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins() * player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else            //buy an object from both silver and gold coins
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 8;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_sword_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins() * player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_sword_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_sword_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 8);
						player_1.set_sword_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins() * player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_sword_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_sword_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 4);
						player_1.set_sword_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins() * player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else             //buy an object from both silver and gold coins
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 8;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_sword_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins() * player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
					
				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_2 == 2)
		{
			//for shield
			if (player_1.get_player_points() >= player_1.get_shield_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_shield_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_shield_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 3);
						player_1.set_shield_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_shield_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_shield_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 6);
						player_1.set_shield_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_shield_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_shield_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_shield_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 6);
						player_1.set_shield_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_shield_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_shield_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 3);
						player_1.set_shield_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_shield_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_2 == 3)
		{
			//for water
			if (player_1.get_player_points() >= player_1.get_water_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_water_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_water_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 5);
						player_1.set_water_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_water_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_water_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 10);
						player_1.set_water_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_water_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_water_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_water_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 10);
						player_1.set_water_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_water_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_water_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 5);
						player_1.set_water_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_water_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_2 == 4)
		{
			//for key
			if (player_1.get_player_points() >= player_1.get_key_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_key_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_key_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 7);
						player_1.set_key_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_key_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_key_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 14);
						player_1.set_key_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 14;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_key_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_key_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_key_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 14);
						player_1.set_key_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_key_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_key_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 7);
						player_1.set_key_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 14;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_key_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
	}
	else if (n == 2)
	{
		int n_3 = 0;
		cout << "\n\nIn Obstacles: ";
		cout << "\n1: Fire   --> Lose 50 points  --> Fire up the cell of opponent  --> block for 2 turns ";
		cout << "\n2: Snake  --> Lose 30 points  --> Send opponent back to 3 cells --> block for 3 turns ";
		cout << "\n3: Ghost  --> Lose 20 points  -->                               --> Block for 1 turn  ";
		cout << "\n4: Lion   --> Lose 50 points  --> buy Only using Gold coins     --> block for 4 turns ";
		cout << "\n5: Lock   --> Lose 60 points  --> buy Only using Silver Coins   --> Block for a key ";
		cout << "\nEnter choice: ";
		cin >> n_3;
		while (n_3<1 || n_3 > 5)
		{
			cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
			cin >> n_3;
		}
		if (n_3 == 1)
		{
			//for fire
			if (player_1.get_player_points() >= player_1.get_fire_points() && player_1.get_fire_count() == 0)
			{
				int n_3_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_3_1;
				while (n_3_1 != 1 && n_3_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_3_1;
				}
				if (n_3_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_fire_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_fire_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 5);
						player_1.set_fire_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_fire_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_fire_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 10);
						player_1.set_fire_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_fire_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_3_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_fire_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_fire_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 10);
						player_1.set_fire_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_fire_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_fire_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 5);
						player_1.set_fire_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_fire_count(2);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}

			}
			else if (player_1.get_player_points() >= player_1.get_fire_points() && player_1.get_fire_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*"; 
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 2)
		{
			//snake
			if (player_1.get_player_points() >= player_1.get_snake_points() && player_1.get_snake_count() == 0)
			{
				int n_3_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_3_1;
				while (n_3_1 != 1 && n_3_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_3_1;
				}
				if (n_3_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_snake_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_snake_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 3);
						player_1.set_snake_count(3);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_snake_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_snake_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 6);
						player_1.set_snake_count(3);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_snake_count(3);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_3_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_snake_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_snake_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 6);
						player_1.set_snake_count(3);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_snake_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_snake_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 3);
						player_1.set_snake_count(3);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_snake_count(3);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}

			}
			else if (player_1.get_player_points() >= player_1.get_snake_points() && player_1.get_snake_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 3)
		{
			//ghost
			if (player_1.get_player_points() >= player_1.get_ghost_points() && player_1.get_ghost_count() == 0)
			{
				int n_3_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_3_1;
				while (n_3_1 != 1 && n_3_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_3_1;
				}
				if (n_3_1 == 1)				//player want to buy from gold coins
				{
					if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_ghost_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_ghost_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 2);
						player_1.set_ghost_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_ghost_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_ghost_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 4);
						player_1.set_ghost_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 4;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_ghost_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_3_1 == 2)				//if player want to buy from silver coins
				{
					if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_ghost_points())
					{
						player_1.set_player_points(player_1.get_player_points() - player_1.get_ghost_points());
						player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 4);
						player_1.set_ghost_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_ghost_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_1.set_player_points(player_1.get_player_points() - player_1.get_ghost_points());
						player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 2);
						player_1.set_ghost_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_1.get_player_gold_coins() * 2;
						int t_silver = player_1.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_1.set_player_gold_coins(0);
						player_1.set_player_silver_coins(t_sum);
						player_1.set_ghost_count(1);
						player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}

			}
			else if (player_1.get_player_points() >= player_1.get_ghost_points() && player_1.get_ghost_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 4)
		{
			//lion
			if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_lion_points() && player_1.get_lion_count() == 0)
			{
				player_1.set_player_points(player_1.get_player_points() - player_1.get_lion_points());
				player_1.set_player_gold_coins(player_1.get_player_gold_coins() - 5);
				player_1.set_lion_count(4);
				player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
				cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
			}
			else if (player_1.get_player_gold_coins() * player_1.get_gold_points() >= player_1.get_lion_points() && player_1.get_lion_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Gold Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 5)
		{
			//lock
			if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_lock_points() && player_1.get_lock_count() == 0)
			{
				player_1.set_player_points(player_1.get_player_points() - player_1.get_lock_points());
				player_1.set_player_silver_coins(player_1.get_player_silver_coins() - 12);
				player_1.set_lock_count(1);
				player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
				cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
			}
			else if (player_1.get_player_silver_coins() * player_1.get_silver_points() >= player_1.get_lock_points() && player_1.get_lock_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Silver Points   *-*-*-*-*-*";
			}
		}
	}
	Sleep(1000);
	system("cls");
	output();

	cout << "\nPlayer 1: ";
	cout << "\nYou are on " << row_of_player_1 + 1 << " row and " << col_of_player_1 + 1 << " column ";

	cout << "\n\n>>> player 1 Points Status <<<\n";								//player point
	cout << "player 1 currently has " << player_1.get_player_points() << " points.";

	cout << "\n\n>>>  player 1 Coins Status  <<<";
	player_1.display_player_coins();								//player coins status

	cout << "\n\n>>>  Player 1 Garage <<<\n";
	player_1.display_player_objects();								//player silver status

	/////////////////////////////////////////////////////////////////
	cout << "\n\nWant to place hurdle or not:  press 'y' for yes and 'n' for no: ";
	char ques_hurd;
	cin >> ques_hurd;
	while (ques_hurd != 'y' && ques_hurd != 'n')
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
		cin >> ques_hurd;
	}
	if (ques_hurd == 'y')
	{
		cout << "\nEnter Which hurdle you want to place: ";
		cout << "\n1) Fire..    2) snake ..    3) ghost ..    4)lion ..    5)lock:  ";
		int choice_hurdle;
		cout << "\nEnter choice: ";
		cin >> choice_hurdle;
		if (choice_hurdle == 1)					//fire choice
		{
			if (player_1.get_fire_count() > 0 )
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_1_place_hurdle_check(hurdle_row, hurdle_col, player_1.get_fire_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 2)					//snake choice
		{
			if (player_1.get_snake_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_1_place_hurdle_check(hurdle_row, hurdle_col, player_1.get_snake_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 3)					//ghost choice
		{
			if (player_1.get_ghost_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_1_place_hurdle_check(hurdle_row, hurdle_col, player_1.get_ghost_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 4)					//lion choice
		{
			if (player_1.get_lion_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_1_place_hurdle_check(hurdle_row, hurdle_col, player_1.get_lion_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 5)					//lock choice
		{
			if (player_1.get_lock_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_1_place_hurdle_check(hurdle_row, hurdle_col, player_1.get_lock_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
	}

	Sleep(1000);
	system("cls");
	output();

	/////////////////////////////////////////////////////////////////
	cout << "\nPlayer 1: ";
	cout << "\n\nFor skip your turn press 's' or move to next block press 'n' and 'e' for exit:  ";
	char ch_1;
	cin >> ch_1;
	while (ch_1 != 's' && ch_1 != 'n' && ch_1 != 'e')
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
		cin >> ch_1;
	}
	if (ch_1 != 'e')
	{
		if (ch_1 == 's')
		{
			cout << "\n\n******  Turn Skipped  ****** ";
		}
		else
		{

			if (p_1_flag == false)
			{
				temp_row_of_player_1 = row_of_player_1;					//storage previous position
				temp_col_of_player_1 = col_of_player_1;

				board[row_of_player_1][col_of_player_1] = 22;
				int final_row = 0;

				if (p_1_count < (*size) * (*size) / 2)
				{
					if (col_of_player_1 < *size - 1 && p_1_forward == 1)
					{
						col_of_player_1++;
						p_1_count++;
					}
					else if (p_1_forward == 1)
					{		
						row_of_player_1--;
						p_1_forward = 0;
						p_1_backward = 1;
						p_1_count++;
					}
					else if (col_of_player_1 > 0 && p_1_backward == 1)
					{
						col_of_player_1--;
						p_1_count++;
					}
					else if (p_1_backward == 1)
					{
						row_of_player_1--;
						col_of_player_1 = *size - 1;
						p_1_count++;
					}
				}
			}
							//add gold and silver coins
			if (board[row_of_player_1][col_of_player_1] == 1)				//add gold coins 
			{
				player_1.set_player_gold_coins(player_1.get_player_gold_coins() + 10);
				player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
			}
			else if (board[row_of_player_1][col_of_player_1] == 2)			//add 
			{
				player_1.set_player_silver_coins(player_1.get_player_silver_coins() + 20);
				player_1.set_player_points((player_1.get_player_gold_coins()* player_1.get_gold_points()) + (player_1.get_player_silver_coins() * player_1.get_silver_points()));
			}
			//hurdle check here
			if (board[row_of_player_1][col_of_player_1] == player_2.get_fire_id())				//fire hurdle check
			{
				if (player_2.get_fire_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Water to remove fire or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_1.get_water_count() > 0)
						{
							cout << "\n\n ** You Successfully removed the Fire hurdle **";
							player_1.set_water_count(player_1.get_water_count() - 1);
							p_1_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Water to remove the fire hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's fire hurdle. ";
					player_2.set_fire_count(player_2.get_fire_count() - 1);
					if (p_1_flag == false)
					{
						board[temp_row_of_player_1][temp_col_of_player_1] = player_id;
					}
					p_1_flag = true;
				}
			}
			else if (board[row_of_player_1][col_of_player_1] == player_2.get_snake_id())				//snake check
			{
				if (player_2.get_snake_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Sword to kill snake or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_1.get_sword_count() > 0)
						{
							cout << "\n\n ** You Successfully kill the snake hurdle **";
							player_1.set_sword_count(player_1.get_sword_count() - 1);
							p_1_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Sword to kill the snake hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's snake hurdle. ";
					player_2.set_snake_count(player_2.get_snake_count() - 1);
					if (p_1_flag == false)
					{
						board[temp_row_of_player_1][temp_col_of_player_1] = player_id;
					}
					p_1_flag = true;
				}
			}
			else if (board[row_of_player_1][col_of_player_1] == player_2.get_ghost_id())				//ghost check
			{
				if (player_2.get_ghost_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Shield to protect from ghost or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_1.get_shield_count() > 0)
						{
							cout << "\n\n ** You Successfully remove the ghost hurdle **";
							player_1.set_shield_count(player_1.get_shield_count() - 1);
							p_1_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Shield to remove the ghost hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's ghost hurdle. ";
					player_2.set_ghost_count(player_2.get_ghost_count() - 1);
					if (p_1_flag == false)
					{
						board[temp_row_of_player_1][temp_col_of_player_1] = player_id;
					}
					p_1_flag = true;
				}
			}
			else if (board[row_of_player_1][col_of_player_1] == player_2.get_lion_id())				//lion check
			{
				if (player_2.get_lion_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Sword to kill lion or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_1.get_sword_count() > 0)
						{
							cout << "\n\n ** You Successfully remove the lion hurdle **";
							player_1.set_sword_count(player_1.get_sword_count() - 1);
							p_1_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Sword to remove the lion hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's lion hurdle. ";
					player_2.set_lion_count(player_2.get_lion_count() - 1);
					if (p_1_flag == false)
					{
						board[temp_row_of_player_1][temp_col_of_player_1] = player_id;
					}
					p_1_flag = true;
				}
			}
			else if (board[row_of_player_1][col_of_player_1] == player_2.get_lock_id())				//lock check
			{
				if (player_2.get_lock_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use key for lock or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_1.get_key_count() > 0)
						{
							cout << "\n\n ** You Successfully remove the lock hurdle **";
							player_1.set_key_count(player_1.get_key_count() - 1);
							p_1_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have key to remove the key hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's key hurdle. ";
					player_2.set_lock_count(player_2.get_lock_count() - 1);
					if (p_1_flag == false)
					{
						board[temp_row_of_player_1][temp_col_of_player_1] = player_id;
					}
					p_1_flag = true;
				}
			}
			
			if (p_1_flag == false)							//player movement to new cell
			{
				board[row_of_player_1][col_of_player_1] = player_id;
				board[temp_row_of_player_1][temp_col_of_player_1] = 22;
			}
		}
	}
	else
	{
		exit = ch_1;
	}
	Sleep(2000);
}
//blue color 12,22

										//player 2 will place hurdle on player 1's board
void Gameoflife::player_2_place_hurdle_check(int r, int c, int hurdle_id)
{
	int tempo = ((*size) * (*size)) / 2;
	r--;
	c--;
	int block_num = (*size) * r + c;
	if (block_num > tempo && block_num < (*size) * (*size))
	{
		board[r][c] = hurdle_id;
		cout << "\n-------- Hurdle Successfully placed --------";
	}
	else
	{
		cout << "\n------- Invalid block ---------";
	}
}


void Gameoflife::getting_player_2_move()
{
	cout << "\nYou are on " << row_of_player_2 + 1 << " row and " << col_of_player_2 + 1 << " column ";

	cout << "\n\n>>> player 2 Points Status <<<\n";								//player point
	cout << "player 2 currently has " << player_2.get_player_points() << " points.";

	cout << "\n\n>>>  player 2 Coins Status  <<<";
	player_2.display_player_coins();								//player coins status

	cout << "\n\n>>>  Player 2 Garage <<<\n";
	player_2.display_player_objects();								//player silver status

	cout << "\n\n *** Want to buy something? ";
	int n = 0;
	cout << "\n1: Helping objects: \n2: Obstacles: \n-1: To buy nothing: \nEnter choice:   ";
	cin >> n;
	while (n != 1 && n != 2 && n != -1)
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
		cin >> n;
	}
	if (n == 1)
	{
		int n_2 = 0;
		cout << "\n\nIn Helping Objects: ";
		cout << "\n1: Sword  --> Lose 40 points  --> To kill snake or lion --> Used only twice ";
		cout << "\n2: Shield --> Lose 30 points  --> To protect from ghost --> Used only once ";
		cout << "\n3: Water  --> Lose 50 points  --> To protect from fire  --> Used only once ";
		cout << "\n4: key    --> Lose 70 points  --> To unlock the door    --> Used only once ";
		cout << "\nEnter choice: ";
		cin >> n_2;
		while (n_2 < 1 || n_2 > 4)
		{
			cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
			cin >> n_2;
		}
		if (n_2 == 1)
		{
			// for sword
			if (player_2.get_player_points() >= player_2.get_sword_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_sword_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_sword_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 4);
						player_2.set_sword_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins() * player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_sword_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_sword_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 8);
						player_2.set_sword_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins() * player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else            //buy an object from both silver and gold coins
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 8;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_sword_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins() * player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_sword_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_sword_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 8);
						player_2.set_sword_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins() * player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_sword_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_sword_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 4);
						player_2.set_sword_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins() * player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else             //buy an object from both silver and gold coins
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 8;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_sword_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins() * player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_2 == 2)
		{
			//for shield
			if (player_2.get_player_points() >= player_2.get_shield_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_shield_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_shield_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 3);
						player_2.set_shield_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_shield_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_shield_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 6);
						player_2.set_shield_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_shield_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_shield_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_shield_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 6);
						player_2.set_shield_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_shield_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_shield_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 3);
						player_2.set_shield_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_shield_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_2 == 3)
		{
			//for water
			if (player_2.get_player_points() >= player_2.get_water_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_water_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_water_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 5);
						player_2.set_water_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_water_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_water_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 10);
						player_2.set_water_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_water_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_water_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_water_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 10);
						player_2.set_water_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_water_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_water_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 5);
						player_2.set_water_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_water_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_2 == 4)
		{
			//for key
			if (player_2.get_player_points() >= player_2.get_key_points())
			{
				int n_2_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_2_1;
				while (n_2_1 != 1 && n_2_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_2_1;
				}
				if (n_2_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_key_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_key_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 7);
						player_2.set_key_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_key_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_key_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 14);
						player_2.set_key_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 14;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_key_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_2_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_key_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_key_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 14);
						player_2.set_key_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_key_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_key_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 7);
						player_2.set_key_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 14;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_key_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
	}
	else if (n == 2)
	{
		int n_3 = 0;
		cout << "\n\nIn Obstacles: ";
		cout << "\n1: Fire   --> Lose 50 points  --> Fire up the cell of opponent  --> block for 2 turns ";
		cout << "\n2: Snake  --> Lose 30 points  --> Send opponent back to 3 cells --> block for 3 turns ";
		cout << "\n3: Ghost  --> Lose 20 points  -->                               --> Block for 1 turn  ";
		cout << "\n4: Lion   --> Lose 50 points  --> buy Only using Gold coins     --> block for 4 turns ";
		cout << "\n5: Lock   --> Lose 60 points  --> buy Only using Silver Coins   --> Block for a key ";
		cout << "\nEnter choice: ";
		cin >> n_3;
		while (n_3 < 1 || n_3 > 5)
		{
			cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
			cin >> n_3;
		}
		if (n_3 == 1)
		{
			//for fire
			if (player_2.get_player_points() >= player_2.get_fire_points() && player_2.get_fire_count() == 0)
			{
				int n_3_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_3_1;
				while (n_3_1 != 1 && n_3_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_3_1;
				}
				if (n_3_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_fire_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_fire_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 5);
						player_2.set_fire_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_fire_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_fire_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 10);
						player_2.set_fire_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_fire_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_3_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_fire_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_fire_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 10);
						player_2.set_fire_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_fire_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_fire_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 5);
						player_2.set_fire_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_fire_count(2);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}

			}
			else if (player_2.get_player_points() >= player_2.get_fire_points() && player_2.get_fire_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 2)
		{
			//snake
			if (player_2.get_player_points() >= player_2.get_snake_points() && player_2.get_snake_count() == 0)
			{
				int n_3_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_3_1;
				while (n_3_1 != 1 && n_3_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_3_1;
				}
				if (n_3_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_snake_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_snake_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 3);
						player_2.set_snake_count(3);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_snake_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_snake_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 6);
						player_2.set_snake_count(3);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_snake_count(3);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_3_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_snake_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_snake_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 6);
						player_2.set_snake_count(3);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_snake_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_snake_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 3);
						player_2.set_snake_count(3);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 6;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_snake_count(3);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}

			}
			else if (player_2.get_player_points() >= player_2.get_snake_points() && player_2.get_snake_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 3)
		{
			//ghost
			if (player_2.get_player_points() >= player_2.get_ghost_points() && player_2.get_ghost_count() == 0)
			{
				int n_3_1;
				cout << "\n\nWhich points You want to use? ";
				cout << "\n1: Gold coin Points ";
				cout << "\n2: Silver coin Points ";
				cout << "\nEnter Choice: ";
				cin >> n_3_1;
				while (n_3_1 != 1 && n_3_1 != 2)
				{
					cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
					cin >> n_3_1;
				}
				if (n_3_1 == 1)				//player want to buy from gold coins
				{
					if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_ghost_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_ghost_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 2);
						player_2.set_ghost_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_ghost_points())
					{
						cout << "\n ----- You Don't Have enough Gold coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_ghost_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 4);
						player_2.set_ghost_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 4;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_ghost_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}
				}
				else if (n_3_1 == 2)				//if player want to buy from silver coins
				{
					if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_ghost_points())
					{
						player_2.set_player_points(player_2.get_player_points() - player_2.get_ghost_points());
						player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 4);
						player_2.set_ghost_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
					}
					else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_ghost_points())
					{
						cout << "\n ----- You Don't Have enough Silver coins (points) ";
						player_2.set_player_points(player_2.get_player_points() - player_2.get_ghost_points());
						player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 2);
						player_2.set_ghost_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
					}
					else
					{
						int t_gold = player_2.get_player_gold_coins() * 2;
						int t_silver = player_2.get_player_silver_coins();
						int t_sum = t_gold + t_silver - 10;
						player_2.set_player_gold_coins(0);
						player_2.set_player_silver_coins(t_sum);
						player_2.set_ghost_count(1);
						player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
						cout << "\n\n***** Object Successfully bought from both *silver* and *gold* coins (points): ***** ";
					}

				}

			}
			else if (player_2.get_player_points() >= player_2.get_ghost_points() && player_2.get_ghost_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 4)
		{
			//lion
			if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_lion_points() && player_2.get_lion_count() == 0)
			{
				player_2.set_player_points(player_2.get_player_points() - player_2.get_lion_points());
				player_2.set_player_gold_coins(player_2.get_player_gold_coins() - 5);
				player_2.set_lion_count(4);
				player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
				cout << "\n\n***** Object Successfully bought from *gold* coins (points): ***** ";
			}
			else if (player_2.get_player_gold_coins() * player_2.get_gold_points() >= player_2.get_lion_points() && player_2.get_lion_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Gold Points   *-*-*-*-*-*";
			}
		}
		else if (n_3 == 5)
		{
			//lock
			if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_lock_points() && player_2.get_lock_count() == 0)
			{
				player_2.set_player_points(player_2.get_player_points() - player_2.get_lock_points());
				player_2.set_player_silver_coins(player_2.get_player_silver_coins() - 12);
				player_2.set_lock_count(1);
				player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
				cout << "\n\n***** Object Successfully bought from *silver* coins (points): ***** ";
			}
			else if (player_2.get_player_silver_coins() * player_2.get_silver_points() >= player_2.get_lock_points() && player_2.get_lock_count() > 0)
			{
				cout << "\n*-*-*-*-*-*   Hurdle already bought   *-*-*-*-*-*";
				cout << "\n*-*-*-*-*-*   First use it then buy again   *-*-*-*-*-*";
			}
			else
			{
				cout << "\n*-*-*-*-*-*   You Dont Have Enough Silver Points   *-*-*-*-*-*";
			}
		}
	}

	Sleep(1000);
	system("cls");
	output();

	cout << "\nPlayer 2";
	cout << "\nYou are on " << row_of_player_2 + 1 << " row and " << col_of_player_2 + 1 << " column ";

	cout << "\n\n>>> player 2 Points Status <<<\n";								//player point
	cout << "player 2 currently has " << player_2.get_player_points() << " points.";

	cout << "\n\n>>>  player 2 Coins Status  <<<";
	player_2.display_player_coins();								//player coins status

	cout << "\n\n>>>  Player 2 Garage <<<\n";
	player_2.display_player_objects();								//player silver status

	/////////////////////////////////////////////////////////////////
	cout << "\n\nWant to place hurdle or not:  press 'y' for yes and 'n' for no: ";
	char ques_hurd;
	cin >> ques_hurd;
	while (ques_hurd != 'y' && ques_hurd != 'n')
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
		cin >> ques_hurd;
	}
	if (ques_hurd == 'y')
	{
		cout << "\nEnter Which hurdle you want to place: ";
		cout << "\n1) Fire..    2) snake ..    3) ghost ..    4)lion ..    5)lock:  ";
		int choice_hurdle;
		cout << "\nEnter choice: ";
		cin >> choice_hurdle;
		if (choice_hurdle == 1)					//fire choice
		{
			if (player_2.get_fire_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_2_place_hurdle_check(hurdle_row, hurdle_col, player_2.get_fire_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 2)					//snake choice
		{
			if (player_2.get_snake_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_2_place_hurdle_check(hurdle_row, hurdle_col, player_2.get_snake_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 3)					//ghost choice
		{
			if (player_2.get_ghost_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_2_place_hurdle_check(hurdle_row, hurdle_col, player_2.get_ghost_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 4)					//lion choice
		{
			if (player_2.get_lion_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_2_place_hurdle_check(hurdle_row, hurdle_col, player_2.get_lion_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
		else if (choice_hurdle == 5)					//lock choice
		{
			if (player_2.get_lock_count() > 0)
			{
				cout << "\nAt which block of opponent you want to place hurdle: ";
				int hurdle_row, hurdle_col;
				cout << "\nEnter row (# 1,2,3 ... etc): ";
				cin >> hurdle_row;
				move_validation_check(hurdle_row);
				cout << "\nEnter col (# 1,2,3 ... etc): ";
				cin >> hurdle_col;
				move_validation_check(hurdle_col);
				player_2_place_hurdle_check(hurdle_row, hurdle_col, player_2.get_lock_id());
			}
			else
			{
				cout << "\n\n********  You Don't Have any hurdle ******** First buy hurdle and then place it *******";
			}
		}
	}

	Sleep(1000);
	system("cls");
	output();
	/////////////////////////////////////////////////////////////////
	cout << "\nPlayer 2: ";
	cout << "\n\nFor skip your turn press 's' or move to next block press 'n' and 'e' for exit:  ";
	char ch_2;
	cin >> ch_2;
	while (ch_2 != 's' && ch_2 != 'n' && ch_2 != 'e')
	{
		cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
		cin >> ch_2;
	}
	if (ch_2 != 'e')
	{
		if (ch_2 == 's')
		{
			cout << "\n\n******  Turn Skipped  ****** ";
		}
		else
		{
			
			if (p_2_flag == false)
			{
				temp_row_of_player_2 = row_of_player_2;				//player 2 previous movement storage
				temp_col_of_player_2 = col_of_player_2;

				board[row_of_player_2][col_of_player_2] = 23;
				int final_row = 0;

				if (p_2_count < (*size) * (*size) / 2)
				{
					if (col_of_player_2 > 0 && p_2_forward == 1)
					{
						col_of_player_2--;
						p_2_count++;
					}
					else if (p_2_forward == 1)
					{		
						row_of_player_2++;
						p_2_forward = 0;
						p_2_backward = 1;
						p_2_count++;
					}
					else if (col_of_player_2 < *size - 1 && p_2_backward == 1)
					{
						col_of_player_2++;
						p_2_count++;
					}
					else if (p_2_backward == 1)
					{
						row_of_player_2++;
						col_of_player_2 = 0;
						p_2_count++;
					}
				}
			}
								//add gold and silver coins
			if (board[row_of_player_2][col_of_player_2] == 1)				//add gold coins 
			{
				player_2.set_player_gold_coins(player_2.get_player_gold_coins() + 10);
				player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
			}
			else if (board[row_of_player_2][col_of_player_2] == 2)
			{
				player_2.set_player_silver_coins(player_2.get_player_silver_coins() + 20);
				player_2.set_player_points((player_2.get_player_gold_coins()* player_2.get_gold_points()) + (player_2.get_player_silver_coins() * player_2.get_silver_points()));
			}
			//check for coins and hurdles here

			if (board[row_of_player_2][col_of_player_2] == player_1.get_fire_id())				//fire hurdle check
			{
				if (player_1.get_fire_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Water to remove fire or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_2.get_water_count() > 0)
						{
							cout << "\n\n ** You Successfully removed the Fire hurdle **";
							player_2.set_water_count(player_2.get_water_count() - 1);
							p_2_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Water to remove the fire hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's fire hurdle. ";
					player_1.set_fire_count(player_1.get_fire_count() - 1);
					if (p_2_flag == false)
					{
						board[temp_row_of_player_2][temp_col_of_player_2] = player_id;
					}
					p_2_flag = true;
				}
			}
			else if (board[row_of_player_2][col_of_player_2] == player_1.get_snake_id())				//snake check
			{
				if (player_1.get_snake_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Sword to kill snake or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_2.get_sword_count() > 0)
						{
							cout << "\n\n ** You Successfully kill the snake hurdle **";
							player_2.set_sword_count(player_2.get_sword_count() - 1);
							p_2_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Sword to kill the snake hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's snake hurdle. ";
					player_1.set_snake_count(player_1.get_snake_count() - 1);
					if (p_2_flag == false)
					{
						board[temp_row_of_player_2][temp_col_of_player_2] = player_id;
					}
					p_2_flag = true;
				}
			}
			else if (board[row_of_player_2][col_of_player_2] == player_1.get_ghost_id())				//ghost check
			{
				if (player_1.get_ghost_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Shield to protect from ghost or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_2.get_shield_count() > 0)
						{
							cout << "\n\n ** You Successfully remove the ghost hurdle **";
							player_2.set_shield_count(player_2.get_shield_count() - 1);
							p_2_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Shield to remove the ghost hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's ghost hurdle. ";
					player_1.set_ghost_count(player_1.get_ghost_count() - 1);
					if (p_2_flag == false)
					{
						board[temp_row_of_player_2][temp_col_of_player_2] = player_id;
					}
					p_2_flag = true;
				}
			}
			else if (board[row_of_player_2][col_of_player_2] == player_1.get_lion_id())				//lion check
			{
				if (player_1.get_lion_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use Sword to kill lion or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_2.get_sword_count() > 0)
						{
							cout << "\n\n ** You Successfully remove the lion hurdle **";
							player_2.set_sword_count(player_2.get_sword_count() - 1);
							p_2_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have Sword to remove the lion hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's lion hurdle. ";
					player_1.set_lion_count(player_1.get_lion_count() - 1);
					if (p_2_flag == false)
					{
						board[temp_row_of_player_2][temp_col_of_player_2] = player_id;
					}
					p_2_flag = true;
				}
			}
			else if (board[row_of_player_2][col_of_player_2] == player_1.get_lock_id())				//lock check
			{
				if (player_1.get_lock_count() == 0)
				{
					char ch_p_1;
					cout << "\n\n** Want to use key for lock or not ? **";
					cout << "\nPress 'y' for yes and 'n' for no ";
					cin >> ch_p_1;
					while (ch_p_1 != 'y' && ch_p_1 != 'n')
					{
						cout << "\n+++++	INVALID CHOICE +++++  Enter Again: ";
						cin >> ch_p_1;
					}
					if (ch_p_1 == 'y')
					{
						if (player_2.get_key_count() > 0)
						{
							cout << "\n\n ** You Successfully remove the lock hurdle **";
							player_2.set_key_count(player_2.get_key_count() - 1);
							p_2_flag = false;
						}
						else
						{
							cout << "\n\n ** You Don't Have key to remove the key hurdle **";
						}
					}
				}
				else
				{
					cout << "\nCan't move .. Turn is blocked by opponent's key hurdle. ";
					player_1.set_lock_count(player_1.get_lock_count() - 1);
					if (p_2_flag == false)
					{
						board[temp_row_of_player_2][temp_col_of_player_2] = player_id;
					}
					p_2_flag = true;
				}
			}

			if (p_2_flag == false)										//player 2 placment
			{
				board[row_of_player_2][col_of_player_2] = player_id;
				board[temp_row_of_player_2][temp_col_of_player_2] = 22;
			}
		}
	}
	else
	{
		exit = ch_2;
	}
	Sleep(2000);
}

//red color 13,23

void Gameoflife::output()
{
	Maximized();
	
	if (*size == 5 || *size == 7)
	{
		int c_count = 0;
		int y_incre = 70;
		int x_incre = 70;
		for (int i = 0; i < *size; i++)								//graphical output
		{
			x_incre = 70;
			for (int j = 0; j < *size; j++)
			{
				if (c_count > (*size) * (*size) / 2)
				{
					myRect(700 + x_incre, 10 + y_incre, 770 + x_incre, 80 + y_incre, RGB(255, 255, 255), RGB(255, 0, 64));

					if (board[i][j] == 1)				//gold coin printing
					{
						myEllipse(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(255, 255, 0), RGB(255, 255, 0));
					}
					else if (board[i][j] == 2)			//silver coin printing
					{
						myEllipse(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(192, 192, 192), RGB(192, 192, 192));
					}
					else if (board[i][j] == 14)			//player printing
					{
						myEllipse(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(0, 215, 100), RGB(77, 0, 0));
					}
					else if (board[i][j] == 7)			//fire printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(255, 255, 0), RGB(255, 128, 0));
					}
					else if (board[i][j] == 8)			//snake printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(255, 191, 0), RGB(0, 255, 128));
					}
					else if (board[i][j] == 9)			//ghost printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(26, 0, 0), RGB(172, 83, 83));
					}
					else if (board[i][j] == 10)			//lion printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(232, 235, 102), RGB(255, 35, 35));
					}
					else if (board[i][j] == 11)			//lock printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(111, 117, 102), RGB(111, 42, 102));
					}

				}
				else if (c_count == (*size) * (*size) / 2)
				{
					myRect(700 + x_incre, 10 + y_incre, 770 + x_incre, 80 + y_incre, RGB(255, 255, 255), RGB(0, 255, 0));
				}
				else
				{
					myRect(700 + x_incre, 10 + y_incre, 770 + x_incre, 80 + y_incre, RGB(255, 255, 255), RGB(0, 0, 255));

					if (board[i][j] == 1)					//gold coin printing
					{
						myEllipse(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(255, 255, 0), RGB(255, 255, 0));
					}
					else if (board[i][j] == 2)				//silver coin printing
					{
						myEllipse(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(192, 192, 192), RGB(192, 192, 192));
					}
					else if (board[i][j] == 14)			//player printing
					{
						myEllipse(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(0, 215, 100), RGB(77, 0, 0));
					}
					else if (board[i][j] == 7)			//fire printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(255, 255, 0), RGB(255, 128, 0));
					}
					else if (board[i][j] == 8)			//snake printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(255, 191, 0), RGB(0, 255, 128));
					}
					else if (board[i][j] == 9)			//ghost printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(26, 0, 0), RGB(172, 83, 83));
					}
					else if (board[i][j] == 10)			//lion printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(232, 235, 102), RGB(255, 35, 35));
					}
					else if (board[i][j] == 11)			//lock printing
					{
						myRect(715 + x_incre, 25 + y_incre, 755 + x_incre, 65 + y_incre, RGB(111, 117, 102), RGB(111, 42, 102));
					}
				}
				c_count++;
				x_incre = x_incre + 70;
			}
			y_incre = y_incre + 70;
		}
	}
	else                                // ouput if board is 9 by 9 or 11 by 11
	{
		int c_count = 0;
		int y_incre = 50;
		int x_incre = 50;
		for (int i = 0; i < *size; i++)								//graphical output
		{
			x_incre = 50;
			for (int j = 0; j < *size; j++)
			{
				if (c_count > (*size) * (*size) / 2)
				{
					myRect(650 + x_incre, 5 + y_incre, 700 + x_incre, 55 + y_incre, RGB(255, 255, 255), RGB(255, 0, 64));

					if (board[i][j] == 1)				//gold coin printing
					{
						myEllipse(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(255, 255, 0), RGB(255, 255, 0));
					}
					else if (board[i][j] == 2)			//silver coin printing
					{
						myEllipse(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(192, 192, 192), RGB(192, 192, 192));
					}
					else if (board[i][j] == 14)			//player printing
					{
						myEllipse(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(0, 215, 100), RGB(77, 0, 0));
					}
					else if (board[i][j] == 7)			//fire printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(255, 255, 0), RGB(255, 128, 0));
					}
					else if (board[i][j] == 8)			//snake printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(255, 191, 0), RGB(0, 255, 128));
					}
					else if (board[i][j] == 9)			//ghost printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(26, 0, 0), RGB(172, 83, 83));
					}
					else if (board[i][j] == 10)			//lion printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(232, 235, 102), RGB(255, 35, 35));
					}
					else if (board[i][j] == 11)			//lock printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(111, 117, 102), RGB(111, 42, 102));
					}

				}
				else if (c_count == (*size) * (*size) / 2)
				{
					myRect(650 + x_incre, 5 + y_incre, 700 + x_incre, 55 + y_incre, RGB(255, 255, 255), RGB(0, 255, 0));
				}
				else
				{
					myRect(650 + x_incre, 5 + y_incre, 700 + x_incre, 55 + y_incre, RGB(255, 255, 255), RGB(0, 0, 255));

					if (board[i][j] == 1)					//gold coin printing
					{
						myEllipse(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(255, 255, 0), RGB(255, 255, 0));
					}
					else if (board[i][j] == 2)				//silver coin printing
					{
						myEllipse(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(192, 192, 192), RGB(192, 192, 192));
					}
					else if (board[i][j] == 14)			//player printing
					{
						myEllipse(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(0, 215, 100), RGB(77, 0, 0));
					}
					else if (board[i][j] == 7)			//fire printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(255, 255, 0), RGB(255, 128, 0));
					}
					else if (board[i][j] == 8)			//snake printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(255, 191, 0), RGB(0, 255, 128));
					}
					else if (board[i][j] == 9)			//ghost printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(26, 0, 0), RGB(172, 83, 83));
					}
					else if (board[i][j] == 10)			//lion printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(232, 235, 102), RGB(255, 35, 35));
					}
					else if (board[i][j] == 11)			//lock printing
					{
						myRect(665 + x_incre, 20 + y_incre, 685 + x_incre, 40 + y_incre, RGB(111, 117, 102), RGB(111, 42, 102));
					}
				}
				c_count++;
				x_incre = x_incre + 50;
			}
			y_incre = y_incre + 50;
		}
	}


}

bool Gameoflife::win_check()
{
	if (row_of_player_1 * (*size) + col_of_player_1 == ((*size) * (*size) / 2) + 1)
	{
		int count = 0;
		if (player_1.get_player_points() > player_2.get_player_points())
			count++;
		if (count == 1)
		{
			cout << "\n\n\n --------------[ Player 1 Win the game ]---------------- \n";
			Sleep(3000);
			return true;
		}
		else
		{
			cout << "\n\n\n --------------[ Game Drawn ]---------------- \n";
			Sleep(3000);
			return true;
		}
	}
	else if (row_of_player_2 * (*size) + col_of_player_2 == ((*size) * (*size) / 2) - 1)
	{
		int count = 0;
		if (player_2.get_player_points() > player_1.get_player_points())
			count++;
		if (count == 1)
		{
			cout << "\n\n\n --------------[ Player 2 Win the game ]---------------- \n";
			Sleep(3000);
			return true;
		}
		else
		{
			cout << "\n\n\n --------------[ Game Drawn ]---------------- \n";
			Sleep(3000);
			return true;
		}
	}
	else
		return false;
}

void Gameoflife::Save_data()
{
	ofstream fout;
	fout.open("GOL_data.txt");
	fout << *size;							//board size;
	fout << endl;
						//save player 1 data
	fout << player_1.get_player_gold_coins();
	fout << " ";
	fout << player_1.get_player_silver_coins();
	fout << endl;

	fout << player_1.get_sword_count() << " ";
	fout << player_1.get_shield_count() << " ";
	fout << player_1.get_water_count() << " ";
	fout << player_1.get_key_count() << " ";
	fout << endl;

	fout << player_1.get_fire_count() << " ";
	fout << player_1.get_snake_count() << " ";
	fout << player_1.get_ghost_count() << " ";
	fout << player_1.get_lion_count() << " ";
	fout << player_1.get_lock_count() << " ";
	fout << endl;

	fout << row_of_player_1 << " ";
	fout << col_of_player_1 << " ";
	fout << endl;

									//player 2 data
	fout << player_2.get_player_gold_coins() << " ";
	fout << player_2.get_player_silver_coins() << " ";
	fout << endl;

	fout << player_2.get_sword_count() << " ";
	fout << player_2.get_shield_count() << " ";
	fout << player_2.get_water_count() << " ";
	fout << player_2.get_key_count() << " ";
	fout << endl << " ";

	fout << player_2.get_fire_count() << " ";
	fout << player_2.get_snake_count() << " ";
	fout << player_2.get_ghost_count() << " ";
	fout << player_2.get_lion_count() << " ";
	fout << player_2.get_lock_count() << " ";
	fout << endl;

	fout << row_of_player_2 << " ";
	fout << col_of_player_2 << " ";
	fout << endl;

	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size; j++)
		{
			fout << board[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

void Gameoflife::read_data()
{
	ifstream fin;
	fin.open("GOL_data.txt");
	if (!fin)
	{
		cout << "\n File not Found: ";
	}
	else
	{
		//save player 1 data
		int n;
		fin >> *size;
		fin >> n;
		player_1.set_player_gold_coins(n);
		fin >> n;
		player_1.set_player_silver_coins(n);


		fin >> n;
		player_1.set_sword_count(n);
		fin >> n;
		player_1.set_shield_count(n);
		fin >> n;
		player_1.set_water_count(n);
		fin >> n;
		player_1.set_key_count(n);
	

		fin >> n;
		player_1.set_fire_count(n);
		fin >> n;
		player_1.set_snake_count(n);
		fin >> n;
		player_1.set_ghost_count(n);
		fin >> n;
		player_1.set_lion_count(n);
		fin >> n;
		player_1.set_lock_count(n);
		

		
		fin >> row_of_player_1;
		fin >> col_of_player_1;
		

		//player 2 data
		fin >> n;
		player_2.set_player_gold_coins(n);
		fin >> n;
		player_2.set_player_silver_coins(n);

		fin >> n;
		player_2.set_sword_count(n);
		fin >> n;
		player_2.set_shield_count(n);
		fin >> n;
		player_2.set_water_count(n);
		fin >> n;
		player_2.set_key_count(n);
		

		fin >> n;
		player_2.set_fire_count(n);
		fin >> n;
		player_2.set_snake_count(n);
		fin >> n;
		player_2.set_ghost_count(n);
		fin >> n;
		player_2.set_lion_count(n);
		fin >> n;
		player_2.set_lock_count(n);
		

		fin >> row_of_player_2 ;
		fin >> col_of_player_2 ;
		

		for (int i = 0; i < *size; i++)
		{
			for (int j = 0; j < *size; j++)
			{
				fin >> board[i][j];
			}
		}
		fin.close();
	}
}

Gameoflife::~Gameoflife()
{
	for (int i = 0; i < *size; i++)
	{
		delete[]board[i];
	}
	delete[]board;
	board = NULL;
	delete size;
	size = NULL;
}