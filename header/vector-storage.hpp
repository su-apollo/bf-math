#pragma once
#include "swizzle.hpp"

#include <exception>

namespace bf {
namespace math {
template <typename T, std::size_t N>
class vector_storage;

#define BF_SWIZZLES_X(_x) \
	const swizzle<T, N, 2, 0, 0> _x##_x; \
	const swizzle<T, N, 3, 0, 0, 0> _x##_x##_x; \
	const swizzle<T, N, 4, 0, 0, 0, 0> _x##_x##_x##_x


template <typename T>
class vector_storage<T, 1> {
protected:
	static const std::size_t N = 1;

public:
	union {
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;

		BF_SWIZZLES_X(x);
		BF_SWIZZLES_X(r);
		BF_SWIZZLES_X(s);
	};

	vector_storage() {
	}

	T& operator [] (std::size_t i) {
		return reinterpret_cast<T*>(this)[i];
	}

	const T& operator [] (std::size_t i) const {
		return reinterpret_cast<const T*>(this)[i];
	}

	vector_storage& operator = (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = operand;

		return *this;
	}

	vector_storage& operator = (T&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand);

		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		
		for (auto i = 0; i < N; ++i)
			(*this)[i] = temp[i];
		
		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (vector_usage<T2, N, S2>&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand[i]);

		return *this;
	}
};

#define BF_SWIZZLES_XY(_x, _y) \
	swizzle<T, N, 2, 0, 1> _x##_y; \
	swizzle<T, N, 2, 1, 0> _y##_x; \
	const swizzle<T, N, 2, 1, 1> _y##_y; \
	const swizzle<T, N, 3, 0, 0, 1> _x##_x##_y; \
	const swizzle<T, N, 3, 0, 1, 0> _x##_y##_x; \
	const swizzle<T, N, 3, 0, 1, 1> _x##_y##_y; \
	const swizzle<T, N, 3, 1, 0, 0> _y##_x##_x; \
	const swizzle<T, N, 3, 1, 0, 1> _y##_x##_y; \
	const swizzle<T, N, 3, 1, 1, 0> _y##_y##_x; \
	const swizzle<T, N, 3, 1, 1, 1> _y##_y##_y; \
	const swizzle<T, N, 4, 0, 0, 0, 1> _x##_x##_x##_y; \
	const swizzle<T, N, 4, 0, 0, 1, 0> _x##_x##_y##_x; \
	const swizzle<T, N, 4, 0, 0, 1, 1> _x##_x##_y##_y; \
	const swizzle<T, N, 4, 0, 1, 0, 0> _x##_y##_x##_x; \
	const swizzle<T, N, 4, 0, 1, 0, 1> _x##_y##_x##_y; \
	const swizzle<T, N, 4, 0, 1, 1, 0> _x##_y##_y##_x; \
	const swizzle<T, N, 4, 0, 1, 1, 1> _x##_y##_y##_y; \
	const swizzle<T, N, 4, 1, 0, 0, 0> _y##_x##_x##_x; \
	const swizzle<T, N, 4, 1, 0, 0, 1> _y##_x##_x##_y; \
	const swizzle<T, N, 4, 1, 0, 1, 0> _y##_x##_y##_x; \
	const swizzle<T, N, 4, 1, 0, 1, 1> _y##_x##_y##_y; \
	const swizzle<T, N, 4, 1, 1, 0, 0> _y##_y##_x##_x; \
	const swizzle<T, N, 4, 1, 1, 0, 1> _y##_y##_x##_y; \
	const swizzle<T, N, 4, 1, 1, 1, 0> _y##_y##_y##_x; \
	const swizzle<T, N, 4, 1, 1, 1, 1> _y##_y##_y##_y

template <typename T>
class vector_storage<T, 2> {
protected:
	static const std::size_t N = 2;

public:
	union {
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		swizzle<T, N, 1, 1> y;
		swizzle<T, N, 1, 1> g;
		swizzle<T, N, 1, 1> t;

		BF_SWIZZLES_X(x);
		BF_SWIZZLES_XY(x, y);

		BF_SWIZZLES_X(r);
		BF_SWIZZLES_XY(r, g);

		BF_SWIZZLES_X(s);
		BF_SWIZZLES_XY(s, t);
	};

	vector_storage() {
	}

	T& operator [] (std::size_t i) {
		return reinterpret_cast<T*>(this)[i];
	}

	const T& operator [] (std::size_t i) const {
		return reinterpret_cast<const T*>(this)[i];
	}

	vector_storage& operator = (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = operand;

		return *this;
	}

	vector_storage& operator = (T&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand);

		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;

		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];

		for (auto i = 0; i < N; ++i)
			(*this)[i] = temp[i];

		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (vector_usage<T2, N, S2>&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand[i]);

		return *this;
	}
};

