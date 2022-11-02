#include "hurdle.h";

Hurdles::Hurdles()								//default constructor
{
	fire_id = new int(7);								// ids and count storage
	fire_count = new int(0);
	snake_id = new int(8);
	snake_count = new int(0);
	ghost_id = new int(9);
	ghost_count = new int(0);
	lion_id = new int(10);
	lion_count = new int(0);
	lock_id = new int(11);
	lock_count = new int(0);

	fire_points = new int(50);							//points storage
	snake_points = new int(30);
	ghost_points = new int(20);
	lion_points = new int(50);
	lock_points = new int(60);
}

// get hurdles id's
int Hurdles::get_fire_id()
{
	return *fire_id;
}
int Hurdles::get_snake_id()
{
	return *snake_id;
}
int Hurdles::get_ghost_id()
{
	return *ghost_id;
}
int Hurdles::get_lion_id()
{
	return *lion_id;
}
int Hurdles::get_lock_id()
{
	return *lock_id;
}

// get hurdles count (how much hurdles can block the opponent's block)
int Hurdles::get_fire_count()
{
	return *fire_count;
}
int Hurdles::get_snake_count()
{
	return *snake_count;
}
int Hurdles::get_ghost_count()
{
	return *ghost_count;
}
int Hurdles::get_lion_count()
{
	return *lion_count;
}
int Hurdles::get_lock_count()
{
	return *lock_count;
}

// get hurdles points
int Hurdles::get_fire_points()
{
	return *fire_points;
}
int Hurdles::get_snake_points()
{
	return *snake_points;
}
int Hurdles::get_ghost_points()
{
	return *ghost_points;
}
int Hurdles::get_lion_points()
{
	return *lion_points;
}
int Hurdles::get_lock_points()
{
	return *lock_points;
}

// setters
void Hurdles::set_fire_count(int fire)
{
	delete fire_count;
	fire_count = new int(fire);
}
void Hurdles::set_snake_count(int snake)
{
	delete snake_count;
	snake_count = new int(snake);
}
void Hurdles::set_ghost_count(int ghost)
{
	delete ghost_count;
	ghost_count = new int(ghost);
}
void Hurdles::set_lion_count(int lion)
{
	delete lion_count;
	lion_count = new int(lion);
}
void Hurdles::set_lock_count(int lock)
{
	delete lock_count;
	lock_count = new int(lock);
}
Hurdles::~Hurdles()											//destructor
{
	delete fire_id;
	delete fire_count;
	delete snake_id;
	delete snake_count;
	delete ghost_id;
	delete ghost_count;
	delete lion_id;
	delete lion_count;
	delete lock_id;
	delete lock_count;
	delete fire_points;
	delete snake_points;
	delete ghost_points;
	delete lion_points;
	delete lock_points;

	fire_id = nullptr;
	fire_count = nullptr;
	snake_id = nullptr;
	snake_count = nullptr;
	ghost_id = nullptr;
	ghost_count = nullptr;
	lion_id = nullptr;
	lion_count = nullptr;
	lock_id = nullptr;
	lock_count = nullptr;
	fire_points = nullptr;
	snake_points = nullptr;
	ghost_points = nullptr;
	lion_points = nullptr;
	lock_points = nullptr;
}