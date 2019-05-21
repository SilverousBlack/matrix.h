#pragma once

#include <iostream>
#include <stdarg.h>
#include <vector>

#define _DIMENSIONAL_H_

using namespace std;

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

template<size_t z, size_t y, size_t x>
dimensional_size<z, y, x>::dimensional_size()
        : absolute_x(x), absolute_y(y), absolute_z(z) {
}

template<size_t z, size_t y, size_t x>
dimensional_size<z, y, x>::dimensional_size(size_t oz, size_t oy, size_t ox)
        : absolute_x(ox), absolute_y(oy), absolute_z(oz) {
}

template<size_t z, size_t y, size_t x>
dimensional_size<z, y, x>::~dimensional_size() {
    delete &absolute_z;
    delete &absolute_y;
    delete &absolute_x;
}

template<size_t z, size_t y, size_t x>
size_t dimensional_size<z, y, x>::get_capacity() {
    return absolute_x * absolute_y * absolute_z;
}

template<size_t z, size_t y, size_t x>
size_t dimensional_size<z, y, x>::get_breadth() {
    return absolute_z;
}

template<size_t z, size_t y, size_t x>
size_t dimensional_size<z, y, x>::get_height() {
    return absolute_y;
}

template<size_t z, size_t y, size_t x>
size_t dimensional_size<z, y, x>::get_width() {
    return absolute_x;
}

template<size_t z, size_t y, size_t x>
void dimensional_size<z, y, x>::up_size(size_t z, size_t y, size_t x) {
    absolute_z = z;
    absolute_y = y;
    absolute_x = x;
}

template<typename type>
class dimensional_pos {
public:
    dimensional_pos();

    dimensional_pos(pos z = 0, pos y = 0, pos x = 0);

    ~dimensional_pos();

    dimensional_pos &get_pos(vector <type> stream, type &t);

    dimensional_pos &get_pos(vector <vector<type>> stream, type &t);

    dimensional_pos &get_pos(vector <vector<vector < type>>

    > stream,
    type &t
    );

    pos get_z();

    pos get_y();

    pos get_x();

private:
    pos absolute_x;
    pos absolute_y;
    pos absolute_z;
};

template<typename type>
dimensional_pos<type>::dimensional_pos()
        : absolute_x(0), absolute_y(0), absolute_z(0) {
}

template<typename type>
dimensional_pos<type>::dimensional_pos(pos z, pos y, pos x)
        : absolute_x(x), absolute_y(y), absolute_z(z) {
}

template<typename type>
dimensional_pos<type>::~dimensional_pos() {
    delete absolute_x;
    delete absolute_y;
    delete absolute_z;
}

template<typename type>
dimensional_pos<type> &dimensional_pos<type>::get_pos(vector <type> stream, type &t) {
    dimensional_pos<type> obj;
    for (pos i = 0; i < stream.size(); i++) {
        if (t == stream[i]) {
            obj(i);
            return obj;
        }
    }
}

template<typename type>
dimensional_pos<type> &dimensional_pos<type>::get_pos(vector <vector<type>> stream, type &t) {
    dimensional_pos<type> obj;
    for (pos i = 0; i < stream.size(); i++) {
        for (pos j = 0; j < stream[i].size(); j++) {
            if (t == stream[i][j]) {
                obj(i, j);
                return obj;
            }
        }
    }
}

template<typename type>
dimensional_pos<type> &dimensional_pos<type>::get_pos(vector < vector < vector < type >> > stream, type & t) {
    dimensional_pos<type> obj;
    for (pos i = 0; i < stream.size(); i++) {
        for (pos j = 0; j < stream[i].size(); j++) {
            for (pos k = 0; k < stream[i][j].size(); k++) {
                if (t == stream[i][j][k]) {
                    obj(i, j, k);
                    return obj;
                }
            }
        }
    }
}

template<typename type>
pos dimensional_pos<type>::get_z() {
    return absolute_z;
}

template<typename type>
pos dimensional_pos<type>::get_y() {
    return absolute_y;
}

template<typename type>
pos dimensional_pos<type>::get_x() {
    return absolute_x;
}