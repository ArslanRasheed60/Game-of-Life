#pragma once
#include "Coins.h";
#include "helperObject.h";
#include "hurdle.h";

class Player_obj: public HelpingObjects, public Hurdles, public COINS
{
	int player_points;
public:
	Player_obj();
	int get_player_points();
	void set_player_points(int points);
	void display_player_objects();
};