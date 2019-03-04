#pragma once
#include "vector.hpp"

namespace bf {
namespace math {
template <typename T, int ROWS, int COLS>
class matrix_storage {};

template <typename T, int ROWS, int COLS>
class matrix {};

template <typename T, int ROWS, int COLS>
class matrix_usage : public matrix_storage<T, ROWS, COLS>
{
private:
	static const int rows = ROWS;
	static const int cols = COLS;
	static const int ELEMS = rows * cols;
	typedef typename scalar_trait<T>::scalar_type value_type;

public:
	matrix_usage() = default;
	~matrix_usage() = default;

	matrix_usage(const T& s) {
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				(*this)[i][j] = s;
			}
		}
	}

	template <typename T2>
	matrix_usage(const matrix_usage<T2, ROWS, COLS>& v) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] = vector<T, COLS>(v[i]);
		}
	}

	vector<T, COLS>& operator [] (int i) {
		value_type* base = reinterpret_cast<value_type*>(this);
		base += COLS * i;
		vector<T, COLS>* row = reinterpret_cast<vector<T, COLS>*>(base);
		return *row;
	}
	
	const vector<T, COLS>& operator [] (int i) const {
		const value_type* base = reinterpret_cast<const value_type*>(this);
		base += COLS * i;
		const vector<T, COLS> *row = reinterpret_cast<const vector<T, COLS>*>(base);
		return *row;
	}

	template <typename T2>
	matrix_usage& operator = (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] = vector<T, COLS>(operand[i]);
		}
		return *this;
	}

	template <typename T2>
	matrix_usage& operator = (matrix_usage<T2, ROWS, COLS>&& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] = vector<T, COLS>(std::move(operand[i]));
		}
		return *this;
	}

	matrix_usage& operator = (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] = s;
		}
		return *this;
	}

	matrix_usage& operator = (T&& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] = std::move(s);
		}
		return *this;
	}

	template <typename T2>
	matrix_usage& operator += (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] += vector<T, COLS>(operand[i]);
		}
		return *this;
	}

	matrix_usage& operator += (const T & operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] += operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator -= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] -= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator -= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] -= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator *= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] *= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator *= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] *= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator /= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] /= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator /= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] /= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator %= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] %= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator %= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] %= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator ^= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] ^= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator ^= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] ^= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator &= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] &= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator &= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] &= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator |= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] |= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator |= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] |= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator <<= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] <<= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator <<= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] <<= operand;
		}
		return *this;
	}
	
	template <typename T2>
	matrix_usage& operator >>= (const matrix_usage<T2, ROWS, COLS>& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] >>= vector<T, COLS>(operand[i]);
		}
		return *this;
	}
	
	matrix_usage& operator >>= (const T& operand) {
		for (int i = 0; i < ROWS; ++i) {
			(*this)[i] >>= operand;
		}
		return *this;
	}

	matrix_usage& operator ++ () {
		for (int i = 0; i < ROWS; ++i) {
			++(*this)[i];
		}
		return *this;
	}
	
	matrix_usage operator ++ (int) { 
		matrix_usage ret(*this);
		for (int i = 0; i < ROWS; ++i) {
			++(*this)[i];
		}
		return ret;
	}
	
	matrix_usage& operator -- () { 
		for (int i = 0; i < ROWS; ++i) {
			--(*this)[i];
		}
		return *this;
	}
	
	matrix_usage operator -- (int) { 
		matrix_usage ret(*this);
		for (int i = 0; i < ROWS; ++i) {
			--(*this)[i];
		}
		return ret;
	}
};
}
}