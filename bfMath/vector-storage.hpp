#pragma once
#include "swizzle.hpp"

#include <exception>

namespace bf {
namespace math {
template <typename T, std::size_t N>
class vector_storage;

#define BF_SWIZZLES_X(_x) \
	const swizzle<T, N, 2, 0x0000> _x##_x; \
	const swizzle<T, N, 3, 0x000000> _x##_x##_x; \
	const swizzle<T, N, 4, 0x00000000> _x##_x##_x##_x

/*
#define BF_SWIZZLES_X(_x) \
	const swizzle<T, N, 2, 0, 0> _x##_x; \
	const swizzle<T, N, 3, 0, 0, 0> _x##_x##_x; \
	const swizzle<T, N, 4, 0, 0, 0, 0> _x##_x##_x##_x
*/

template <typename T>
class vector_storage<T, 1> {
protected:
	static const std::size_t N = 1;

public:
	union {
		swizzle<T, N, 1, 0x00> x;
		swizzle<T, N, 1, 0x00> r;
		swizzle<T, N, 1, 0x00> s;

		/*
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		*/

#ifdef BF_XYZW
		BF_SWIZZLES_X(x);
#endif

#ifdef BF_RGBA
		BF_SWIZZLES_X(r);
#endif

#ifdef BF_STPQ
		BF_SWIZZLES_X(s);
#endif
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
	swizzle<T, N, 2, 0x0100> _x##_y; \
	swizzle<T, N, 2, 0x0001> _y##_x; \
	const swizzle<T, N, 2, 0x0101> _y##_y; \
	const swizzle<T, N, 3, 0x010000> _x##_x##_y; \
	const swizzle<T, N, 3, 0x000100> _x##_y##_x; \
	const swizzle<T, N, 3, 0x010100> _x##_y##_y; \
	const swizzle<T, N, 3, 0x000001> _y##_x##_x; \
	const swizzle<T, N, 3, 0x010001> _y##_x##_y; \
	const swizzle<T, N, 3, 0x000101> _y##_y##_x; \
	const swizzle<T, N, 3, 0x010101> _y##_y##_y; \
	const swizzle<T, N, 4, 0x01000000> _x##_x##_x##_y; \
	const swizzle<T, N, 4, 0x00010000> _x##_x##_y##_x; \
	const swizzle<T, N, 4, 0x01010000> _x##_x##_y##_y; \
	const swizzle<T, N, 4, 0x00000100> _x##_y##_x##_x; \
	const swizzle<T, N, 4, 0x01000100> _x##_y##_x##_y; \
	const swizzle<T, N, 4, 0x00010100> _x##_y##_y##_x; \
	const swizzle<T, N, 4, 0x01010100> _x##_y##_y##_y; \
	const swizzle<T, N, 4, 0x00000001> _y##_x##_x##_x; \
	const swizzle<T, N, 4, 0x01000001> _y##_x##_x##_y; \
	const swizzle<T, N, 4, 0x00010001> _y##_x##_y##_x; \
	const swizzle<T, N, 4, 0x01010001> _y##_x##_y##_y; \
	const swizzle<T, N, 4, 0x00000101> _y##_y##_x##_x; \
	const swizzle<T, N, 4, 0x01000101> _y##_y##_x##_y; \
	const swizzle<T, N, 4, 0x00010101> _y##_y##_y##_x; \
	const swizzle<T, N, 4, 0x01010101> _y##_y##_y##_y

/*
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
*/

template <typename T>
class vector_storage<T, 2> {
protected:
	static const std::size_t N = 2;

public:
	union {
		swizzle<T, N, 1, 0x00> x;
		swizzle<T, N, 1, 0x00> r;
		swizzle<T, N, 1, 0x00> s;
		swizzle<T, N, 1, 0x01> y;
		swizzle<T, N, 1, 0x01> g;
		swizzle<T, N, 1, 0x01> t;

