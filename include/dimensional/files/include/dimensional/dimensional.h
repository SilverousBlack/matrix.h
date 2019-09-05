#pragma once

#if !defined _DIMENSIONAL_H_
#define _DIMENSIONAL_H_
namespace s_dim {

	typedef unsigned long long pos;

	class dimensional_space {
	private:
		size_t sz_z;
		size_t sz_y;
		size_t sz_x;
	public:
		dimensional_space(size_t z = 0, size_t y = 0, size_t x = 0);
		~dimensional_space();
		size_t get_capacity();
		size_t get_breadth();
		size_t get_height();
		size_t get_width();
		template<typename type> size_t* sizes_z(type*** tri_arr);
		template<typename type> size_t** sizes_y(type*** tri_arr);
		template<typename type> size_t*** sizes_x(type*** tri_arr);
		template<typename type> double average_z(type*** tri_arr);
		template<typename type> double average_y(type*** tri_arr);
		template<typename type> double average_x(type*** tri_arr);
		bool operator> (dimensional_space target);
		bool operator>= (dimensional_space target);
		bool operator< (dimensional_space target);
		bool operator<= (dimensional_space target);
		bool operator== (dimensional_space target);
		dimensional_space operator= (dimensional_space src);
		dimensional_space operator= (size_t src[3]);
		template<typename type> dimensional_space operator= (type*** tri_arr_src);
	};

	class dimensional_pos {
	private:
		pos z;
		pos y;
		pos x;
	public:
		dimensional_pos(pos co_z = 0, pos co_y = 0, pos co_x = 0);
		~dimensional_pos();
		pos get_z();
		pos get_y();
		pos get_x();
		template <typename type> void loc(type*** tri_arr, type obj);
		template <typename type> dimensional_pos loc(type*** tri_arr, type obj);
		bool operator> (dimensional_pos target);
		bool operator>= (dimensional_pos target);
		bool operator< (dimensional_pos target);
		bool operator<= (dimensional_pos target);
		bool operator== (dimensional_pos target);
		dimensional_space operator= (dimensional_pos src);
		dimensional_space operator= (pos src[3]);
	};

	typedef dimensional_space dim_space;
	typedef dimensional_pos dim_pos;

	template<typename type>
	inline size_t* dimensional_space::sizes_z(type*** tri_arr){
		size_t* internal = new size_t[sizeof(tri_arr) / (sizeof(type) * sizeof(type) * sizeof(type))];
		for (pos i = 0; i < (internal / sizeof(size_t)); i++) {
			internal[i] = (tri_arr[i] / (sizeof(type) * sizeof(type)));
		}
		return internal;
	}

	template<typename type>
	inline size_t** dimensional_space::sizes_y(type*** tri_arr){
		size_t** internal = new size_t[sizeof(tri_arr) / (sizeof(type) * sizeof(type))];
		for (pos i = 0; i < (internal / sizeof(size_t)); i++) {
			internal[i] = (tri_arr[i] / (sizeof(type) * sizeof(type)));
		}
		return internal;
	}

	template<typename type>
	inline size_t*** dimensional_space::sizes_x(type*** tri_arr){
		size_t** internal = new size_t[sizeof(tri_arr) / (sizeof(type))];
		for (pos i = 0; i < (internal / sizeof(size_t)); i++) {
			internal[i] = (tri_arr[i] / (sizeof(type) * sizeof(type)));
		}
		return internal;
	}

}
#endif