#pragma once
#include <iostream>
#include <stdarg.h>
#include <vector>

#ifndef _DIMENSIONAL_H_
#define _DIMENSIONAL_H_ 
namespace s_dim {

	typedef unsigned long long int pos;

	template<size_t z = 0, size_t y = 0, size_t x = 0>
	class dimensional_size {
	public:
		dimensional_size();
		dimensional_size(size_t oz, size_t oy, size_t ox);
		~dimensional_size();
		size_t get_capacity() const;
		size_t get_breadth() const;
		size_t get_height() const;
		size_t get_width() const;
		void up_size(size_t z = 0, size_t y = 0, size_t x = 0);
	private:
		size_t absolute_x;
		size_t absolute_y;
		size_t absolute_z;
	};

	class dimensional_pos {
	public:
		dimensional_pos(pos z = 0, pos y = 0, pos x = 0);
		~dimensional_pos();
		template <typename type> dimensional_pos& get_pos(std::vector<type> stream, type& t);
		template <typename type> dimensional_pos& get_pos(std::vector<std::vector<type> > stream, type& t);
		template <typename type> dimensional_pos& get_pos(std::vector<std::vector<std::vector<type> > > stream, type& t);
		bool operator== (dimensional_pos comp);
		pos get_z() const;
		pos get_y() const;
		pos get_x() const;
	private:
		pos absolute_x;
		pos absolute_y;
		pos absolute_z;
	};
}
#endif