#pragma once

class COINS
{
	int* player_gold_coins;
	int* player_silver_coins;
	int* gold_points;
	int* silver_points;
public:
	COINS();
	COINS(int gold_1, int silver_1);

	void set_player_gold_coins(int gold_1);
	void set_player_silver_coins(int silver_1);

	void display_player_coins();

	int get_player_gold_coins();
	int get_player_silver_coins();

	int get_gold_points();
	int get_silver_points();

	~COINS();
};