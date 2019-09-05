#pragma once
#include <vector>
#include <sstream>
#include <dimensional/dimensional.h>

#if !defined _MATRIX_H_
#define _MATRIX_H_
namespace s_mtx {
	template<typename type>
	class matrix {
	private:
		std::vector<type> vect_space;
#ifdef _DIMENSIONAL_H_
		s_dim::dimensional_space sz;
#else
		size_t sz_z;
		size_t sz_y;
		size_t sz_x;
#endif
	public:
		matrix(size_t breadth = 0, size_t height = 0, size_t width = 0);
		~matrix();
	};
}
#endif