#define BF_SWIZZLES_XYZ(_x, _y, _z) \
	swizzle<T, N, 2, 0, 2> _x##_z; \
	swizzle<T, N, 2, 1, 2> _y##_z; \
	swizzle<T, N, 2, 2, 0> _z##_x; \
	swizzle<T, N, 2, 2, 1> _z##_y; \
	const swizzle<T, N, 2, 2, 2> _z##_z; \
	const swizzle<T, N, 3, 0, 0, 2> _x##_x##_z; \
	swizzle<T, N, 3, 0, 1, 2> _x##_y##_z; \
	const swizzle<T, N, 3, 0, 2, 0> _x##_z##_x; \
	swizzle<T, N, 3, 0, 2, 1> _x##_z##_y; \
	const swizzle<T, N, 3, 0, 2, 2> _x##_z##_z; \
	swizzle<T, N, 3, 1, 0, 2> _y##_x##_z; \
	const swizzle<T, N, 3, 1, 1, 2> _y##_y##_z; \
	swizzle<T, N, 3, 1, 2, 0> _y##_z##_x; \
	const swizzle<T, N, 3, 1, 2, 1> _y##_z##_y; \
	const swizzle<T, N, 3, 1, 2, 2> _y##_z##_z; \
	const swizzle<T, N, 3, 2, 0, 0> _z##_x##_x; \
	swizzle<T, N, 3, 2, 0, 1> _z##_x##_y; \
	const swizzle<T, N, 3, 2, 0, 2> _z##_x##_z; \
	swizzle<T, N, 3, 2, 1, 0> _z##_y##_x; \
	const swizzle<T, N, 3, 2, 1, 1> _z##_y##_y; \
	const swizzle<T, N, 3, 2, 1, 2> _z##_y##_z; \
	const swizzle<T, N, 3, 2, 2, 0> _z##_z##_x; \
	const swizzle<T, N, 3, 2, 2, 1> _z##_z##_y; \
	const swizzle<T, N, 3, 2, 2, 2> _z##_z##_z; \
	const swizzle<T, N, 4, 0, 0, 0, 2> _x##_x##_x##_z; \
	const swizzle<T, N, 4, 0, 0, 1, 2> _x##_x##_y##_z; \
	const swizzle<T, N, 4, 0, 0, 2, 0> _x##_x##_z##_x; \
	const swizzle<T, N, 4, 0, 0, 2, 1> _x##_x##_z##_y; \
	const swizzle<T, N, 4, 0, 0, 2, 2> _x##_x##_z##_z; \
	const swizzle<T, N, 4, 0, 1, 0, 2> _x##_y##_x##_z; \
	const swizzle<T, N, 4, 0, 1, 1, 2> _x##_y##_y##_z; \
	const swizzle<T, N, 4, 0, 1, 2, 0> _x##_y##_z##_x; \
	const swizzle<T, N, 4, 0, 1, 2, 1> _x##_y##_z##_y; \
	const swizzle<T, N, 4, 0, 1, 2, 2> _x##_y##_z##_z; \
	const swizzle<T, N, 4, 0, 2, 0, 0> _x##_z##_x##_x; \
	const swizzle<T, N, 4, 0, 2, 0, 1> _x##_z##_x##_y; \
	const swizzle<T, N, 4, 0, 2, 0, 2> _x##_z##_x##_z; \
	const swizzle<T, N, 4, 0, 2, 1, 0> _x##_z##_y##_x; \
	const swizzle<T, N, 4, 0, 2, 1, 1> _x##_z##_y##_y; \
	const swizzle<T, N, 4, 0, 2, 1, 2> _x##_z##_y##_z; \
	const swizzle<T, N, 4, 0, 2, 2, 0> _x##_z##_z##_x; \
	const swizzle<T, N, 4, 0, 2, 2, 1> _x##_z##_z##_y; \
	const swizzle<T, N, 4, 0, 2, 2, 2> _x##_z##_z##_z; \
	const swizzle<T, N, 4, 1, 0, 0, 2> _y##_x##_x##_z; \
	const swizzle<T, N, 4, 1, 0, 1, 2> _y##_x##_y##_z; \
	const swizzle<T, N, 4, 1, 0, 2, 0> _y##_x##_z##_x; \
	const swizzle<T, N, 4, 1, 0, 2, 1> _y##_x##_z##_y; \
	const swizzle<T, N, 4, 1, 0, 2, 2> _y##_x##_z##_z; \
	const swizzle<T, N, 4, 1, 1, 0, 2> _y##_y##_x##_z; \
	const swizzle<T, N, 4, 1, 1, 1, 2> _y##_y##_y##_z; \
	const swizzle<T, N, 4, 1, 1, 2, 0> _y##_y##_z##_x; \
	const swizzle<T, N, 4, 1, 1, 2, 1> _y##_y##_z##_y; \
	const swizzle<T, N, 4, 1, 1, 2, 2> _y##_y##_z##_z; \
	const swizzle<T, N, 4, 1, 2, 0, 0> _y##_z##_x##_x; \
	const swizzle<T, N, 4, 1, 2, 0, 1> _y##_z##_x##_y; \
	const swizzle<T, N, 4, 1, 2, 0, 2> _y##_z##_x##_z; \
	const swizzle<T, N, 4, 1, 2, 1, 0> _y##_z##_y##_x; \
	const swizzle<T, N, 4, 1, 2, 1, 1> _y##_z##_y##_y; \
	const swizzle<T, N, 4, 1, 2, 1, 2> _y##_z##_y##_z; \
	const swizzle<T, N, 4, 1, 2, 2, 0> _y##_z##_z##_x; \
	const swizzle<T, N, 4, 1, 2, 2, 1> _y##_z##_z##_y; \
	const swizzle<T, N, 4, 1, 2, 2, 2> _y##_z##_z##_z; \
	const swizzle<T, N, 4, 2, 0, 0, 0> _z##_x##_x##_x; \
	const swizzle<T, N, 4, 2, 0, 0, 1> _z##_x##_x##_y; \
	const swizzle<T, N, 4, 2, 0, 0, 2> _z##_x##_x##_z; \
	const swizzle<T, N, 4, 2, 0, 1, 0> _z##_x##_y##_x; \
	const swizzle<T, N, 4, 2, 0, 1, 1> _z##_x##_y##_y; \
	const swizzle<T, N, 4, 2, 0, 1, 2> _z##_x##_y##_z; \
	const swizzle<T, N, 4, 2, 0, 2, 0> _z##_x##_z##_x; \
	const swizzle<T, N, 4, 2, 0, 2, 1> _z##_x##_z##_y; \
	const swizzle<T, N, 4, 2, 0, 2, 2> _z##_x##_z##_z; \
	const swizzle<T, N, 4, 2, 1, 0, 0> _z##_y##_x##_x; \
	const swizzle<T, N, 4, 2, 1, 0, 1> _z##_y##_x##_y; \
	const swizzle<T, N, 4, 2, 1, 0, 2> _z##_y##_x##_z; \
	const swizzle<T, N, 4, 2, 1, 1, 0> _z##_y##_y##_x; \
	const swizzle<T, N, 4, 2, 1, 1, 1> _z##_y##_y##_y; \
	const swizzle<T, N, 4, 2, 1, 1, 2> _z##_y##_y##_z; \
	const swizzle<T, N, 4, 2, 1, 2, 0> _z##_y##_z##_x; \
	const swizzle<T, N, 4, 2, 1, 2, 1> _z##_y##_z##_y; \
	const swizzle<T, N, 4, 2, 1, 2, 2> _z##_y##_z##_z; \
	const swizzle<T, N, 4, 2, 2, 0, 0> _z##_z##_x##_x; \
	const swizzle<T, N, 4, 2, 2, 0, 1> _z##_z##_x##_y; \
	const swizzle<T, N, 4, 2, 2, 0, 2> _z##_z##_x##_z; \
	const swizzle<T, N, 4, 2, 2, 1, 0> _z##_z##_y##_x; \
	const swizzle<T, N, 4, 2, 2, 1, 1> _z##_z##_y##_y; \
	const swizzle<T, N, 4, 2, 2, 1, 2> _z##_z##_y##_z; \
	const swizzle<T, N, 4, 2, 2, 2, 0> _z##_z##_z##_x; \
	const swizzle<T, N, 4, 2, 2, 2, 1> _z##_z##_z##_y; \
	const swizzle<T, N, 4, 2, 2, 2, 2> _z##_z##_z##_z

