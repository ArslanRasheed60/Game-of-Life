#pragma once

class Hurdles
{
	int* fire_id;
	int* fire_count;
	int* snake_id;
	int* snake_count;
	int* ghost_id;
	int* ghost_count;
	int* lion_id;
	int* lion_count;
	int* lock_id;
	int* lock_count;
	int* fire_points;
	int* snake_points;
	int* ghost_points;
	int* lion_points;
	int* lock_points;
public:
	Hurdles();
	int get_fire_id();
	int get_snake_id();
	int get_ghost_id();
	int get_lion_id();
	int get_lock_id();

	int get_fire_points();
	int get_snake_points();
	int get_ghost_points();
	int get_lion_points();
	int get_lock_points();

	int get_fire_count();
	int get_snake_count();
	int get_ghost_count();
	int get_lion_count();
	int get_lock_count();

	void set_fire_count(int fire);
	void set_snake_count(int snake);
	void set_ghost_count(int ghost);
	void set_lion_count(int lion);
	void set_lock_count(int lock);

	~Hurdles();
};
