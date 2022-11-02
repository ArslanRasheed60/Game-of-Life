#include "Coins.h";
#include "helperObject.h";
#include "hurdle.h";
#include "player.h";
#include <iostream>
using namespace std;

Player_obj::Player_obj() :HelpingObjects(), Hurdles(), COINS()					// default constructors
{
	player_points = (get_player_gold_coins() * get_gold_points()) + (get_player_silver_coins() * get_silver_points());
}

int Player_obj::get_player_points()					//get player points
{
	return player_points;
}
void Player_obj::set_player_points(int points)			//set player points
{
	player_points = points;
}

void Player_obj::display_player_objects()
{
	cout << "1) Helping Objects: --> " << "1) Sword: " << get_sword_count() << ".   2) Shield: " << get_shield_count()
		<< ".   3) Water: " << get_water_count() << ".   4) Key: " << get_key_count();
	cout << "\n2) Obstacles: --> " << "1) Fire: " << get_fire_count() << ".   2) Snake: " << get_snake_count()
		<< ".   3) Ghost: " << get_ghost_count() << ".   4) Lion: " << get_lion_count() << ".   5) lock: " << get_lock_count();

}