template <typename T>
class vector_storage<T, 3> {
protected:
	static const std::size_t N = 3;

public:
	union {
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		swizzle<T, N, 1, 1> y;
		swizzle<T, N, 1, 1> g;
		swizzle<T, N, 1, 1> t;
		swizzle<T, N, 1, 2> z;
		swizzle<T, N, 1, 2> b;
		swizzle<T, N, 1, 2> p;

		BF_SWIZZLES_X(x);
		BF_SWIZZLES_XY(x, y);
		BF_SWIZZLES_XYZ(x, y, z);

		BF_SWIZZLES_X(r);
		BF_SWIZZLES_XY(r, g);
		BF_SWIZZLES_XYZ(r, g, b);

		BF_SWIZZLES_X(s);
		BF_SWIZZLES_XY(s, t);
		BF_SWIZZLES_XYZ(s, t, p);
	};

	vector_storage() {
	}

	T& operator [] (std::size_t i) {
		return reinterpret_cast<T*>(this)[i];
	}

	const T& operator [] (std::size_t i) const {
		return reinterpret_cast<const T*>(this)[i];
	}

	vector_storage& operator = (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = operand;

		return *this;
	}

	vector_storage& operator = (T&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand);

		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];

		for (auto i = 0; i < N; ++i)
			(*this)[i] = temp[i];
		
		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (vector_usage<T2, N, S2>&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand[i]);

		return *this;
	}
};

