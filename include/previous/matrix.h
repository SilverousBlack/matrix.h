#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "dimensional.h"
#if !defined _MATRIX_H_ && defined _DIMENSIONAL_H_ && defined _VECTOR_
#define _MATRIX_H_
namespace s_mtx {
	using namespace s_dim;
	template<typename type, size_t _breadth = 0, size_t _height = 0, size_t _width = 0>
	class matrix {
	public:
		matrix(size_t o_z = 0, size_t o_y = 0, size_t o_x = 0);
		~matrix();
		void resize(size_t new_breadth = 0, size_t new_height = 0, size_t new_width = 0);
		void assign(type obj, pos z, pos y, pos x);
		type access(pos z = 0, pos y = 0, pos x = 0);
		void move(dimensional_pos old_pos, dimensional_pos new_pos);
		size_t get_capacity() const;
		size_t get_breadth() const;
		size_t get_height() const;
		size_t get_width() const;
		std::vector<std::vector<type> >& copy(std::vector<std::vector<type> > dest, pos z = 0, pos y = 0, pos dest_z = 0);
		std::vector<type>& copy(std::vector<type> dest, pos z = 0, pos y = 0);
		dimensional_pos get_loc(type& t);
		bool isfull();
		void fill(type obj);
		void remove_instance(type obj);
		void operator<<(type t);
		void operator>>(type t);
		matrix<type, _breadth, _width, _height> operator=(matrix<type, _breadth, _height, _width> obj);
		operator int() const;
		operator bool() const;
		operator size_t() const;
		dimensional_size<_breadth, _height, _width> metadata();
	private:
		dimensional_size<_breadth, _height, _width> size_obj;
		std::vector<std::vector<std::vector<type> > > dat;
	};
	typedef matrix<int> mat_int;
	typedef matrix<char> mat_chr;
	typedef matrix<bool> mat_bln;
	typedef matrix<float> mat_flt;
	typedef matrix<double> mat_dbl;
	typedef matrix<wchar_t> mat_wch;

#ifdef _CSTRING_
	typedef matrix<std::string> mat_str;
	typedef matrix<std::wstring> mat_wsr;
#endif

	enum mtxio {
		/*
		Output Matrix I/O modes
		*/
		std, cpy, safe,

		/*
		Input Matrix I/O modes
		*/
		sta, cta, bbta, rsta, rcta
		/*
		sta = standard type allocation
		cta = convetional type allocation
		bbta = boolean-based type allocation
		rsta = random standard type allocation
		rcta = random conventional type allocation
		*/
	};

#if defined _FSTREAM_ && defined _SSTREAM_
	template<typename type>
	void make_file(matrix<type> src, std::string filename, mtxio mode = std);
	template<typename type>
	void read_file(matrix<type> dest, std::string filename);
	std::string marker(dimensional_pos obj);
	template<typename type>
	std::string metadata(matrix<type> obj);
	dimensional_size<> read_metadata(std::string metadata);
	dimensional_pos read_marker(std::string marker);
	std::string identity_type(std::string type_metadata);
	template<typename type>
	void read_content(type obj, std::string content);
	template<typename type>
	void mtx_init(matrix<type> mtx, mtxio mode);
#endif
}
#endif