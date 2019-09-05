#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <typeinfo>
#include <fstream>
#include <algorithm>

#ifndef _CONTAINER_H_
#define _CONTAINER_H_
namespace s_cont {
	template<typename type>
	static bool sortUtil_ascend(type _src1, type _src2) {
		return _src1 < _src2;
	}

	template<typename type>
	static bool sortUtil_descend(type _src1, type _src2) {
		return _src1 > _src2;
	}

	enum cont_stream {
		std,
		hex
	};

	template<typename type>
	class container {
	private:
		size_t sz;
		type* space;
	public:

		// Initialization

		container(size_t size = 0);
		container(type* arr);
		~container();

		// Base Use Utility

		void reserve(size_t size = 255);
		void resize(size_t new_size = 255);
		type access(int64_t i) const;
		void assign(type obj, uint64_t i);
		void push_back(type obj);
		uint64_t find(type obj);
		type begin();
		type end();

		// Common Use Utility

		type* arr();
		type* unique_items();
		type* sub_arr(uint64_t index, uint64_t offset = 0);
		container<type> sub_cont(uint64_t index, uint64_t offset = 0);

		// Containment and Internal Management Utility

		size_t size() const;
		double occupancy();
		double occupancy_percent();
		bool isfull();
		void fill(type& obj);
		uint64_t count(type& obj);
		double count_percent(type& obj);
		size_t amount_unique();
		size_t* count_unique();
		bool exists(type obj) const;
		void destroy(type obj);
		void delete_pos(uint64_t i);
		void counting_sort();
		void reverse();

		// Initialization Operators

		void operator= (container<type>& cont);
		void operator= (type*& arr);
		void operator= (bool bln);

		// Boolean Comparison Operators

		bool operator== (container<type>& cont);
		bool operator== (type*& arr);
		bool operator!= (container<type>& cont);
		bool operator!= (type*& arr);
		bool operator< (container<type>& cont);
		bool operator<= (container<type>& cont);
		bool operator> (container<type>& cont);
		bool operator>= (container<type>& cont);
		
		// Cast Operators

		operator bool() const;
		operator double() const;
		operator uint64_t() const;
		operator type* ()const;

		// Common Use Operators

		void operator++();
		void operator--();
		void operator+ (uint64_t add_size);
		container<type> operator+(container<type>& cont);
		void operator- (uint64_t min_size);
		container<type> operator-(container<type>& cont);
		type operator[](uint64_t i);
#ifdef _ALGORITHM_
		void ascending_sort();
		void descending_sort();
#endif
		
#if defined _VECTOR_
		container(std::vector<type> vect);
		template<typename utpe> container(std::vector<utpe> vect);

		std::vector<type> vect();

		void operator= (std::vector<type> vect);
		template<typename utpe> void operator= (std::vector<utpe> vect);
#endif

#if defined _IOSTREAM_ && defined _SSTREAM_
		void catch_input(size_t stream_size, cont_stream mode = cont_stream::std);
		void print_out(cont_stream mode = cont_stream::std);

		template <typename utpe> void transpose(container<utpe>& cont, cont_stream mode = cont_stream::std);
		template <typename utpe> void metapose(utpe*& arr, cont_stream mode = cont_stream::std);
#ifdef _VECTOR_
		template <typename utpe> void stlpose(std::vector<utpe>& vect, cont_stream mode = cont_stream::std);
#endif 
#ifdef _TYPEINFO_
		std::string iterator_type();
#endif
#endif
	protected:
		type* duplicate(type*& src);
		void flush();
		type* merge(type* _src1, type* _src2);
		type* demerge(type* _src1, type* _src2);
	};

	// Initialization

	template<typename type>
	inline container<type>::container(size_t size)
		: sz(size)
		, space(new type[sz])
	{}

	template<typename type>
	inline container<type>::container(type * arr)
		: sz((sizeof(arr)/sizeof(type)))
		, space(new type[sz])

	{
		for (uint64_t i = 0; i < sz; i++) {
			space[i] = arr[i];
		}
	}

	template<typename type>
	inline container<type>::~container(){
		flush();
	}

	// Base Use Utility

	template<typename type>
	inline void container<type>::reserve(size_t size){
		sz = size;
		space = new type[sz];
	}

	template<typename type>
	inline void container<type>::resize(size_t new_size){
		type* backup = duplicate(space);
		size_t back_sz = sz;
		for (uint64_t i = 0; i < back_sz; i++) {
			backup[i] = space[i];
		}
		delete[] space;
		sz = new_size;
		space = new type[(sizeof(type) * sz)];
		if (sz >= back_sz) {
			for (uint64_t i = 0; i < back_sz; i++) {
				space[i] = backup[i];
			}
		}
		else if (sz < back_sz) {
			for (uint64_t i = 0; i < sz; i++) {
				space[i] = backup[i];
			}
		}
		delete[] backup;
	}

	template<typename type>
	inline type container<type>::access(int64_t i) const{
		return type(space[i]);
	}

