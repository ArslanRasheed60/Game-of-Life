#pragma once

#include "Coins.h";
#include "hurdle.h";
#include "helperObject.h";
#include "player.h";

class Gameoflife
{
	int** board;
	int* size;
public:
	static int player_id;
	static int row_of_player_1;
	static int col_of_player_1;
	static int row_of_player_2;
	static int col_of_player_2;
	static char exit;
						//player 1 movement control
	static int p_1_backward;
	static int p_1_forward;
	static int p_1_count;
	static Player_obj player_1;								//player 1 object
	static bool p_1_flag;
						//player 2 movement control
	static int p_2_backward;
	static int p_2_forward;
	static int p_2_count;
	static Player_obj player_2;								//player 2 object
	static bool p_2_flag;
						//storage of previous position when hurdles come
	static int temp_row_of_player_1;
	static int temp_col_of_player_1;
	static int temp_row_of_player_2;
	static int temp_col_of_player_2;

	Gameoflife();
	Gameoflife(int siz);
	int get_size();
	void set_object_in_board(int r, int c,int val);
	int get_object_from_board(int r, int c);
	
	void player_1_place_hurdle_check(int r,int c,int hurdle_id);
	void player_2_place_hurdle_check(int r,int c,int hurdle_id);
	void getting_player_1_move();
	void getting_player_2_move();
	void move_validation_check(int& nn);
	
	void Save_data();
	void read_data();

	bool win_check();
	void output();
	~Gameoflife();
};



// 1 = gold coins
// 2 = silver coins
// 
// 15 = goal