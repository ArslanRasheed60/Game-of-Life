#pragma once

class HelpingObjects
{
	int* sword_id;
	int* shield_id;
	int* water_id;
	int* key_id;
	int* sword_count;
	int* shield_count;
	int* water_count;
	int* key_count;
	int* sword_points;
	int* shield_points;
	int* water_points;
	int* key_points;
public:
	HelpingObjects();

	int get_sword_id();
	int get_shield_id();
	int get_water_id();
	int get_key_id();

	int get_sword_count();
	int get_shield_count();
	int get_water_count();
	int get_key_count();

	void set_sword_count(int sword);
	void set_shield_count(int shield);
	void set_water_count(int water);
	void set_key_count(int key);
	
	int get_sword_points();
	int get_shield_points();
	int get_water_points();
	int get_key_points();

	~HelpingObjects();
};
