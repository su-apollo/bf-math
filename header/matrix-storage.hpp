#pragma once
#include "matrix-usage.hpp"

namespace bf {
namespace math{
#define BF_MATRIX_X(row, col) ((row * cols + col) << 0)
#define BF_MATRIX_Y(row, col) ((row * cols + col) << 8)
#define BF_MATRIX_Z(row, col) ((row * cols + col) << 16)
#define BF_MATRIX_W(row, col) ((row * cols + col) << 24)

#define BF_MATRIX_SMASK1(x0, y0) \
	BF_MATRIX_X(x0, y0)

#define BF_MATRIX_SWIZZLE1(x0, y0) \
	swizzle<T, ELEMS, 1, BF_MATRIX_SMASK1(x0, y0)>

#define BF_MATRIX_SMASK2(x0, y0, x1, y1) \
	BF_MATRIX_X(x0, y0) | \
	BF_MATRIX_Y(x1, y1)

#define BF_MATRIX_SWIZZLE2(x0, y0, x1, y1) \
	swizzle<T, ELEMS, 2, BF_MATRIX_SMASK2(x0, y0, x1, y1)>

#define BF_MATRIX_SMASK3(x0, y0, x1, y1, x2, y2) \
	BF_MATRIX_X(x0, y0) | \
	BF_MATRIX_Y(x1, y1) | \
	BF_MATRIX_Z(x2, y2)

#define BF_MATRIX_SWIZZLE3(x0, y0, x1, y1, x2, y2) \
	swizzle<T, ELEMS, 3, BF_MATRIX_SMASK3(x0, y0, x1, y1, x2, y2)>

#define BF_MATRIX_SMASK4(x0, y0, x1, y1, x2, y2, x3, y3) \
	BF_MATRIX_X(x0, y0) | \
	BF_MATRIX_Y(x1, y1) | \
	BF_MATRIX_Z(x2, y2) | \
	BF_MATRIX_W(x3, y3)

#define __CG_MATRIX_SWIZZLE4(x0, y0, x1, y1, x2, y2, x3, y3) \
	swizzle<T, ELEMS, 4, BF_MATRIX_SMASK4(x0, y0, x1, y1, x2, y2, x3, y3)>



}
}