		/*
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		swizzle<T, N, 1, 1> y;
		swizzle<T, N, 1, 1> g;
		swizzle<T, N, 1, 1> t;
		*/

#ifdef BF_XYZW
		BF_SWIZZLES_X(x);
		BF_SWIZZLES_XY(x, y);
#endif

#ifdef BF_RGBA
		BF_SWIZZLES_X(r);
		BF_SWIZZLES_XY(r, g);
#endif

#ifdef BF_STPQ
		BF_SWIZZLES_X(s);
		BF_SWIZZLES_XY(s, t);
#endif
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
	swizzle<T, N, 2, 0x0200> _x##_z; \
	swizzle<T, N, 2, 0x0201> _y##_z; \
	swizzle<T, N, 2, 0x0002> _z##_x; \
	swizzle<T, N, 2, 0x0102> _z##_y; \
	const swizzle<T, N, 2, 0x0202> _z##_z; \
	const swizzle<T, N, 3, 0x020000> _x##_x##_z; \
	swizzle<T, N, 3, 0x020100> _x##_y##_z; \
	const swizzle<T, N, 3, 0x000200> _x##_z##_x; \
	swizzle<T, N, 3, 0x010200> _x##_z##_y; \
	const swizzle<T, N, 3, 0x020200> _x##_z##_z; \
	swizzle<T, N, 3, 0x020001> _y##_x##_z; \
	const swizzle<T, N, 3, 0x020101> _y##_y##_z; \
	swizzle<T, N, 3, 0x000201> _y##_z##_x; \
	const swizzle<T, N, 3, 0x010201> _y##_z##_y; \
	const swizzle<T, N, 3, 0x020201> _y##_z##_z; \
	const swizzle<T, N, 3, 0x000002> _z##_x##_x; \
	swizzle<T, N, 3, 0x010002> _z##_x##_y; \
	const swizzle<T, N, 3, 0x020002> _z##_x##_z; \
	swizzle<T, N, 3, 0x000102> _z##_y##_x; \
	const swizzle<T, N, 3, 0x010102> _z##_y##_y; \
	const swizzle<T, N, 3, 0x020102> _z##_y##_z; \
	const swizzle<T, N, 3, 0x000202> _z##_z##_x; \
	const swizzle<T, N, 3, 0x010202> _z##_z##_y; \
	const swizzle<T, N, 3, 0x020202> _z##_z##_z; \
	const swizzle<T, N, 4, 0x02000000> _x##_x##_x##_z; \
	const swizzle<T, N, 4, 0x02010000> _x##_x##_y##_z; \
	const swizzle<T, N, 4, 0x00020000> _x##_x##_z##_x; \
	const swizzle<T, N, 4, 0x01020000> _x##_x##_z##_y; \
	const swizzle<T, N, 4, 0x02020000> _x##_x##_z##_z; \
	const swizzle<T, N, 4, 0x02000100> _x##_y##_x##_z; \
	const swizzle<T, N, 4, 0x02010100> _x##_y##_y##_z; \
	const swizzle<T, N, 4, 0x00020100> _x##_y##_z##_x; \
	const swizzle<T, N, 4, 0x01020100> _x##_y##_z##_y; \
	const swizzle<T, N, 4, 0x02020100> _x##_y##_z##_z; \
	const swizzle<T, N, 4, 0x00000200> _x##_z##_x##_x; \
	const swizzle<T, N, 4, 0x01000200> _x##_z##_x##_y; \
	const swizzle<T, N, 4, 0x02000200> _x##_z##_x##_z; \
	const swizzle<T, N, 4, 0x00010200> _x##_z##_y##_x; \
	const swizzle<T, N, 4, 0x01010200> _x##_z##_y##_y; \
	const swizzle<T, N, 4, 0x02010200> _x##_z##_y##_z; \
	const swizzle<T, N, 4, 0x00020200> _x##_z##_z##_x; \
	const swizzle<T, N, 4, 0x01020200> _x##_z##_z##_y; \
	const swizzle<T, N, 4, 0x02020200> _x##_z##_z##_z; \
	const swizzle<T, N, 4, 0x02000001> _y##_x##_x##_z; \
	const swizzle<T, N, 4, 0x02010001> _y##_x##_y##_z; \
	const swizzle<T, N, 4, 0x00020001> _y##_x##_z##_x; \
	const swizzle<T, N, 4, 0x01020001> _y##_x##_z##_y; \
	const swizzle<T, N, 4, 0x02020001> _y##_x##_z##_z; \
	const swizzle<T, N, 4, 0x02000101> _y##_y##_x##_z; \
	const swizzle<T, N, 4, 0x02010101> _y##_y##_y##_z; \
	const swizzle<T, N, 4, 0x00020101> _y##_y##_z##_x; \
	const swizzle<T, N, 4, 0x01020101> _y##_y##_z##_y; \
	const swizzle<T, N, 4, 0x02020101> _y##_y##_z##_z; \
	const swizzle<T, N, 4, 0x00000201> _y##_z##_x##_x; \
	const swizzle<T, N, 4, 0x01000201> _y##_z##_x##_y; \
	const swizzle<T, N, 4, 0x02000201> _y##_z##_x##_z; \
	const swizzle<T, N, 4, 0x00010201> _y##_z##_y##_x; \
	const swizzle<T, N, 4, 0x01010201> _y##_z##_y##_y; \
	const swizzle<T, N, 4, 0x02010201> _y##_z##_y##_z; \
	const swizzle<T, N, 4, 0x00020201> _y##_z##_z##_x; \
	const swizzle<T, N, 4, 0x01020201> _y##_z##_z##_y; \
	const swizzle<T, N, 4, 0x02020201> _y##_z##_z##_z; \
	const swizzle<T, N, 4, 0x00000002> _z##_x##_x##_x; \
	const swizzle<T, N, 4, 0x01000002> _z##_x##_x##_y; \
	const swizzle<T, N, 4, 0x02000002> _z##_x##_x##_z; \
	const swizzle<T, N, 4, 0x00010002> _z##_x##_y##_x; \
	const swizzle<T, N, 4, 0x01010002> _z##_x##_y##_y; \
	const swizzle<T, N, 4, 0x02010002> _z##_x##_y##_z; \
	const swizzle<T, N, 4, 0x00020002> _z##_x##_z##_x; \
	const swizzle<T, N, 4, 0x01020002> _z##_x##_z##_y; \
	const swizzle<T, N, 4, 0x02020002> _z##_x##_z##_z; \
	const swizzle<T, N, 4, 0x00000102> _z##_y##_x##_x; \
	const swizzle<T, N, 4, 0x01000102> _z##_y##_x##_y; \
	const swizzle<T, N, 4, 0x02000102> _z##_y##_x##_z; \
	const swizzle<T, N, 4, 0x00010102> _z##_y##_y##_x; \
	const swizzle<T, N, 4, 0x01010102> _z##_y##_y##_y; \
	const swizzle<T, N, 4, 0x02010102> _z##_y##_y##_z; \
	const swizzle<T, N, 4, 0x00020102> _z##_y##_z##_x; \
	const swizzle<T, N, 4, 0x01020102> _z##_y##_z##_y; \
	const swizzle<T, N, 4, 0x02020102> _z##_y##_z##_z; \
	const swizzle<T, N, 4, 0x00000202> _z##_z##_x##_x; \
	const swizzle<T, N, 4, 0x01000202> _z##_z##_x##_y; \
	const swizzle<T, N, 4, 0x02000202> _z##_z##_x##_z; \
	const swizzle<T, N, 4, 0x00010202> _z##_z##_y##_x; \
	const swizzle<T, N, 4, 0x01010202> _z##_z##_y##_y; \
	const swizzle<T, N, 4, 0x02010202> _z##_z##_y##_z; \
	const swizzle<T, N, 4, 0x00020202> _z##_z##_z##_x; \
	const swizzle<T, N, 4, 0x01020202> _z##_z##_z##_y; \
	const swizzle<T, N, 4, 0x02020202> _z##_z##_z##_z

/*
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
*/

template <typename T>
class vector_storage<T, 3> {
protected:
	static const std::size_t N = 3;

public:
	union {
		swizzle<T, N, 1, 0x00> x;
		swizzle<T, N, 1, 0x00> r;
		swizzle<T, N, 1, 0x00> s;
		swizzle<T, N, 1, 0x01> y;
		swizzle<T, N, 1, 0x01> g;
		swizzle<T, N, 1, 0x01> t;
		swizzle<T, N, 1, 0x02> z;
		swizzle<T, N, 1, 0x02> b;
		swizzle<T, N, 1, 0x02> p;