#define BF_SWIZZLES_XYZW(_x, _y, _z, _w) \
	swizzle<T, N, 2, 0, 3> _x##_w; \
	swizzle<T, N, 2, 1, 3> _y##_w; \
	swizzle<T, N, 2, 2, 3> _z##_w; \
	swizzle<T, N, 2, 3, 0> _w##_x; \
	swizzle<T, N, 2, 3, 1> _w##_y; \
	swizzle<T, N, 2, 3, 2> _w##_z; \
	const swizzle<T, N, 2, 3, 3> _w##_w; \
	const swizzle<T, N, 3, 0, 0, 3> _x##_x##_w; \
	swizzle<T, N, 3, 0, 1, 3> _x##_y##_w; \
	swizzle<T, N, 3, 0, 2, 3> _x##_z##_w; \
	const swizzle<T, N, 3, 0, 3, 0> _x##_w##_x; \
	swizzle<T, N, 3, 0, 3, 1> _x##_w##_y; \
	swizzle<T, N, 3, 0, 3, 2> _x##_w##_z; \
	const swizzle<T, N, 3, 0, 3, 3> _x##_w##_w; \
	swizzle<T, N, 3, 1, 0, 3> _y##_x##_w; \
	const swizzle<T, N, 3, 1, 1, 3> _y##_y##_w; \
	swizzle<T, N, 3, 1, 2, 3> _y##_z##_w; \
	swizzle<T, N, 3, 1, 3, 0> _y##_w##_x; \
	const swizzle<T, N, 3, 1, 3, 1> _y##_w##_y; \
	swizzle<T, N, 3, 1, 3, 2> _y##_w##_z; \
	const swizzle<T, N, 3, 1, 3, 3> _y##_w##_w; \
	swizzle<T, N, 3, 2, 0, 3> _z##_x##_w; \
	swizzle<T, N, 3, 2, 1, 3> _z##_y##_w; \
	const swizzle<T, N, 3, 2, 2, 3> _z##_z##_w; \
	swizzle<T, N, 3, 2, 3, 0> _z##_w##_x; \
	swizzle<T, N, 3, 2, 3, 1> _z##_w##_y; \
	const swizzle<T, N, 3, 2, 3, 2> _z##_w##_z; \
	const swizzle<T, N, 3, 2, 3, 3> _z##_w##_w; \
	const swizzle<T, N, 3, 3, 0, 0> _w##_x##_x; \
	swizzle<T, N, 3, 3, 0, 1> _w##_x##_y; \
	swizzle<T, N, 3, 3, 0, 2> _w##_x##_z; \
	const swizzle<T, N, 3, 3, 0, 3> _w##_x##_w; \
	swizzle<T, N, 3, 3, 1, 0> _w##_y##_x; \
	const swizzle<T, N, 3, 3, 1, 1> _w##_y##_y; \
	swizzle<T, N, 3, 3, 1, 2> _w##_y##_z; \
	const swizzle<T, N, 3, 3, 1, 3> _w##_y##_w; \
	swizzle<T, N, 3, 3, 2, 0> _w##_z##_x; \
	swizzle<T, N, 3, 3, 2, 1> _w##_z##_y; \
	const swizzle<T, N, 3, 3, 2, 2> _w##_z##_z; \
	const swizzle<T, N, 3, 3, 2, 3> _w##_z##_w; \
	const swizzle<T, N, 3, 3, 3, 0> _w##_w##_x; \
	const swizzle<T, N, 3, 3, 3, 1> _w##_w##_y; \
	const swizzle<T, N, 3, 3, 3, 2> _w##_w##_z; \
	const swizzle<T, N, 3, 3, 3, 3> _w##_w##_w; \
	const swizzle<T, N, 4, 0, 0, 0, 3> _x##_x##_x##_w; \
	const swizzle<T, N, 4, 0, 0, 1, 3> _x##_x##_y##_w; \
	const swizzle<T, N, 4, 0, 0, 2, 3> _x##_x##_z##_w; \
	const swizzle<T, N, 4, 0, 0, 3, 0> _x##_x##_w##_x; \
	const swizzle<T, N, 4, 0, 0, 3, 1> _x##_x##_w##_y; \
	const swizzle<T, N, 4, 0, 0, 3, 2> _x##_x##_w##_z; \
	const swizzle<T, N, 4, 0, 0, 3, 3> _x##_x##_w##_w; \
	const swizzle<T, N, 4, 0, 1, 0, 3> _x##_y##_x##_w; \
	const swizzle<T, N, 4, 0, 1, 1, 3> _x##_y##_y##_w; \
	swizzle<T, N, 4, 0, 1, 2, 3> _x##_y##_z##_w; \
	const swizzle<T, N, 4, 0, 1, 3, 0> _x##_y##_w##_x; \
	const swizzle<T, N, 4, 0, 1, 3, 1> _x##_y##_w##_y; \
	swizzle<T, N, 4, 0, 1, 3, 2> _x##_y##_w##_z; \
	const swizzle<T, N, 4, 0, 1, 3, 3> _x##_y##_w##_w; \
	const swizzle<T, N, 4, 0, 2, 0, 3> _x##_z##_x##_w; \
	swizzle<T, N, 4, 0, 2, 1, 3> _x##_z##_y##_w; \
	const swizzle<T, N, 4, 0, 2, 2, 3> _x##_z##_z##_w; \
	const swizzle<T, N, 4, 0, 2, 3, 0> _x##_z##_w##_x; \
	swizzle<T, N, 4, 0, 2, 3, 1> _x##_z##_w##_y; \
	const swizzle<T, N, 4, 0, 2, 3, 2> _x##_z##_w##_z; \
	const swizzle<T, N, 4, 0, 2, 3, 3> _x##_z##_w##_w; \
	const swizzle<T, N, 4, 0, 3, 0, 0> _x##_w##_x##_x; \
	const swizzle<T, N, 4, 0, 3, 0, 1> _x##_w##_x##_y; \
	const swizzle<T, N, 4, 0, 3, 0, 2> _x##_w##_x##_z; \
	const swizzle<T, N, 4, 0, 3, 0, 3> _x##_w##_x##_w; \
	const swizzle<T, N, 4, 0, 3, 1, 0> _x##_w##_y##_x; \
	const swizzle<T, N, 4, 0, 3, 1, 1> _x##_w##_y##_y; \
	swizzle<T, N, 4, 0, 3, 1, 2> _x##_w##_y##_z; \
	const swizzle<T, N, 4, 0, 3, 1, 3> _x##_w##_y##_w; \
	const swizzle<T, N, 4, 0, 3, 2, 0> _x##_w##_z##_x; \
	swizzle<T, N, 4, 0, 3, 2, 1> _x##_w##_z##_y; \
	const swizzle<T, N, 4, 0, 3, 2, 2> _x##_w##_z##_z; \
	const swizzle<T, N, 4, 0, 3, 2, 3> _x##_w##_z##_w; \
	const swizzle<T, N, 4, 0, 3, 3, 0> _x##_w##_w##_x; \
	const swizzle<T, N, 4, 0 ,3, 3, 1> _x##_w##_w##_y; \
	const swizzle<T, N, 4, 0, 3, 3, 2> _x##_w##_w##_z; \
	const swizzle<T, N, 4, 0, 3, 3, 3> _x##_w##_w##_w; \
	const swizzle<T, N, 4, 1, 0, 0, 3> _y##_x##_x##_w; \
	const swizzle<T, N, 4, 1, 0, 1, 3> _y##_x##_y##_w; \
	swizzle<T, N, 4, 1, 0, 2, 3> _y##_x##_z##_w; \
	const swizzle<T, N, 4, 1, 0, 3, 0> _y##_x##_w##_x; \
	const swizzle<T, N, 4, 1, 0, 3, 1> _y##_x##_w##_y; \
	swizzle<T, N, 4, 1, 0, 3, 2> _y##_x##_w##_z; \
	const swizzle<T, N, 4, 1, 0, 3, 3> _y##_x##_w##_w; \
	const swizzle<T, N, 4, 1, 1, 0, 3> _y##_y##_x##_w; \
	const swizzle<T, N, 4, 1, 1, 1, 3> _y##_y##_y##_w; \
	const swizzle<T, N, 4, 1, 1, 2, 3> _y##_y##_z##_w; \
	const swizzle<T, N, 4, 1, 1, 3, 0> _y##_y##_w##_x; \
	const swizzle<T, N, 4, 1, 1, 3, 1> _y##_y##_w##_y; \
	const swizzle<T, N, 4, 1, 1, 3, 2> _y##_y##_w##_z; \
	const swizzle<T, N, 4, 1, 1, 3, 3> _y##_y##_w##_w; \
	swizzle<T, N, 4, 1, 2, 0, 3> _y##_z##_x##_w; \
	const swizzle<T, N, 4, 1, 2, 1, 3> _y##_z##_y##_w; \
	const swizzle<T, N, 4, 1, 2, 2, 3> _y##_z##_z##_w; \
	swizzle<T, N, 4, 1, 2, 3, 0> _y##_z##_w##_x; \
	const swizzle<T, N, 4, 1, 2, 3, 1> _y##_z##_w##_y; \
	const swizzle<T, N, 4, 1, 2, 3, 2> _y##_z##_w##_z; \
	const swizzle<T, N, 4, 1, 2, 3, 3> _y##_z##_w##_w; \
	const swizzle<T, N, 4, 1, 3, 0, 0> _y##_w##_x##_x; \
	const swizzle<T, N, 4, 1, 3, 0, 1> _y##_w##_x##_y; \
	swizzle<T, N, 4, 1, 3, 0, 2> _y##_w##_x##_z; \
	const swizzle<T, N, 4, 1, 3, 0, 3> _y##_w##_x##_w; \
	const swizzle<T, N, 4, 1, 3, 1, 0> _y##_w##_y##_x; \
	const swizzle<T, N, 4, 1, 3, 1, 1> _y##_w##_y##_y; \
	const swizzle<T, N, 4, 1, 3, 1, 2> _y##_w##_y##_z; \
	const swizzle<T, N, 4, 1, 3, 1, 3> _y##_w##_y##_w; \
	swizzle<T, N, 4, 1, 3, 2, 0> _y##_w##_z##_x; \
	const swizzle<T, N, 4, 1, 3, 2, 1> _y##_w##_z##_y; \
	const swizzle<T, N, 4, 1, 3, 2, 2> _y##_w##_z##_z; \
	const swizzle<T, N, 4, 1, 3, 2, 3> _y##_w##_z##_w; \
	const swizzle<T, N, 4, 1, 3, 3, 0> _y##_w##_w##_x; \
	const swizzle<T, N, 4, 1, 3, 3, 1> _y##_w##_w##_y; \
	const swizzle<T, N, 4, 1, 3, 3, 2> _y##_w##_w##_z; \
	const swizzle<T, N, 4, 1, 3, 3, 3> _y##_w##_w##_w; \
	const swizzle<T, N, 4, 2, 0, 0, 3> _z##_x##_x##_w; \
	swizzle<T, N, 4, 2, 0, 1, 3> _z##_x##_y##_w; \
	const swizzle<T, N, 4, 2, 0, 2, 3> _z##_x##_z##_w; \
	const swizzle<T, N, 4, 2, 0, 3, 0> _z##_x##_w##_x; \
	swizzle<T, N, 4, 2, 0, 3, 1> _z##_x##_w##_y; \
	const swizzle<T, N, 4, 2, 0, 3, 2> _z##_x##_w##_z; \
	const swizzle<T, N, 4, 2, 0, 3, 3> _z##_x##_w##_w; \
	swizzle<T, N, 4, 2, 1, 0, 3> _z##_y##_x##_w; \
	const swizzle<T, N, 4, 2, 1, 1, 3> _z##_y##_y##_w; \
	const swizzle<T, N, 4, 2, 1, 2, 3> _z##_y##_z##_w; \
	swizzle<T, N, 4, 2, 1, 3, 0> _z##_y##_w##_x; \
	const swizzle<T, N, 4, 2, 1, 3, 1> _z##_y##_w##_y; \
	const swizzle<T, N, 4, 2, 1, 3, 2> _z##_y##_w##_z; \
	const swizzle<T, N, 4, 2, 1, 3, 3> _z##_y##_w##_w; \
	const swizzle<T, N, 4, 2, 2, 0, 3> _z##_z##_x##_w; \
	const swizzle<T, N, 4, 2, 2, 1, 3> _z##_z##_y##_w; \
	const swizzle<T, N, 4, 2, 2, 2, 3> _z##_z##_z##_w; \
	const swizzle<T, N, 4, 2, 2, 3, 0> _z##_z##_w##_x; \
	const swizzle<T, N, 4, 2, 2, 3, 1> _z##_z##_w##_y; \
	const swizzle<T, N, 4, 2, 2, 3, 2> _z##_z##_w##_z; \
	const swizzle<T, N, 4, 2, 2, 3, 3> _z##_z##_w##_w; \
	const swizzle<T, N, 4, 2, 3, 0, 0> _z##_w##_x##_x; \
	swizzle<T, N, 4, 2, 3, 0, 1> _z##_w##_x##_y; \
	const swizzle<T, N, 4, 2, 3, 0, 2> _z##_w##_x##_z; \
	const swizzle<T, N, 4, 2, 3, 0, 3> _z##_w##_x##_w; \
	swizzle<T, N, 4, 2, 3, 1, 0> _z##_w##_y##_x; \
	const swizzle<T, N, 4, 2, 3, 1, 1> _z##_w##_y##_y; \
	const swizzle<T, N, 4, 2, 3, 1, 2> _z##_w##_y##_z; \
	const swizzle<T, N, 4, 2, 3, 1, 3> _z##_w##_y##_w; \
	const swizzle<T, N, 4, 2, 3, 2, 0> _z##_w##_z##_x; \
	const swizzle<T, N, 4, 2, 3, 2, 1> _z##_w##_z##_y; \
	const swizzle<T, N, 4, 2, 3, 2, 2> _z##_w##_z##_z; \
	const swizzle<T, N, 4, 2, 3, 2, 3> _z##_w##_z##_w; \
	const swizzle<T, N, 4, 2, 3, 3, 0> _z##_w##_w##_x; \
	const swizzle<T, N, 4, 2, 3, 3, 1> _z##_w##_w##_y; \
	const swizzle<T, N, 4, 2, 3, 3, 2> _z##_w##_w##_z; \
	const swizzle<T, N, 4, 2, 3, 3, 3> _z##_w##_w##_w; \
	const swizzle<T, N, 4, 3, 0, 0, 0> _w##_x##_x##_x; \
	const swizzle<T, N, 4, 3, 0, 0, 1> _w##_x##_x##_y; \
	const swizzle<T, N, 4, 3, 0, 0, 2> _w##_x##_x##_z; \
	const swizzle<T, N, 4, 3, 0, 0, 3> _w##_x##_x##_w; \
	const swizzle<T, N, 4, 3, 0, 1, 0> _w##_x##_y##_x; \
	const swizzle<T, N, 4, 3, 0, 1, 1> _w##_x##_y##_y; \
	swizzle<T, N, 4, 3, 0, 1, 2> _w##_x##_y##_z; \
	const swizzle<T, N, 4, 3, 0, 1, 3> _w##_x##_y##_w; \
	const swizzle<T, N, 4, 3, 0, 2, 0> _w##_x##_z##_x; \
	swizzle<T, N, 4, 3, 0, 2, 1> _w##_x##_z##_y; \
	const swizzle<T, N, 4, 3, 0, 2, 2> _w##_x##_z##_z; \
	const swizzle<T, N, 4, 3, 0, 2, 3> _w##_x##_z##_w; \
	const swizzle<T, N, 4, 3, 0, 3, 0> _w##_x##_w##_x; \
	const swizzle<T, N, 4, 3, 0, 3, 1> _w##_x##_w##_y; \
	const swizzle<T, N, 4, 3, 0, 3, 2> _w##_x##_w##_z; \
	const swizzle<T, N, 4, 3, 0, 3, 3> _w##_x##_w##_w; \
	const swizzle<T, N, 4, 3, 1, 0, 0> _w##_y##_x##_x; \
	const swizzle<T, N, 4, 3, 1, 0, 1> _w##_y##_x##_y; \
	swizzle<T, N, 4, 3, 1, 0, 2> _w##_y##_x##_z; \
	const swizzle<T, N, 4, 3, 1, 0, 3> _w##_y##_x##_w; \
	const swizzle<T, N, 4, 3, 1, 1, 0> _w##_y##_y##_x; \
	const swizzle<T, N, 4, 3, 1, 1, 1> _w##_y##_y##_y; \
	const swizzle<T, N, 4, 3, 1, 1, 2> _w##_y##_y##_z; \
	const swizzle<T, N, 4, 3, 1, 1, 3> _w##_y##_y##_w; \
	swizzle<T, N, 4, 3, 1, 2, 0> _w##_y##_z##_x; \
	const swizzle<T, N, 4, 3, 1, 2, 1> _w##_y##_z##_y; \
	const swizzle<T, N, 4, 3, 1, 2, 2> _w##_y##_z##_z; \
	const swizzle<T, N, 4, 3, 1, 2, 3> _w##_y##_z##_w; \
	const swizzle<T, N, 4, 3, 1, 3, 0> _w##_y##_w##_x; \
	const swizzle<T, N, 4, 3, 1, 3, 1> _w##_y##_w##_y; \
	const swizzle<T, N, 4, 3, 1, 3, 2> _w##_y##_w##_z; \
	const swizzle<T, N, 4, 3, 1, 3, 3> _w##_y##_w##_w; \
	const swizzle<T, N, 4, 3, 2, 0, 0> _w##_z##_x##_x; \
	swizzle<T, N, 4, 3, 2, 0, 1> _w##_z##_x##_y; \
	const swizzle<T, N, 4, 3, 2, 0, 2> _w##_z##_x##_z; \
	const swizzle<T, N, 4, 3, 2, 0, 3> _w##_z##_x##_w; \
	swizzle<T, N, 4, 3, 2, 1, 0> _w##_z##_y##_x; \
	const swizzle<T, N, 4, 3, 2, 1, 1> _w##_z##_y##_y; \
	const swizzle<T, N, 4, 3, 2, 1, 2> _w##_z##_y##_z; \
	const swizzle<T, N, 4, 3, 2, 1, 3> _w##_z##_y##_w; \
	const swizzle<T, N, 4, 3, 2, 2, 0> _w##_z##_z##_x; \
	const swizzle<T, N, 4, 3, 2, 2, 1> _w##_z##_z##_y; \
	const swizzle<T, N, 4, 3, 2, 2, 2> _w##_z##_z##_z; \
	const swizzle<T, N, 4, 3, 2, 2, 3> _w##_z##_z##_w; \
	const swizzle<T, N, 4, 3, 2, 3, 0> _w##_z##_w##_x; \
	const swizzle<T, N, 4, 3, 2, 3, 1> _w##_z##_w##_y; \
	const swizzle<T, N, 4, 3, 2, 3, 2> _w##_z##_w##_z; \
	const swizzle<T, N, 4, 3, 2, 3, 3> _w##_z##_w##_w; \
	const swizzle<T, N, 4, 3, 3, 0, 0> _w##_w##_x##_x; \
	const swizzle<T, N, 4, 3, 3, 0, 1> _w##_w##_x##_y; \
	const swizzle<T, N, 4, 3, 3, 0, 2> _w##_w##_x##_z; \
	const swizzle<T, N, 4, 3, 3, 0, 3> _w##_w##_x##_w; \
	const swizzle<T, N, 4, 3, 3, 1, 0> _w##_w##_y##_x; \
	const swizzle<T, N, 4, 3, 3, 1, 1> _w##_w##_y##_y; \
	const swizzle<T, N, 4, 3, 3, 1, 2> _w##_w##_y##_z; \
	const swizzle<T, N, 4, 3, 3, 1, 3> _w##_w##_y##_w; \
	const swizzle<T, N, 4, 3, 3, 2, 0> _w##_w##_z##_x; \
	const swizzle<T, N, 4, 3, 3, 2, 1> _w##_w##_z##_y; \
	const swizzle<T, N, 4, 3, 3, 2, 2> _w##_w##_z##_z; \
	const swizzle<T, N, 4, 3, 3, 2, 3> _w##_w##_z##_w; \
	const swizzle<T, N, 4, 3, 3, 3, 0> _w##_w##_w##_x; \
	const swizzle<T, N, 4, 3, 3, 3, 1> _w##_w##_w##_y; \
	const swizzle<T, N, 4, 3, 3, 3, 2> _w##_w##_w##_z; \
	const swizzle<T, N, 4, 3, 3, 3, 3> _w##_w##_w##_w

