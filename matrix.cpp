#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <typeinfo>
#include "dimensional.h"
#include "matrix.h"

namespace s_mtx {
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
		delete[] size_obj;
		dat.clear();
		dat.resize(0);
		delete[] dat;
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
	void matrix<type, _breadth, _height, _width>::move(dimensional_pos old_pos, dimensional_pos new_pos) {
		type obj = dat[old_pos.get_z()][old_pos.get_y()][old_pos.get_x()];
		(bool)dat[old_pos.get_z()][old_pos.get_y()][old_pos.get_x()];
		dat[new_pos.get_z()][new_pos.get_y()][new_pos.get_x()] = obj;
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	size_t matrix<type, _breadth, _height, _width>::get_capacity() const {
		return size_obj.get_capacity();
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	size_t matrix<type, _breadth, _height, _width>::get_breadth() const{
		return size_obj.get_breadth();
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	size_t matrix<type, _breadth, _height, _width>::get_height() const{
		return size_obj.get_height();
	}

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	size_t matrix<type, _breadth, _height, _width>::get_width() const{
		return size_obj.get_width();
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
	dimensional_pos matrix<type, _breadth, _height, _width>::get_loc(type& t) {
		dimensional_pos internal;
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
						t = obj;
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
	matrix<type, _breadth, _height, _width>::operator size_t() const {
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

	template<typename type, size_t _breadth, size_t _height, size_t _width>
	dimensional_size<_breadth, _height, _width> matrix<type, _breadth, _height, _width>::metadata(){
		return size_obj;
	}

	template<typename type>
	void make_file(matrix<type> src, std::string filename, mtxio mode) {
		if (mode == std) {
			filename.append(".mtx");
			std::ofstream file(filename, ios::binary | ios::trunc);
			for (pos z = 0; z < src.get_breadth(); z++) {
				for (pos y = 0; y < src.get_height(); y++) {
					for (pos x = 0; x < src.get_width(); x++) {
						file << metadata(src) << std::endl;
						file << marker(dimensional_pos(z, y, x)) << "\t" << src.access(z, x, y) << std::endl;
					}
				}
			}
		}
		if (mode == cpy) {
			std::ofstream copy(filename, ios::binary | ios::trunc);
			filename.append(".mtx");
			std::ofstream file(filename, ios::binary | ios::trunc);
			for (pos z = 0; z < src.get_breadth(); z++) {
				for (pos y = 0; y < src.get_height(); y++) {
					for (pos x = 0; x < src.get_width(); x++) {
						file << metadata(src) << std::endl;
						file << marker(dimensional_pos(z, y, x)) << "\t" << src.access(z, x, y) << std::endl;
						copy << metadata(src) << std::endl;
						copy << marker(dimensional_pos(z, y, x)) << "\t" << src.access(z, x, y) << std::endl;
					}
				}
			}
		}
		if (mode == safe) {
			std::ofstream copy(filename, ios::trunc);
			filename.append(".mtx");
			std::ofstream file(filename, ios::binary | ios::trunc);
			for (pos z = 0; z < src.get_breadth(); z++) {
				for (pos y = 0; y < src.get_height(); y++) {
					for (pos x = 0; x < src.get_width(); x++) {
						file << metadata(src) << std::endl;
						file << marker(dimensional_pos(z, y, x)) << "\t" << src.access(z, x, y) << std::endl;
						copy << metadata(src) << std::endl;
						copy << marker(dimensional_pos(z, y, x)) << "\t" << src.access(z, x, y) << std::endl;
					}
				}
			}
		}
	}
	template<typename type>
	void read_file(matrix<type> dest, std::string filename){
		std::ifstream file(filename, ios::binary | ios::trunc);
		std::string metadata;
		std::string type_metadata;
		file >> metadata;
		file >> type_metadata;
		dimensional_size<> size = read_metadata(metadata);
		std::string nametype = identity_type(type_metadata);
		std::string typemtx = typeid(type);
		if (typemtx != nametype) {
			std::cerr << "Incompatible matrix types. \nSource type [" << nametype << "] is incompatible with Destination type [" << typemtx << "]";
		}
		else {
			if (size != dest.metadata()) {
				std::clog << "Incompatible dimensional sizes.\nResizing destination to fit Source";
				dest.resize(size.get_breadth(), size.get_height(), size.get_width());
			}
			else {
				for (size_t i = 0; i < size.get_breadth(); i++) {
					for (size_t j = 0; j < size.get_height(); j++) {
						for (size_t k = 0; k < size.get_width(); k++) {
							dimensional_pos markerpos(0, 0, 0);
							std::string marker = "";
							file >> marker;
							markerpos = read_marker(marker);
							if (markerpos == dimensional_pos(i, j, k)) {
								std::string content = "";
								file >> content;
								type obj;
								read_content(obj, content);
								dest.assign(obj, i, j, k);
							}
							else {
								std::cerr << "Broken MATRIX file (*.mtx) at dimensional_pos(" << i << "::" << j << "::" << k << ").";
							}
						}
					}
				}
			}
		}
	}
	template<typename type>
	std::string metadata(matrix<type> obj){
		std::stringstream internal = "";
		internal << "[" << obj.get_capacity() << "::" << obj.get_breadth() << "::" << obj.get_height() << " ::" << obj.get_width() << "]\t[" << typeid(type) << "]";
		return internal.str();
	}
	template<typename type>
	void read_content(type obj, std::string content){
		type internal;
		std::stringstream ss;
		ss << content;
		ss >> internal;
		obj = internal;
	}
	template<typename type>
	void mtx_init(matrix<type> mtx, mtxio mode){
		if (mode == sta) {
			for (pos z = 0; z < mtx.get_breadth(); z++) {
				for (pos y = 0; y < mtx.get_height(); y++) {
					for (pos x = 0; x < mtx.get_width(); x++) {
						double clu = (z * mtx.get_breadth()) + (y * mtx.get_height()) + x;
						type obj(clu);
						mtx.assign(obj, z, y, x);
					}
				}
			}
		}
		else if (mode == cta) {

		}
		else if (mode == bbta) {

		}
		else if (mode == rsta) {

		}
		else if (mode == rcta) {

		}
	}
	std::string marker(dimensional_pos obj){
		std::stringstream internal;
		internal << obj.get_z() << "-" << obj.get_y() << "-" << obj.get_x() << ":";
		return internal.str();
	}
	dimensional_size<> read_metadata(std::string metadata){
		std::string internal = metadata;
		internal.erase(internal.begin());
		size_t z_size = 0;
		for (z_size; internal[z_size+1]!=':'; z_size++) {
			if (internal[z_size] != (48 & 49 & 50 & 51 & 52 & 53 & 54 & 55 & 56 & 57)) {
				std::cerr << "MATRIX File (*.mtx) has been corrupted";
			}
		}
		std::string str_bdt = "";
		str_bdt.assign(internal, z_size, 0);
		internal.erase(0, (z_size + 2));
		size_t y_size = 0;
		for (y_size; internal[y_size + 1] != ':'; y_size++) {
			if (internal[z_size] != (48 & 49 & 50 & 51 & 52 & 53 & 54 & 55 & 56 & 57)) {
				std::cerr << "MATRIX File (*.mtx) has been corrupted";
			}
		}
		std::string str_hgt = "";
		str_hgt.assign(internal, y_size, 0);
		internal.erase(0, (y_size + 2));
		size_t x_size = 0;
		for (x_size; internal[x_size + 1] != ':'; x_size++) {
			if (internal[z_size] != (48 & 49 & 50 & 51 & 52 & 53 & 54 & 55 & 56 & 57)) {
				std::cerr << "MATRIX File (*.mtx) has been corrupted";
			}
		}
		std::string str_wdt = "";
		str_wdt.assign(internal, x_size, 0);
		internal.erase(0, (x_size + 2));
		std::stringstream ss;
		ss << str_bdt << " " << str_hgt << " " << str_wdt;
		size_t breadth = 0;
		size_t height = 0;
		size_t width = 0;
		ss >> breadth >> height >> width;
		return dimensional_size<>(breadth, height, width);
	}
	dimensional_pos read_marker(std::string marker){
		std::string internal = marker;
		internal.erase(internal.begin());
		size_t z_size = 0;
		for (z_size; internal[z_size + 1] != '-'; z_size++) {
			if (internal[z_size] != (48 & 49 & 50 & 51 & 52 & 53 & 54 & 55 & 56 & 57)) {
				std::cerr << "MATRIX File (*.mtx) has been corrupted";
			}
		}
		std::string str_z = "";
		str_z.assign(internal, z_size, 0);
		internal.erase(0, (z_size + 1));
		size_t y_size = 0;
		for (y_size; internal[y_size + 1] != '-'; y_size++) {
			if (internal[z_size] != (48 & 49 & 50 & 51 & 52 & 53 & 54 & 55 & 56 & 57)) {
				std::cerr << "MATRIX File (*.mtx) has been corrupted";
			}
		}
		std::string str_y = "";
		str_y.assign(internal, y_size, 0);
		internal.erase(0, (y_size + 1));
		size_t x_size = 0;
		for (x_size; internal[x_size + 1] != '-'; x_size++) {
			if (internal[z_size] != (48 & 49 & 50 & 51 & 52 & 53 & 54 & 55 & 56 & 57)) {
				std::cerr << "MATRIX File (*.mtx) has been corrupted";
			}
		}
		std::string str_x = "";
		str_x.assign(internal, x_size, 0);
		internal.erase(0, (x_size + 1));
		std::stringstream ss;
		ss << str_z << " " << str_y << " " << str_x;
		size_t z = 0;
		size_t y = 0;
		size_t x = 0;
		ss >> z >> y >> x;
		return dimensional_pos(z, y, x);
	}
	std::string identity_type(std::string type_metadata){
		std::string internal = "";
		internal.assign(type_metadata, 1, type_metadata.size()-2);
		return internal;
	}
}