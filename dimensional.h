#pragma once
#include <iostream>
#include <stdarg.h>
#include <vector>
#define _DIMENSIONAL_H_ 
namespace s_dim {

	typedef unsigned long long int pos;

	template<size_t z = 0, size_t y = 0, size_t x = 0>
	class dimensional_size {
	public:
		dimensional_size();
		dimensional_size(size_t oz, size_t oy, size_t ox);
		~dimensional_size();
		size_t get_capacity();
		size_t get_breadth();
		size_t get_height();
		size_t get_width();
		void up_size(size_t z = 0, size_t y = 0, size_t x = 0);
	private:
		size_t absolute_x;
		size_t absolute_y;
		size_t absolute_z;
	};

	template<typename type>
	class dimensional_pos {
	public:
		dimensional_pos();
		dimensional_pos(pos z = 0, pos y = 0, pos x = 0);
		~dimensional_pos();
		dimensional_pos& get_pos(std::vector<type> stream, type& t);
		dimensional_pos& get_pos(std::vector<std::vector<type> > stream, type& t);
		dimensional_pos& get_pos(std::vector<std::vector<std::vector<type> > > stream, type& t);
		pos get_z();
		pos get_y();
		pos get_x();
	private:
		pos absolute_x;
		pos absolute_y;
		pos absolute_z;
	};
}