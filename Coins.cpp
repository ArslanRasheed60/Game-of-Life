#include "Coins.h";
#include <iostream>

using namespace std;

COINS::COINS()
{
	player_gold_coins = new int(10);
	player_silver_coins = new int(20);

	gold_points = new int(10);							//per gold 10 points
	silver_points = new int(5);							//per silver 5 points

}
COINS::COINS(int gold_1, int silver_1)
{
	player_gold_coins = new int (gold_1);
	player_silver_coins = new int (silver_1);

	gold_points = new int(10);							//per gold 10 points
	silver_points = new int(5);							//per silver 5 points
}
void COINS::set_player_gold_coins(int gold_1)						//set gold coins of player
{
	if (player_gold_coins != NULL)
	{
		delete player_gold_coins;
		player_gold_coins = new int(gold_1);
	}
	else
	{
		player_gold_coins = new int(gold_1);
	}
	
}
void COINS::set_player_silver_coins(int silver_1)					//set silver coins of player
{
	if (player_silver_coins != NULL)
	{
		delete player_silver_coins;
		player_silver_coins = new int(silver_1);
	}
	else
	{
		player_silver_coins = new int(silver_1);
	}
	
}

int COINS::get_player_gold_coins()						//get player gold coins
{
	return *player_gold_coins;
}
int COINS::get_player_silver_coins()					//get player silver coins
{
	return *player_silver_coins;
}


int COINS::get_gold_points()
{
	return *gold_points;
}
int COINS::get_silver_points()
{
	return *silver_points;
}

void COINS::display_player_coins()
{
	cout << "\nGold Coins:  " << *player_gold_coins << ".        Silver Coins:  " << *player_silver_coins;
}

COINS::~COINS()
{
	delete player_gold_coins;
	delete player_silver_coins;
	delete gold_points;
	delete silver_points;

	player_gold_coins = NULL;
	player_silver_coins = NULL;
	gold_points = NULL;
	silver_points = NULL;
}