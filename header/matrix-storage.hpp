#pragma once
#include "swizzle.hpp"

#include <exception>

namespace bf {
namespace math {
template<typename T, int ROWS, int COLS, typename Straits = scalar_traits<T, T>>
class matrix_storage {	
};

// ms	_m00 ~ _m33
// s	_11 ~ _44
#define BF_MATRIX_USAGE(ms, s) ms, s

#define BF_MATRIX_SWIZZLE1(x0, y0) \
	swizzle<T, ELEMS, 1, >

#define BF_MATRIX_SWIZZLE2(x0, y0, x1, y1) \
	swizzle<T, ELEMS, 2, >

#define BF_MATRIX_SWIZZLE3(x0, y0, x1, y1, x2, y2) \
	swizzle<T, ELEMS, 3, >

#define BF_MATRIX_SWIZZLE4(x0, y0, x1, y1, x2, y2, x3, y3) \
	swizzle<T, ELEMS, 4, >

#define BF_MATRIX_ELEMENT(row, x, ms, s) \
	BF_MATRIX_SWIZZLE1(row, x) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_ROW_SWIZZLE2(row, x, y, ms, s) \
	BF_MATRIX_SWIZZLE2(row, x, row, y) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_ROW_SWIZZLE3(row, x, y, z, ms, s) \
	BF_MATRIX_SWIZZLE3(row, x, row, y, row, z) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_ROW_SWIZZLE4(row, x, y, z, w, ms, s) \
	BF_MATRIX_SWIZZLE3(row, x, row, y, row, z, row, w) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_COLUMN_SWIZZLE2(col, x, y, ms, s) \
	BF_MATRIX_SWIZZLE2(x, col, y, col) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_COLUMN_SWIZZLE3(col, x, y, z, ms, s) \
	BF_MATRIX_SWIZZLE2(x, col, y, col, z, col) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_COLUMN_SWIZZLE4(col, x, y, z, w, ms, s) \
	BF_MATRIX_SWIZZLE2(x, col, y, col, z, col, w, col) BF_MATRIX_USAGE(ms, s)

#define BF_MATRIX_SWIZZLE_1x1() \
	BF_MATRIX_ELEMENT(0, 0, _m00, _11)

#define BF_MATRIX_SWIZZLE_1x2() \
	BF_MATRIX_ELEMENT(0, 1, _m01, _12) \
	BF_MATRIX_ROW_SWIZZLE2(0, 0, 1, _m00_m01, _11_12) \
	BF_MATRIX_ROW_SWIZZLE2(0, 1, 0, _m01_m00, _12_11)

#define BF_MATRIX_SWIZZLE_1x3() \
	BF_MATRIX_ELEMENT(0, 2, _m02, _13) \
	BF_MATRIX_ROW_SWIZZLE2(0, 0, 2, _m00_m02, _11_13) \
	BF_MATRIX_ROW_SWIZZLE2(0, 1, 2, _m01_m02, _12_13) \
	BF_MATRIX_ROW_SWIZZLE2(0, 2, 0, _m02_m00, _13_11) \
	BF_MATRIX_ROW_SWIZZLE2(0, 2, 1, _m02_m01, _13_12) \
	BF_MATRIX_ROW_SWIZZLE2(0, 2, 2, _m02_m02, _13_13) \
	BF_MATRIX_ROW_SWIZZLE3(0, 0, 1, 2, _m00_m01_m02, _11_12_13) \
	BF_MATRIX_ROW_SWIZZLE3(0, 0, 2, 1, _m00_m02_m01, _11_13_12) \
	BF_MATRIX_ROW_SWIZZLE3(0, 1, 0, 2, _m01_m00_m02, _12_11_13) \
	BF_MATRIX_ROW_SWIZZLE3(0, 1, 2, 0, _m01_m02_m00, _12_13_11) \
	BF_MATRIX_ROW_SWIZZLE3(0, 2, 0, 1, _m02_m00_m01, _13_11_12) \
	BF_MATRIX_ROW_SWIZZLE3(0, 2, 1, 0, _m02_m01_m00, _13_12_11)

template <typename T>
class matrix_storage<T, 1, 1> {
protected:
	static const std::size_t ROWS = 1;
	static const std::size_t COLS = 1;
	static const std::size_t ELEMS = ROWS * COLS;
public:
    union {
		BF_MATRIX_SWIZZLE_1x1();
	};
};

template <typename T>
class matrix_storage<T, 1, 2> {
protected:
	static const std::size_t ROWS = 1;
	static const std::size_t COLS = 2;
	static const std::size_t ELEMS = ROWS * COLS;
public:
    union {
		BF_MATRIX_SWIZZLE_1x1();
		BF_MATRIX_SWIZZLE_1x2();
	};
};

template <typename T>
class matrix_storage<T, 1, 3> {
protected:
	static const std::size_t ROWS = 1;
	static const std::size_t COLS = 3;
	static const std::size_t ELEMS = ROWS * COLS;
public:
    union {
		BF_MATRIX_SWIZZLE_1x1();
		BF_MATRIX_SWIZZLE_1x2();
		BF_MATRIX_SWIZZLE_1x3();
	};
};

template <typename T>
class matrix_storage<T, 1, 4> {
protected:
	static const std::size_t ROWS = 1;
	static const std::size_t COLS = 4;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 2, 1> {
protected:
	static const std::size_t ROWS = 2;
	static const std::size_t COLS = 1;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 2, 2> {
protected:
	static const std::size_t ROWS = 2;
	static const std::size_t COLS = 2;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 2, 3> {
protected:
	static const std::size_t ROWS = 2;
	static const std::size_t COLS = 3;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 2, 4> {
protected:
	static const std::size_t ROWS = 2;
	static const std::size_t COLS = 4;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 3, 1> {
protected:
	static const std::size_t ROWS = 3;
	static const std::size_t COLS = 1;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 3, 2> {
protected:
	static const std::size_t ROWS = 3;
	static const std::size_t COLS = 2;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 3, 3> {
protected:
	static const std::size_t ROWS = 3;
	static const std::size_t COLS = 3;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 3, 4> {
protected:
	static const std::size_t ROWS = 3;
	static const std::size_t COLS = 4;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 4, 1> {
protected:
	static const std::size_t ROWS = 4;
	static const std::size_t COLS = 1;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 4, 2> {
protected:
	static const std::size_t ROWS = 4;
	static const std::size_t COLS = 2;
	static const std::size_t ELEMS = ROWS * COLS;
};
	
template <typename T>
class matrix_storage<T, 4, 3> {
protected:
	static const std::size_t ROWS = 4;
	static const std::size_t COLS = 3;
	static const std::size_t ELEMS = ROWS * COLS;
};

template <typename T>
class matrix_storage<T, 4, 4> {
protected:
	static const std::size_t ROWS = 4;
	static const std::size_t COLS = 4;
	static const std::size_t ELEMS = ROWS * COLS;
};
}
}