	template<typename type>
	inline void container<type>::assign(type obj, uint64_t i){
		space[i] = obj;
	}

	template<typename type>
	inline void container<type>::push_back(type obj){
		resize(sz++);
		space[sz] = obj;
	}

	template<typename type>
	inline uint64_t container<type>::find(type obj){
		uint64_t loc = 0;
		for (uint64_t i = 0; i < sz; loc++) {
			if (space[i] = obj) {
				loc = i;
				return loc;
			}
		}
		return uint64_t(sz);
	}

	template<typename type>
	inline type container<type>::begin(){
		return type(space[0]);
	}

	template<typename type>
	inline type container<type>::end(){
		return type(space[sz - 1]);
	}

	// Common Use Utility

	template<typename type>
	inline type* container<type>::arr(){
		return space;
	}

	template<typename type>
	inline type* container<type>::unique_items(){
		size_t size = amount_unique();
		type* internal = new type[size];
		uint64_t index = 0;
		for (uint64_t i = 0; i < sz; i++) {
			if (space[i] != internal[index]) {
				internal[index] = space[i];
				index++;
			}
		}
		return internal;
	}

	template<typename type>
	inline type* container<type>::sub_arr(uint64_t index, uint64_t offset){
		size_t size = index - offset;
		type* internal = new type[size * sizeof(type)];
		for (uint64_t i = 0; i < size; i++) {
			internal[i] = space[index + offset];
		}
		return internal;
	}

	template<typename type>
	inline container<type> container<type>::sub_cont(uint64_t index, uint64_t offset){
		return container<type>(sub_arr(index, offset));
	}

	// Containment and Internal Management Utility

	template<typename type>
	inline size_t container<type>::size() const{
		return size_t(sz);
	}

	template<typename type>
	inline double container<type>::occupancy(){
		uint64_t  count = 0;
		for (uint64_t i = 0; i < sz; i++) {
			if (space[i]) count++;
		}
		return double(count);
	}

	template<typename type>
	inline double container<type>::occupancy_percent(){
		return occupancy() / size();
	}

	template<typename type>
	inline bool container<type>::isfull(){
		if (occupancy_percent() != 1) return false;
		else if (occupancy_percent() == 1) return true;
	}

	template<typename type>
	inline void container<type>::fill(type& obj){
		for (uint64_t i = 0; i < sz; i++) {
			if (!(space[i])) space[i] = obj;
		}
	}

	template<typename type>
	inline uint64_t container<type>::count(type& obj){
		uint64_t internal = 0;
		for (uint64_t i = 0; i < sz; i++) {
			if (space[i] == obj) internal++;
		}
		return uint64_t(internal);
	}

	template<typename type>
	inline double container<type>::count_percent(type& obj){
		return count(obj) / size();
	}

	template<typename type>
	inline size_t container<type>::amount_unique(){
		size_t internal = 1;
		container<type> index;
		index.push_back(space[0]);
		for (uint64_t i = 0; i < sz; i++) {
			for (uint64_t j = 0; j = index.size(); j++) {
				if (space[i] != index[j]) internal++;
			}
		}
		return size_t(internal);
	}

	template<typename type>
	inline size_t* container<type>::count_unique(){
		container<type> index;
		container<size_t> internal(amount_unique());
		index.push_back(space[0]);
		uint64_t counter = 0;
		for (uint64_t i = 0; i < sz; i++) {
			for (uint64_t j = 0; j < index.size(); j++) {
				if (space[i] != index[j]) {
					internal[counter] = space[i];
					counter++;
				}
			}
		}
		return internal.arr();
	}

	template<typename type>
	inline bool container<type>::exists(type obj) const{
		for (uint64_t i = 0; i < sz; i++) {
			if (space[i] == obj) return true;
			else if ((i == sz && space[i - 1] != obj)) return false;
		}
	}

	template<typename type>
	inline void container<type>::destroy(type obj){
		for (uint64_t i = 0; i < sz; i++) {
			if (space[i] == obj) (bool)space[i] = false;
		}
	}

	template<typename type>
	inline void container<type>::delete_pos(uint64_t i){
		(bool)space[i] = false;
	}

	template<typename type>
	inline void container<type>::counting_sort(){
		
	}

	// Initialization Operators

	template<typename type>
	inline void container<type>::operator=(container<type>& cont){
		container(cont.arr());
	}

	template<typename type>
	inline void container<type>::operator=(type*& arr){
		container(arr);
	}

	template<typename type>
	inline void container<type>::operator=(bool bln){
		if (bln == false) flush();
	}

	// Boolean Comparison Operators

	template<typename type>
	inline bool container<type>::operator==(container<type>& cont){
		if (sz != cont.size()) return false;
		else if (sz == cont.size()) {
			for (uint64_t i = 0; i < sz; i++) {
				if (space[i] != cont.access(i)) return false;
				else if (space[i - 1] == cont.access(i - 1) && i == sz) return true;
			}
		}
		size_t i = cont->space;
	}