template <typename T>
class vector_storage<T, 4> {
protected:
	static const std::size_t N = 4;

public:
	union {
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		swizzle<T, N, 1, 1> y;
		swizzle<T, N, 1, 1> g;
		swizzle<T, N, 1, 1> t;
		swizzle<T, N, 1, 2> z;
		swizzle<T, N, 1, 2> b;
		swizzle<T, N, 1, 2> p;
		swizzle<T, N, 1, 3> w;
		swizzle<T, N, 1, 3> a;
		swizzle<T, N, 1, 3> q;

		BF_SWIZZLES_X(x);
		BF_SWIZZLES_XY(x, y);
		BF_SWIZZLES_XYZ(x, y, z);
		BF_SWIZZLES_XYZW(x, y, z, w);

		BF_SWIZZLES_X(r);
		BF_SWIZZLES_XY(r, g);
		BF_SWIZZLES_XYZ(r, g, b);
		BF_SWIZZLES_XYZW(r, g, b, a);

		BF_SWIZZLES_X(s);
		BF_SWIZZLES_XY(s, t);
		BF_SWIZZLES_XYZ(s, t, p);
		BF_SWIZZLES_XYZW(s, t, p, q);
	};

	vector_storage() {
	}

	T& operator [] (std::size_t i) {
		return reinterpret_cast<T*>(this)[i];
	}

