#pragma once

#include "matrix.h"

namespace s_matrix {
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
	matrix<type, _breadth, _height, _width>::~matrix() {
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
	void matrix<type, _breadth, _height, _width>::move(dimensional_pos<type> old_pos, dimensional_pos<type> new_pos) {
		type obj = dat[old_pos.get_z()][old_pos.get_y()][old_pos.get_x()];
		(bool)dat[old_pos.get_z()][old_pos.get_y()][old_pos.get_x()];
		dat[new_pos.get_z()][new_pos.get_y()][new_pos.get_x()] = obj;
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	size_t matrix<type, _breadth, _height, _width>::get_capacity() const {
		return size_obj.get_capacity();
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	std::vector<std::vector<type> >& matrix<type, _breadth, _height, _width>::copy(std::vector<std::vector<type> > dest, pos z, pos y, pos dest_z) {
		dest[dest_z] = dat[z][y];
		return dat[z][y];
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	std::vector<type>& matrix<type, _breadth, _height, _width>::copy(std::vector<type> dest, pos z, pos y) {
		dest = dat[z][y];
		return dat[z][y];
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	dimensional_pos<type> matrix<type, _breadth, _height, _width>::get_loc(type& t) {
		dimensional_pos<type> internal;
		return internal.get_pos(dat, t);
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	bool matrix<type, _breadth, _height, _width>::isfull() {
		for (int i = 0; i < dat.size(); i++) {
			for (int j = 0; j < dat[i].size(); j++) {
				for (int k = 0; k < dat[i][j].size(); k++) {
					if (!(bool)dat[i][j][k]) {
						return false;
					}
					if (((bool)dat[i][j][k]) && (i == (dat.size() - 1)) && (j == (dat[i].size() - 1)) && (k == (dat[i][j].size() - 1))) {
						return true;
					}
				}
			}
		}
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	void matrix<type, _breadth, _height, _width>::fill(type obj) {
		for (int i = 0; i < dat.size(); i++) {
			for (int j = 0; j < dat[i].size(); j++) {
				for (int k = 0; k < dat[i][j].size(); k++) {
					if (!(bool)dat[i][j][k]) {
						dat[i][j][k] = obj;
					}
				}
			}
		}
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	void matrix<type, _breadth, _height, _width>::remove_instance(type obj) {
		for (int i = 0; i < dat.size(); i++) {
			for (int j = 0; j < dat[i].size(); j++) {
				for (int k = 0; k < dat[i][j].size(); k++) {
					if (dat[i][j][k] == obj) {
						(bool)dat[i][j][k] = false;
					}
				}
			}
		}
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	void matrix<type, _breadth, _height, _width>::operator<<(type t) {
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
	void matrix<type, _breadth, _height, _width>::operator>>(type t) {
		for (int i = dat.size(); i != 0; i--) {
			for (int j = dat[i].size(); j != 0; j--) {
				for (int k = dat[i][j].size(); k != 0; k--) {
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
	matrix<type, _breadth, _width, _height> matrix<type, _breadth, _height, _width>::operator=(matrix<type, _breadth, _height, _width> obj) {
		return obj;
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	matrix<type, _breadth, _height, _width>::operator int() const {

	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	matrix<type, _breadth, _height, _width>::operator bool() const {
		return isfull();
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	inline matrix<type, _breadth, _height, _width>::operator size_t() const {
		int control = ((rand()) % (3 - 0 + 1)) + 0;
		if (control == 0) {
			return size_obj.get_breadth();
		}
		else if (control == 1) {
			return size_obj.get_height();
		}
		else if (control == 2) {
			return size_obj.get_width();
		}
		else {
			return size_obj.get_capacity();
		}
	}
}