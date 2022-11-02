#include "helperObject.h";

HelpingObjects::HelpingObjects()
{
	sword_id = new int(3);									//id assighning
	shield_id = new int(4);
	water_id = new int(5);
	key_id = new int(6);

	sword_count = new int(0);							//objects count
	shield_count = new int(0);
	water_count = new int(0);
	key_count = new int(0);

	sword_points = new int(40);							//default obects points
	shield_points = new int(30);
	water_points = new int(50);
	key_points = new int(70);
}

// get helping  objects ids
int HelpingObjects::get_sword_id()									
{
	return *sword_id;
}
int HelpingObjects::get_shield_id()
{
	return *shield_id;
}
int HelpingObjects::get_water_id()
{
	return *water_id;
}
int HelpingObjects::get_key_id()
{
	return *key_id;
}

//get helping object count (how many times helping objects can be used)
int HelpingObjects::get_sword_count()
{
	return *sword_count;
}
int HelpingObjects::get_shield_count()
{
	return *shield_count;
}
int HelpingObjects::get_water_count()
{
	return *water_count;
}
int HelpingObjects::get_key_count()
{
	return *key_count;
}

// setters
void HelpingObjects::set_sword_count(int sword)
{
	delete sword_count;
	sword_count = new int(sword);
}
void HelpingObjects::set_shield_count(int shield)
{
	delete shield_count;
	shield_count = new int(shield);
}
void HelpingObjects::set_water_count(int water)
{
	delete water_count;
	water_count = new int(water);
}
void HelpingObjects::set_key_count(int key)
{
	delete key_count;
	key_count = new int(key);
}

// get points of helping objects
int HelpingObjects::get_sword_points()
{
	return *sword_points;
}
int HelpingObjects::get_shield_points()
{
	return *shield_points;
}
int HelpingObjects::get_water_points()
{
	return *water_points;
}
int HelpingObjects::get_key_points()
{
	return *key_points;
}

HelpingObjects::~HelpingObjects()								//destructor
{
	delete sword_id;
	delete shield_id;
	delete water_id;
	delete key_id;
	delete sword_count;
	delete shield_count;
	delete water_count;
	delete key_count;
	delete sword_points;
	delete shield_points;
	delete water_points;
	delete key_points;

	sword_id = nullptr;
	shield_id = nullptr;
	water_id = nullptr;
	key_id = nullptr;
	sword_count = nullptr;
	shield_count = nullptr;
	water_count = nullptr;
	key_count = nullptr;
	sword_points = nullptr;
	shield_points = nullptr;
	water_points = nullptr;
	key_points = nullptr;
}