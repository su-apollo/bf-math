#pragma once
#include <cstddef>

namespace bf {
namespace math {
template <typename T, std::size_t N>
class vector {};

template <typename T, std::size_t N, typename S>
class vector_usage : public S {
public:
	vector_usage& operator += (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] += operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator += (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] += temp[i];
		return *this;
	}

	vector_usage& operator -= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] -= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator -= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] -= temp[i];
		return *this;
	}

	vector_usage& operator *= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] *= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator *= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] *= temp[i];
		return *this;
	}

	vector_usage& operator /= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] /= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator /= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] /= temp[i];
		return *this;
	}

	vector_usage& operator %= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] %= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator %= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] %= temp[i];
		return *this;
	}

	vector_usage& operator ^= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] ^= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator ^= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] ^= temp[i];
		return *this;
	}

	vector_usage& operator &= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] &= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator &= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] &= temp[i];
		return *this;
	}

	vector_usage& operator |= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] |= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator |= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] |= temp[i];
		return *this;
	}

	vector_usage& operator <<= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] <<= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator <<= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] <<= temp[i];
		return *this;
	}

	vector_usage& operator >>= (const T& operand) {
		for (auto i = 0; i < N; ++i)
			(*this)[i] >>= operand;
		return *this;
	}

	template <typename T2, typename S2>
	vector_usage& operator >>= (const vector_usage<T2, N, S2>& operand) {
		vector<T, N> temp;
		for (auto i = 0; i < N; ++i)
			temp[i] = operand[i];
		for (auto i = 0; i < N; ++i)
			(*this)[i] >>= temp[i];
		return *this;
	}

	vector_usage& operator ++ () {
		for (auto i = 0; i < N; ++i)
			++(*this)[i];
		return *this;
	}

	const vector_usage operator ++ (int) {
		vector_usage ret(*this);
		for (auto i = 0; i < N; ++i)
			++(*this)[i];
		return ret;
	}

	vector_usage& operator -- () {
		for (auto i = 0; i < N; ++i)
			--(*this)[i];
		return *this;
	}

	const vector_usage operator -- (int) {
		vector_usage ret(*this);
		for (auto i = 0; i < N; ++i)
			--(*this)[i];
		return ret;
	}
};

template <typename T, std::size_t N, typename S>
class vector_plural_usage : public vector_usage<T, N, S> {
};
}
}