		/*
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		swizzle<T, N, 1, 1> y;
		swizzle<T, N, 1, 1> g;
		swizzle<T, N, 1, 1> t;
		swizzle<T, N, 1, 2> z;
		swizzle<T, N, 1, 2> b;
		swizzle<T, N, 1, 2> p;
		*/

#ifdef BF_XYZW
		BF_SWIZZLES_X(x);
		BF_SWIZZLES_XY(x, y);
		BF_SWIZZLES_XYZ(x, y, z);
#endif

#ifdef BF_RGBA
		BF_SWIZZLES_X(r);
		BF_SWIZZLES_XY(r, g);
		BF_SWIZZLES_XYZ(r, g, b);
#endif

#ifdef BF_STPQ
		BF_SWIZZLES_X(s);
		BF_SWIZZLES_XY(s, t);
		BF_SWIZZLES_XYZ(s, t, p);
#endif
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
	swizzle<T, N, 2, 0x0300> _x##_w; \
	swizzle<T, N, 2, 0x0301> _y##_w; \
	swizzle<T, N, 2, 0x0302> _z##_w; \
	swizzle<T, N, 2, 0x0003> _w##_x; \
	swizzle<T, N, 2, 0x0103> _w##_y; \
	swizzle<T, N, 2, 0x0203> _w##_z; \
	const swizzle<T, N, 2, 0x0303> _w##_w; \
	const swizzle<T, N, 3, 0x030000> _x##_x##_w; \
	swizzle<T, N, 3, 0x030100> _x##_y##_w; \
	swizzle<T, N, 3, 0x030200> _x##_z##_w; \
	const swizzle<T, N, 3, 0x000300> _x##_w##_x; \
	swizzle<T, N, 3, 0x010300> _x##_w##_y; \
	swizzle<T, N, 3, 0x020300> _x##_w##_z; \
	const swizzle<T, N, 3, 0x030300> _x##_w##_w; \
	swizzle<T, N, 3, 0x030001> _y##_x##_w; \
	const swizzle<T, N, 3, 0x030101> _y##_y##_w; \
	swizzle<T, N, 3, 0x030201> _y##_z##_w; \
	swizzle<T, N, 3, 0x000301> _y##_w##_x; \
	const swizzle<T, N, 3, 0x010301> _y##_w##_y; \
	swizzle<T, N, 3, 0x020301> _y##_w##_z; \
	const swizzle<T, N, 3, 0x030301> _y##_w##_w; \
	swizzle<T, N, 3, 0x030002> _z##_x##_w; \
	swizzle<T, N, 3, 0x030102> _z##_y##_w; \
	const swizzle<T, N, 3, 0x030202> _z##_z##_w; \
	swizzle<T, N, 3, 0x000302> _z##_w##_x; \
	swizzle<T, N, 3, 0x010302> _z##_w##_y; \
	const swizzle<T, N, 3, 0x020302> _z##_w##_z; \
	const swizzle<T, N, 3, 0x030302> _z##_w##_w; \
	const swizzle<T, N, 3, 0x000003> _w##_x##_x; \
	swizzle<T, N, 3, 0x010003> _w##_x##_y; \
	swizzle<T, N, 3, 0x020003> _w##_x##_z; \
	const swizzle<T, N, 3, 0x030003> _w##_x##_w; \
	swizzle<T, N, 3, 0x000103> _w##_y##_x; \
	const swizzle<T, N, 3, 0x010103> _w##_y##_y; \
	swizzle<T, N, 3, 0x020103> _w##_y##_z; \
	const swizzle<T, N, 3, 0x030103> _w##_y##_w; \
	swizzle<T, N, 3, 0x000203> _w##_z##_x; \
	swizzle<T, N, 3, 0x010203> _w##_z##_y; \
	const swizzle<T, N, 3, 0x020203> _w##_z##_z; \
	const swizzle<T, N, 3, 0x030203> _w##_z##_w; \
	const swizzle<T, N, 3, 0x000303> _w##_w##_x; \
	const swizzle<T, N, 3, 0x010303> _w##_w##_y; \
	const swizzle<T, N, 3, 0x020303> _w##_w##_z; \
	const swizzle<T, N, 3, 0x030303> _w##_w##_w; \
	const swizzle<T, N, 4, 0x03000000> _x##_x##_x##_w; \
	const swizzle<T, N, 4, 0x03010000> _x##_x##_y##_w; \
	const swizzle<T, N, 4, 0x03020000> _x##_x##_z##_w; \
	const swizzle<T, N, 4, 0x00030000> _x##_x##_w##_x; \
	const swizzle<T, N, 4, 0x01030000> _x##_x##_w##_y; \
	const swizzle<T, N, 4, 0x02030000> _x##_x##_w##_z; \
	const swizzle<T, N, 4, 0x03030000> _x##_x##_w##_w; \
	const swizzle<T, N, 4, 0x03000100> _x##_y##_x##_w; \
	const swizzle<T, N, 4, 0x03010100> _x##_y##_y##_w; \
	swizzle<T, N, 4, 0x03020100> _x##_y##_z##_w; \
	const swizzle<T, N, 4, 0x00030100> _x##_y##_w##_x; \
	const swizzle<T, N, 4, 0x01030100> _x##_y##_w##_y; \
	swizzle<T, N, 4, 0x02030100> _x##_y##_w##_z; \
	const swizzle<T, N, 4, 0x03030100> _x##_y##_w##_w; \
	const swizzle<T, N, 4, 0x03000200> _x##_z##_x##_w; \
	swizzle<T, N, 4, 0x03010200> _x##_z##_y##_w; \
	const swizzle<T, N, 4, 0x03020200> _x##_z##_z##_w; \
	const swizzle<T, N, 4, 0x00030200> _x##_z##_w##_x; \
	swizzle<T, N, 4, 0x01030200> _x##_z##_w##_y; \
	const swizzle<T, N, 4, 0x02030200> _x##_z##_w##_z; \
	const swizzle<T, N, 4, 0x03030200> _x##_z##_w##_w; \
	const swizzle<T, N, 4, 0x00000300> _x##_w##_x##_x; \
	const swizzle<T, N, 4, 0x01000300> _x##_w##_x##_y; \
	const swizzle<T, N, 4, 0x02000300> _x##_w##_x##_z; \
	const swizzle<T, N, 4, 0x03000300> _x##_w##_x##_w; \
	const swizzle<T, N, 4, 0x00010300> _x##_w##_y##_x; \
	const swizzle<T, N, 4, 0x01010300> _x##_w##_y##_y; \
	swizzle<T, N, 4, 0x02010300> _x##_w##_y##_z; \
	const swizzle<T, N, 4, 0x03010300> _x##_w##_y##_w; \
	const swizzle<T, N, 4, 0x00020300> _x##_w##_z##_x; \
	swizzle<T, N, 4, 0x01020300> _x##_w##_z##_y; \
	const swizzle<T, N, 4, 0x02020300> _x##_w##_z##_z; \
	const swizzle<T, N, 4, 0x03020300> _x##_w##_z##_w; \
	const swizzle<T, N, 4, 0x00030300> _x##_w##_w##_x; \
	const swizzle<T, N, 4, 0x01030300> _x##_w##_w##_y; \
	const swizzle<T, N, 4, 0x02030300> _x##_w##_w##_z; \
	const swizzle<T, N, 4, 0x03030300> _x##_w##_w##_w; \
	const swizzle<T, N, 4, 0x03000001> _y##_x##_x##_w; \
	const swizzle<T, N, 4, 0x03010001> _y##_x##_y##_w; \
	swizzle<T, N, 4, 0x03020001> _y##_x##_z##_w; \
	const swizzle<T, N, 4, 0x00030001> _y##_x##_w##_x; \
	const swizzle<T, N, 4, 0x01030001> _y##_x##_w##_y; \
	swizzle<T, N, 4, 0x02030001> _y##_x##_w##_z; \
	const swizzle<T, N, 4, 0x03030001> _y##_x##_w##_w; \
	const swizzle<T, N, 4, 0x03000101> _y##_y##_x##_w; \
	const swizzle<T, N, 4, 0x03010101> _y##_y##_y##_w; \
	const swizzle<T, N, 4, 0x03020101> _y##_y##_z##_w; \
	const swizzle<T, N, 4, 0x00030101> _y##_y##_w##_x; \
	const swizzle<T, N, 4, 0x01030101> _y##_y##_w##_y; \
	const swizzle<T, N, 4, 0x02030101> _y##_y##_w##_z; \
	const swizzle<T, N, 4, 0x03030101> _y##_y##_w##_w; \
	swizzle<T, N, 4, 0x03000201> _y##_z##_x##_w; \
	const swizzle<T, N, 4, 0x03010201> _y##_z##_y##_w; \
	const swizzle<T, N, 4, 0x03020201> _y##_z##_z##_w; \
	swizzle<T, N, 4, 0x00030201> _y##_z##_w##_x; \
	const swizzle<T, N, 4, 0x01030201> _y##_z##_w##_y; \
	const swizzle<T, N, 4, 0x02030201> _y##_z##_w##_z; \
	const swizzle<T, N, 4, 0x03030201> _y##_z##_w##_w; \
	const swizzle<T, N, 4, 0x00000301> _y##_w##_x##_x; \
	const swizzle<T, N, 4, 0x01000301> _y##_w##_x##_y; \
	swizzle<T, N, 4, 0x02000301> _y##_w##_x##_z; \
	const swizzle<T, N, 4, 0x03000301> _y##_w##_x##_w; \
	const swizzle<T, N, 4, 0x00010301> _y##_w##_y##_x; \
	const swizzle<T, N, 4, 0x01010301> _y##_w##_y##_y; \
	const swizzle<T, N, 4, 0x02010301> _y##_w##_y##_z; \
	const swizzle<T, N, 4, 0x03010301> _y##_w##_y##_w; \
	swizzle<T, N, 4, 0x00020301> _y##_w##_z##_x; \
	const swizzle<T, N, 4, 0x01020301> _y##_w##_z##_y; \
	const swizzle<T, N, 4, 0x02020301> _y##_w##_z##_z; \
	const swizzle<T, N, 4, 0x03020301> _y##_w##_z##_w; \
	const swizzle<T, N, 4, 0x00030301> _y##_w##_w##_x; \
	const swizzle<T, N, 4, 0x01030301> _y##_w##_w##_y; \
	const swizzle<T, N, 4, 0x02030301> _y##_w##_w##_z; \
	const swizzle<T, N, 4, 0x03030301> _y##_w##_w##_w; \
	const swizzle<T, N, 4, 0x03000002> _z##_x##_x##_w; \
	swizzle<T, N, 4, 0x03010002> _z##_x##_y##_w; \
	const swizzle<T, N, 4, 0x03020002> _z##_x##_z##_w; \
	const swizzle<T, N, 4, 0x00030002> _z##_x##_w##_x; \
	swizzle<T, N, 4, 0x01030002> _z##_x##_w##_y; \
	const swizzle<T, N, 4, 0x02030002> _z##_x##_w##_z; \
	const swizzle<T, N, 4, 0x03030002> _z##_x##_w##_w; \
	swizzle<T, N, 4, 0x03000102> _z##_y##_x##_w; \
	const swizzle<T, N, 4, 0x03010102> _z##_y##_y##_w; \
	const swizzle<T, N, 4, 0x03020102> _z##_y##_z##_w; \
	swizzle<T, N, 4, 0x00030102> _z##_y##_w##_x; \
	const swizzle<T, N, 4, 0x01030102> _z##_y##_w##_y; \
	const swizzle<T, N, 4, 0x02030102> _z##_y##_w##_z; \
	const swizzle<T, N, 4, 0x03030102> _z##_y##_w##_w; \
	const swizzle<T, N, 4, 0x03000202> _z##_z##_x##_w; \
	const swizzle<T, N, 4, 0x03010202> _z##_z##_y##_w; \
	const swizzle<T, N, 4, 0x03020202> _z##_z##_z##_w; \
	const swizzle<T, N, 4, 0x00030202> _z##_z##_w##_x; \
	const swizzle<T, N, 4, 0x01030202> _z##_z##_w##_y; \
	const swizzle<T, N, 4, 0x02030202> _z##_z##_w##_z; \
	const swizzle<T, N, 4, 0x03030202> _z##_z##_w##_w; \
	const swizzle<T, N, 4, 0x00000302> _z##_w##_x##_x; \
	swizzle<T, N, 4, 0x01000302> _z##_w##_x##_y; \
	const swizzle<T, N, 4, 0x02000302> _z##_w##_x##_z; \
	const swizzle<T, N, 4, 0x03000302> _z##_w##_x##_w; \
	swizzle<T, N, 4, 0x00010302> _z##_w##_y##_x; \
	const swizzle<T, N, 4, 0x01010302> _z##_w##_y##_y; \
	const swizzle<T, N, 4, 0x02010302> _z##_w##_y##_z; \
	const swizzle<T, N, 4, 0x03010302> _z##_w##_y##_w; \
	const swizzle<T, N, 4, 0x00020302> _z##_w##_z##_x; \
	const swizzle<T, N, 4, 0x01020302> _z##_w##_z##_y; \
	const swizzle<T, N, 4, 0x02020302> _z##_w##_z##_z; \
	const swizzle<T, N, 4, 0x03020302> _z##_w##_z##_w; \
	const swizzle<T, N, 4, 0x00030302> _z##_w##_w##_x; \
	const swizzle<T, N, 4, 0x01030302> _z##_w##_w##_y; \
	const swizzle<T, N, 4, 0x02030302> _z##_w##_w##_z; \
	const swizzle<T, N, 4, 0x03030302> _z##_w##_w##_w; \
	const swizzle<T, N, 4, 0x00000003> _w##_x##_x##_x; \
	const swizzle<T, N, 4, 0x01000003> _w##_x##_x##_y; \
	const swizzle<T, N, 4, 0x02000003> _w##_x##_x##_z; \
	const swizzle<T, N, 4, 0x03000003> _w##_x##_x##_w; \
	const swizzle<T, N, 4, 0x00010003> _w##_x##_y##_x; \
	const swizzle<T, N, 4, 0x01010003> _w##_x##_y##_y; \
	swizzle<T, N, 4, 0x02010003> _w##_x##_y##_z; \
	const swizzle<T, N, 4, 0x03010003> _w##_x##_y##_w; \
	const swizzle<T, N, 4, 0x00020003> _w##_x##_z##_x; \
	swizzle<T, N, 4, 0x01020003> _w##_x##_z##_y; \
	const swizzle<T, N, 4, 0x02020003> _w##_x##_z##_z; \
	const swizzle<T, N, 4, 0x03020003> _w##_x##_z##_w; \
	const swizzle<T, N, 4, 0x00030003> _w##_x##_w##_x; \
	const swizzle<T, N, 4, 0x01030003> _w##_x##_w##_y; \
	const swizzle<T, N, 4, 0x02030003> _w##_x##_w##_z; \
	const swizzle<T, N, 4, 0x03030003> _w##_x##_w##_w; \
	const swizzle<T, N, 4, 0x00000103> _w##_y##_x##_x; \
	const swizzle<T, N, 4, 0x01000103> _w##_y##_x##_y; \
	swizzle<T, N, 4, 0x02000103> _w##_y##_x##_z; \
	const swizzle<T, N, 4, 0x03000103> _w##_y##_x##_w; \
	const swizzle<T, N, 4, 0x00010103> _w##_y##_y##_x; \
	const swizzle<T, N, 4, 0x01010103> _w##_y##_y##_y; \
	const swizzle<T, N, 4, 0x02010103> _w##_y##_y##_z; \
	const swizzle<T, N, 4, 0x03010103> _w##_y##_y##_w; \
	swizzle<T, N, 4, 0x00020103> _w##_y##_z##_x; \
	const swizzle<T, N, 4, 0x01020103> _w##_y##_z##_y; \
	const swizzle<T, N, 4, 0x02020103> _w##_y##_z##_z; \
	const swizzle<T, N, 4, 0x03020103> _w##_y##_z##_w; \
	const swizzle<T, N, 4, 0x00030103> _w##_y##_w##_x; \
	const swizzle<T, N, 4, 0x01030103> _w##_y##_w##_y; \
	const swizzle<T, N, 4, 0x02030103> _w##_y##_w##_z; \
	const swizzle<T, N, 4, 0x03030103> _w##_y##_w##_w; \
	const swizzle<T, N, 4, 0x00000203> _w##_z##_x##_x; \
	swizzle<T, N, 4, 0x01000203> _w##_z##_x##_y; \
	const swizzle<T, N, 4, 0x02000203> _w##_z##_x##_z; \
	const swizzle<T, N, 4, 0x03000203> _w##_z##_x##_w; \
	swizzle<T, N, 4, 0x00010203> _w##_z##_y##_x; \
	const swizzle<T, N, 4, 0x01010203> _w##_z##_y##_y; \
	const swizzle<T, N, 4, 0x02010203> _w##_z##_y##_z; \
	const swizzle<T, N, 4, 0x03010203> _w##_z##_y##_w; \
	const swizzle<T, N, 4, 0x00020203> _w##_z##_z##_x; \
	const swizzle<T, N, 4, 0x01020203> _w##_z##_z##_y; \
	const swizzle<T, N, 4, 0x02020203> _w##_z##_z##_z; \
	const swizzle<T, N, 4, 0x03020203> _w##_z##_z##_w; \
	const swizzle<T, N, 4, 0x00030203> _w##_z##_w##_x; \
	const swizzle<T, N, 4, 0x01030203> _w##_z##_w##_y; \
	const swizzle<T, N, 4, 0x02030203> _w##_z##_w##_z; \
	const swizzle<T, N, 4, 0x03030203> _w##_z##_w##_w; \
	const swizzle<T, N, 4, 0x00000303> _w##_w##_x##_x; \
	const swizzle<T, N, 4, 0x01000303> _w##_w##_x##_y; \
	const swizzle<T, N, 4, 0x02000303> _w##_w##_x##_z; \
	const swizzle<T, N, 4, 0x03000303> _w##_w##_x##_w; \
	const swizzle<T, N, 4, 0x00010303> _w##_w##_y##_x; \
	const swizzle<T, N, 4, 0x01010303> _w##_w##_y##_y; \
	const swizzle<T, N, 4, 0x02010303> _w##_w##_y##_z; \
	const swizzle<T, N, 4, 0x03010303> _w##_w##_y##_w; \
	const swizzle<T, N, 4, 0x00020303> _w##_w##_z##_x; \
	const swizzle<T, N, 4, 0x01020303> _w##_w##_z##_y; \
	const swizzle<T, N, 4, 0x02020303> _w##_w##_z##_z; \
	const swizzle<T, N, 4, 0x03020303> _w##_w##_z##_w; \
	const swizzle<T, N, 4, 0x00030303> _w##_w##_w##_x; \
	const swizzle<T, N, 4, 0x01030303> _w##_w##_w##_y; \
	const swizzle<T, N, 4, 0x02030303> _w##_w##_w##_z; \
	const swizzle<T, N, 4, 0x03030303> _w##_w##_w##_w

/*
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
*/

template <typename T>
class vector_storage<T, 4> {
protected:
	static const std::size_t N = 4;

public:
	union {
		swizzle<T, N, 1, 0x00> x;
		swizzle<T, N, 1, 0x00> r;
		swizzle<T, N, 1, 0x00> s;
		swizzle<T, N, 1, 0x01> y;
		swizzle<T, N, 1, 0x01> g;
		swizzle<T, N, 1, 0x01> t;
		swizzle<T, N, 1, 0x02> z;
		swizzle<T, N, 1, 0x02> b;
		swizzle<T, N, 1, 0x02> p;

		/*
		swizzle<T, N, 1, 0> x;
		swizzle<T, N, 1, 0> r;
		swizzle<T, N, 1, 0> s;
		swizzle<T, N, 1, 1> y;
		swizzle<T, N, 1, 1> g;
		swizzle<T, N, 1, 1> t;
		swizzle<T, N, 1, 2> z;
		swizzle<T, N, 1, 2> b;
		swizzle<T, N, 1, 2> p;
		*/

#ifdef BF_XYZW
		BF_SWIZZLES_X(x);
		BF_SWIZZLES_XY(x, y);
		BF_SWIZZLES_XYZ(x, y, z);
		BF_SWIZZLES_XYZW(x, y, z, w);
#endif

#ifdef BF_RGBA
		BF_SWIZZLES_X(r);
		BF_SWIZZLES_XY(r, g);
		BF_SWIZZLES_XYZ(r, g, b);
		BF_SWIZZLES_XYZW(r, g, b, a);
#endif

#ifdef BF_STPQ
		BF_SWIZZLES_X(s);
		BF_SWIZZLES_XY(s, t);
		BF_SWIZZLES_XYZ(s, t, p);
		BF_SWIZZLES_XYZW(s, t, p, q);
#endif
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