	const T& operator [] (std::size_t i) const {
		return reinterpret_cast<const T*>(this)[i];
	}

	vector_storage& operator = (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = operand;

		return *this;
	}

	vector_storage& operator = (T&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand);

		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];

		for (auto i = 0; i < N; ++i)
			(*this)[i] = temp[i];
		
		return *this;
	}

	template <typename T2, typename S2>
	vector_storage& operator = (vector_usage<T2, N, S2>&& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(operand[i]);

		return *this;
	}
};

template <typename T, std::size_t N>
class vector_plural : public vector_plural_usage<T, N, vector_storage<T, N>> {
public:
	vector_plural() = default;
	~vector_plural() = default;

	vector_plural(const T& sca) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = sca;
	}

	template <typename S2>
	vector_plural(const vector_plural_usage<T, N, S2>& vec) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = vec[i];
	}

	template <typename S2>
	vector_plural(vector_plural_usage<T, N, S2>&& vec) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = std::move(vec[i]);
	}

	template <typename T2, typename S2>
	vector_plural(const vector_plural_usage<T2, N, S2>& vec) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = T(vec[i]);
	}

	template <typename S2>
	vector_plural(const vector_plural_usage<T, 1, S2>& vec) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = vec[0];
	}

	template <typename T2, typename S2>
	vector_plural(const vector_plural_usage<T2, 1, S2>& vec) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] = T(vec[0]);
	}
};

