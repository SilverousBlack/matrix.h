#pragma once
#include <iostream>
#include <vector>
#include "dimensional.h"
#define _MATRIX_H_
namespace s_matrix {
	using namespace s_dim;
	template<typename type, size_t _breadth = 0, size_t _height = 0, size_t _width = 0>
	class matrix {
	public:
		matrix(size_t o_z = 0, size_t o_y = 0, size_t o_x = 0);
		~matrix();
		void resize(size_t new_breadth = 0, size_t new_height = 0, size_t new_width = 0);
		void assign(type obj, pos z, pos y, pos x);
		type access(pos z = 0, pos y = 0, pos x = 0);
		void move(dimensional_pos<type> old_pos, dimensional_pos<type> new_pos);
		size_t get_capacity() const;
		std::vector<std::vector<type> >& copy(std::vector<std::vector<type> > dest, pos z = 0, pos y = 0, pos dest_z = 0);
		std::vector<type>& copy(std::vector<type> dest, pos z = 0, pos y = 0);
		dimensional_pos<type> get_loc(type& t);
		bool isfull();
		void fill(type obj);
		void remove_instance(type obj);
		void operator<<(type t);
		void operator>>(type t);
		matrix<type, _breadth, _width, _height> operator=(matrix<type, _breadth, _height, _width> obj);
		operator int() const;
		operator bool() const;
		operator size_t() const;
	private:
		dimensional_size<_breadth, _height, _width> size_obj;
		std::vector<std::vector<std::vector<type> > > dat;
	};
}