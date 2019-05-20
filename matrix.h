#pragma once
#include <iostream>
#include <vector>
#include "dimensional.h"
using namespace std;
#define _MATRIX_H_

template<typename type, size_t _breadth = 0, size_t _height = 0, size_t _width = 0>
class matrix {
public:
	matrix();
	matrix(size_t o_z, size_t o_y, size_t o_x);
	~matrix();
	void resize(size_t new_breadth = 0, size_t new_height = 0, size_t new_width = 0);
	void assign(type obj, pos z, pos y, pos x);
	type access(pos z=0, pos y = 0, pos x = 0);
	void move(dimensional_pos<type> old_pos, dimensional_pos<type> new_pos);
	size_t get_capacity();
	vector<vector<type> >& copy(vector<vector<type> > dest, pos z = 0, pos y = 0, pos dest_z = 0);
	vector<type>& copy(vector<type> dest, pos z = 0, pos y = 0);
	dimensional_pos<type> get_loc(type& t);
	void operator<<(type t);
	void operator>>(type t);
	matrix<type, _breadth, _width, _height> operator=(matrix<type, _breadth, _height, _width> obj);
private:
	dimensional_size<_breadth, _height, _width> size_obj;
	vector<vector<vector<type> > > dat;
};

template<typename type, size_t _breadth, size_t _height, size_t _width>
matrix<type, _breadth, _height, _width>::matrix(){
	dat.reserve(_breadth);
	for (int z = 0; z < dat.size(); z++) {
		dat[z].reserve(_height);
		for (int y = 0; y < dat[y].size(); y++) {
			dat[z][y].reserve(_width);
		}
	}
	size_obj;
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
matrix<type, _breadth, _height, _width>::matrix(size_t o_z, size_t o_y, size_t o_x)
	: size_obj(o_z, o_y, o_x)
{
	dat.resize(o_z);
	for (int z = 0; z < dat.size(); z++) {
		dat[z].resize(o_y);
		for (int y = 0; y < dat[y].size(); y++) {
			dat[z][y].reserve(o_x);
		}
	}
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
matrix<type, _breadth, _height, _width>::~matrix(){
	delete& size_obj;
	dat.clear();
	dat.resize(0);
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
void matrix<type, _breadth, _height, _width>::resize(size_t new_breadth, size_t new_height, size_t new_width) {
	dat.resize(new_breadth);
	for (int z = 0; z < dat.size(); z++) {
		dat[z].resize(new_height);
		for (int y = 0; y < dat[z][y].size(); y++) {
			dat[z][y].resize(new_width);
		}
	}
	size_obj.up_size(new_breadth, new_height, new_width);
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
void matrix<type, _breadth, _height, _width>::assign(type obj, pos z, pos y, pos x) {
	dat[z][y][x] = obj;
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
type matrix<type, _breadth, _height, _width>::access(pos z, pos y, pos x) {
	return dat[z][y][x];
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
void matrix<type, _breadth, _height, _width>::move(dimensional_pos<type> old_pos, dimensional_pos<type> new_pos){
	type obj = dat[old_pos.get_z()][old_pos.get_y()][old_pos.get_x()];
	(bool)dat[old_pos.get_z()][old_pos.get_y()][old_pos.get_x()];
	dat[new_pos.get_z()][new_pos.get_y()][new_pos.get_x()] = obj;
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
size_t matrix<type, _breadth, _height, _width>::get_capacity(){
	return size_obj.get_capacity();
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
vector<vector<type> >& matrix<type, _breadth, _height, _width>::copy(vector<vector<type> > dest, pos z, pos y, pos dest_z) {
	dest[dest_z] = dat[z][y];
	return dat[z][y];
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
vector<type>& matrix<type, _breadth, _height, _width>::copy(vector<type> dest, pos z, pos y) {
	dest = dat[z][y];
	return dat[z][y];
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
dimensional_pos<type> matrix<type, _breadth, _height, _width>::get_loc(type& t) {
	dimensional_pos<type> internal;
	return internal.get_pos(dat, t);
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
void matrix<type, _breadth, _height, _width>::operator<<(type t){
	for (int i = 0; i < dat.size(); i++) {
		for (int j = 0; j < dat[i].size(); j++) {
			for (int k = 0; k < dat[i][j].size(); k++) {
				if ((bool)dat[i][j][k] == false) {
					dat[i][j][k] = t;
				}
			}
		}
	}
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
void matrix<type, _breadth, _height, _width>::operator>>(type t){
	for (int i=dat.size(); i!=0; i--){
		for (int j=dat[i].size(); j !=0; j--){
			for (int k=dat[i][j].size(); k!=0 ; k--) {
				if ((bool)dat[i][j][k] == true) {
					type obj = dat[i][j][k];
					(bool)dat[i][j][k] = false;
					return obj;
				}
			}
		}
	}
}

template<typename type, size_t _breadth, size_t _height, size_t _width>
matrix<type, _breadth, _width, _height> matrix<type, _breadth, _height, _width>::operator=(matrix<type, _breadth, _height, _width> obj){
	return obj;
}