template <typename T>
class vector<T, 1> : public vector_usage<T, 1, vector_storage<T, 1>>{
private:
	static const std::size_t N = 1;

public:
	vector() = default;

	vector(const T& sca) {
		(*this)[0] = sca;
	}

	vector(T&& sca) {
		(*this)[0] = std::move(sca);
	}

	template <typename S2>
	vector(const vector_usage<T, N, S2>& vec) {
		(*this)[0] = vec[0];
	}

	template <typename S2>
	vector(vector_usage<T, N, S2>&& vec) {
		(*this)[0] = std::move(vec[0]);
	}

	template <typename T2, typename S2>
	explicit vector(const vector_usage<T2, N, S2>& vec) {
		(*this)[0] = T(vec[0]);
	}

	vector& operator = (const T& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	vector& operator = (T&& operand) {
		vector_storage<T, N>::operator=(std::forward<T>(operand));
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (const vector_usage<T2, N, S2>& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (vector_usage<T2, N, S2>&& operand) {
		vector_storage<T, N>::operator=(std::forward<vector_usage<T2, N, S2>>(operand));
		return *this;
	}

	operator T() const {
		return (*this)[0];
	}
};

template <typename T>
class vector<T, 2> : public vector_plural<T, 2>{
private:
	static const std::size_t N = 2;

public:
	vector() = default;
	~vector() = default;

	template <typename TA, typename TB>
	vector(const TA& a, const TB& b) {
		(*this)[0] = T(a);
		(*this)[1] = T(b);
	}

	vector(const T& sca) : vector_plural<T, N>(sca) {
	}

	template <typename S2>
	vector(const vector_usage<T, 1, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename S2>
	vector(const vector_usage<T, N, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename S2>
	vector(vector_usage<T, N, S2>&& vec) : vector_plural<T, N>(std::forward<vector_usage<T, N, S2>>(vec)) {
	}

	template <typename T2, typename S2>
	vector(const vector_usage<T2, 1, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename T2, typename S2>
	vector(const vector_usage<T2, N, S2>& vec) : vector_plural<T, N>(vec) {
	}

	vector& operator = (const T& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	vector& operator = (T&& operand) {
		vector_storage<T, N>::operator=(std::forward<T>(operand));
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (const vector_usage<T2, N, S2>& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (vector_usage<T2, N, S2>&& operand) {
		vector_storage<T, N>::operator=(std::forward<vector_usage<T2, N, S2>>(operand));
		return *this;
	}

	vector& operator = (const vector& operand) {
		(*this)[0] = operand[0];
		(*this)[1] = operand[1];
		return *this;
	}

	vector& operator = (vector&& operand) {
		(*this)[0] = std::move(operand[0]);
		(*this)[1] = std::move(operand[1]);
		return *this;
	}
};

template <typename T>
class vector<T, 3> : public vector_plural<T, 3>{
private:
	static const std::size_t N = 3;

public:
	vector() = default;
	~vector() = default;

	template <typename TA, typename TB, typename TC>
	vector(const TA& a, const TB& b, const TC& c) {
		(*this)[0] = T(a);
		(*this)[1] = T(b);
		(*this)[2] = T(c);
	}

	template <typename TA, typename SA, typename TB>
	vector(const vector_usage<TA, 2, SA> a, const TB& b) {
		(*this)[0] = T(a[0]);
		(*this)[1] = T(a[1]);
		(*this)[2] = T(b);
	}

	template <typename TA, typename TB, typename SB>
	vector(const TA& a, const vector_usage<TB, 2, SB>& b) {
		(*this)[0] = T(a);
		(*this)[1] = T(b[0]);
		(*this)[2] = T(b[1]);
	}

	vector(const T& sca) : vector_plural<T, N>(sca) {
	}

	template <typename S2>
	vector(const vector_usage<T, 1, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename S2>
	vector(const vector_usage<T, N, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename S2>
	vector(vector_usage<T, N, S2>&& vec) : vector_plural<T, N>(std::forward<vector_usage<T, N, S2>>(vec)) {
	}

	template <typename T2, typename S2>
	vector(const vector_usage<T2, 1, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename T2, typename S2>
	vector(const vector_usage<T2, N, S2>& vec) : vector_plural<T, N>(vec) {
	}

	vector& operator = (const T& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	vector& operator = (T&& operand) {
		vector_storage<T, N>::operator=(std::forward<T>(operand));
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (const vector_usage<T2, N, S2>& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (vector_usage<T2, N, S2>&& operand) {
		vector_storage<T, N>::operator=(std::forward<vector_usage<T2, N, S2>>(operand));
		return *this;
	}

	vector& operator = (const vector& operand) {
		(*this)[0] = operand[0];
		(*this)[1] = operand[1];
		(*this)[2] = operand[2];
		return *this;
	}

	vector& operator = (vector&& operand) {
		(*this)[0] = std::move(operand[0]);
		(*this)[1] = std::move(operand[1]);
		(*this)[2] = std::move(operand[2]);
		return *this;
	}
};

template <typename T>
class vector<T, 4> : public vector_plural<T, 4>{
private:
	static const std::size_t N = 4;

public:
	vector() = default;
	~vector() = default;

	template <typename TA, typename TB, typename TC, typename TD>
	vector(const TA& a, const TB& b, const TC& c, const TD& d) {
		(*this)[0] = T(a);
		(*this)[1] = T(b);
		(*this)[2] = T(c);
		(*this)[3] = T(d);
	}

	template <typename TA, typename SA, typename TB, typename TC>
	vector(const vector_usage<TA, 2, SA> a, const TB& b, const TC& c) {
		(*this)[0] = T(a[0]);
		(*this)[1] = T(a[1]);
		(*this)[2] = T(b);
		(*this)[3] = T(c);
	}

	template <typename TA, typename TB, typename SB, typename TC>
	vector(const TA& a, const vector_usage<TB, 2, SB>& b, const TC& c) {
		(*this)[0] = T(a);
		(*this)[1] = T(b[0]);
		(*this)[2] = T(b[1]);
		(*this)[3] = T(c);
	}

	template <typename TA, typename TB, typename TC, typename SC>
	vector(const TA& a, const TB& b, const vector_usage<TC, 2, SC>& c) {
		(*this)[0] = T(a);
		(*this)[1] = T(b);
		(*this)[2] = T(c[0]);
		(*this)[3] = T(c[1]);
	}

	template <typename TA, typename SA, typename TB>
	vector(const vector_usage<TA, 3, SA>& a, const TB& b) {
		(*this)[0] = T(a[0]);
		(*this)[1] = T(a[1]);
		(*this)[2] = T(a[2]);
		(*this)[3] = T(b);
	}

	template <typename TA, typename TB, typename SB>
	vector(const TA& a, const vector_usage<TB, 3, SB>& b) {
		(*this)[0] = T(a);
		(*this)[1] = T(b[0]);
		(*this)[2] = T(b[1]);
		(*this)[3] = T(b[2]);
	}

	vector(const T& sca) : vector_plural<T, N>(sca) {
	}

	template <typename S2>
	vector(const vector_usage<T, 1, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename S2>
	vector(const vector_usage<T, N, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename S2>
	vector(vector_usage<T, N, S2>&& vec) : vector_plural<T, N>(std::forward<vector_usage<T, N, S2>>(vec)) {
	}

	template <typename T2, typename S2>
	vector(const vector_usage<T2, 1, S2>& vec) : vector_plural<T, N>(vec) {
	}

	template <typename T2, typename S2>
	vector(const vector_usage<T2, N, S2>& vec) : vector_plural<T, N>(vec) {
	}

	vector& operator = (const T& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	vector& operator = (T&& operand) {
		vector_storage<T, N>::operator=(std::forward<T>(operand));
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (const vector_usage<T2, N, S2>& operand) {
		vector_storage<T, N>::operator=(operand);
		return *this;
	}

	template <typename T2, typename S2>
	vector& operator = (vector_usage<T2, N, S2>&& operand) {
		vector_storage<T, N>::operator=(std::forward<vector_usage<T2, N, S2>>(operand));
		return *this;
	}

	vector& operator = (const vector& operand) {
		(*this)[0] = operand[0];
		(*this)[1] = operand[1];
		(*this)[2] = operand[2];
		(*this)[3] = operand[3];
		return *this;
	}

	vector& operator = (vector&& operand) {
		(*this)[0] = std::move(operand[0]);
		(*this)[1] = std::move(operand[1]);
		(*this)[2] = std::move(operand[2]);
		(*this)[3] = std::move(operand[3]);
		return *this;
	}
};
}
}