	template<typename type>
	inline bool container<type>::operator==(type*& arr){
		return this==(container(arr));
	}

	template<typename type>
	inline bool container<type>::operator!=(container<type>& cont){
		return !(this==(cont));
	}

	template<typename type>
	inline bool container<type>::operator!=(type*& arr){
		return operator!=(container(type));
	}

	template<typename type>
	inline bool container<type>::operator<(container<type>& cont){
		if (sz < cont.size()) return true;
		else return false;
	}

	template<typename type>
	inline bool container<type>::operator<=(container<type>& cont){
		if (sz <= cont.size()) return true;
		else return false;
	}

	template<typename type>
	inline bool container<type>::operator>(container<type>& cont){
		return (sz > cont.size());
	}

	template<typename type>
	inline bool container<type>::operator>=(container<type>& cont){
		return (sz >= cont.size());
	}

	// Cast Operators

	template<typename type>
	inline container<type>::operator bool() const{
		return isfull();
	}

	template<typename type>
	inline container<type>::operator double() const{
		return occupancy_percent();
	}

	template<typename type>
	inline container<type>::operator uint64_t() const{
		return size();
	}

	template<typename type>
	inline container<type>::operator type* () const{
		return arr();
	}

	// Common Use Operators

	template<typename type>
	inline void container<type>::operator++(){
		resize(sz++);
	}

	template<typename type>
	inline void container<type>::operator--(){
		resize(sz--);
	}

	template<typename type>
	inline void container<type>::operator+(uint64_t add_size){
		resize(sz + add_size);
	}

	template<typename type>
	inline container<type> container<type>::operator+(container<type>& cont){
		type* internal = merge(space, cont.arr());
		return container<type>(internal);
	}

	template<typename type>
	inline void container<type>::operator-(uint64_t min_size){
		resize(sz - min_size);
	}

	template<typename type>
	inline container<type> container<type>::operator-(container<type>& cont){
		type* internal = demerge(space, cont.arr());
		return container<type>(internal);
	}

	template<typename type>
	inline type container<type>::operator[](uint64_t i){
		return access(i);
	}

#ifdef _CONTAINER_H_
	typedef container<int>					cont_int;
	typedef container<char>					cont_chr;
	typedef container<bool>					cont_bln;
	typedef container<float>				cont_flt;
	typedef container<double>				cont_dbl;
	typedef container<wchar_t>				cont_wch;
#if defined _IOSTREAM_ && defined _CSTRING_
	typedef container<std::string>			cont_str;
	typedef container<std::wstring>			cont_wst;
#endif
#if defined _IOSTREAM_ && defined _SSTREAM_
	typedef container<std::stringstream>	cont_sst;
	typedef container<std::ostringstream>	cont_ost;
	typedef container<std::istringstream>	cont_ist;
#endif
#ifdef _IOSTREAM_
	typedef container<std::istream>			cont_istream;
	typedef container<std::ostream>			cont_ostream;
#endif
#ifdef _FSTREAM_
	typedef container<std::fstream>			cont_fstream;
	typedef container<std::wfstream>		cont_wfstream;
	typedef container<std::ifstream>		cont_ifstream;
	typedef container<std::wifstream>		cont_wifstream;
	typedef container<std::ofstream>		cont_ofstream;
	typedef container<std::wofstream>		cont_wofstream;
#endif
#endif
	
	// Protected

	template<typename type>
	inline type* container<type>::duplicate(type*& src){
		return src;
	}

	template<typename type>
	inline void container<type>::flush(){
		sz = 0;
		delete[] space;
	}

	template<typename type>
	inline type* container<type>::merge(type* _src1, type* _src2){
		type* internal = new type[(sizeof(_src1) + sizeof(_src2))];
		size_t size1 = (sizeof(_src1) / sizeof(type));
		size_t size2 = (sizeof(_src2) / sizeof(type));
		for (uint64_t i = 0; i < size1; i++) {
			internal[i] = _src1[i];
		}
		for (uint64_t i = 0; i < size2; i++) {
			internal[i + size1] = _src2[i];
		}
		return internal;
	}

	template<typename type>
	inline type* container<type>::demerge(type* _src1, type* _src2){
		if (sizeof(_src1) < sizeof(_src2)) {
#ifdef _IOSTREAM_
			operator << (std::cerr, "SECOND SOURCRE (_src2) SIZE IS GREATER THAN FIRST (_src1).");
#endif
			return NULL;
		}
		else {
			type* internal = new type[(sizeof(_src1) - sizeof(_src2))];
			for (uint64_t i = 0; i < (sizeof(internal) / sizeof(type)); i++) {

			}
			return internal;
		}
	}

	// Common Use Operators Left hand fix

	template<typename type>
	void operator++(container<type> cont) {
		cont.resize(cont.size()++);
	}

	template<typename type>
	void operator--(container<type> cont) {
		cont.resize(cont.size()--);
	}
}
#endif