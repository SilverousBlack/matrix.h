#include "dimensional.h"

s_dim::dimensional_space::dimensional_space(size_t z, size_t y, size_t x)
	: sz_z(z)
	, sz_y(y)
	, sz_x(x)
{}

s_dim::dimensional_space::~dimensional_space(){
	delete this;
}

size_t s_dim::dimensional_space::get_capacity(){
	return sz_z * sz_y * sz_x;
}

size_t s_dim::dimensional_space::get_breadth(){
	return sz_z;
}


size_t s_dim::dimensional_space::get_height(){
	return sz_y;
}

size_t s_dim::dimensional_space::get_width(){
	return sz_x;
}

s_dim::dimensional_pos::dimensional_pos(pos co_z, pos co_y, pos co_x)
	: z(co_z)
	, y(co_y)
	, x(co_x)
{}

s_dim::dimensional_pos::~dimensional_pos(){
	delete this;
}
