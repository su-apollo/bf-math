#pragma once
#include "vector-storage.hpp"

#include <utility>

namespace bf {
namespace math {
// operator +
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator + (const vector_usage<T1, N, S1>& a, const vector_usage<T2, N, S2>& b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) + result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator + (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) + result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator + (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i) {
		r[i] = result_type(static_cast<T1>(a)) + result_type(b[i]);
	}
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator + (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) + result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator + (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) + result_type(b[i]);
	return r;
}

// operator -
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator - (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) - result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator - (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) - result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator - (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) - result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator - (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) - result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator - (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) - result_type(b[i]);
	return r;
}

// operator *
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator * (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) * result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator * (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) * result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator * (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) * result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator * (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) * result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator * (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) * result_type(b[i]);
	return r;
}

// operator /
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator / (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) / result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator / (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) / result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator / (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) / result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator / (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) / result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::scalar_type, N> operator / (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::scalar_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) / result_type(b[i]);
	return r;
}

// operator %
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator % (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) % result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::int_type, N> operator % (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) % result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator % (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) % result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator % (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) % result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator % (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) % result_type(b[i]);
	return r;
}

// operator ^
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator ^ (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) ^ result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::int_type, N> operator ^ (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) ^ result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator ^ (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) ^ result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator ^ (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) ^ result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator ^ (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) ^ result_type(b[i]);
	return r;
}

// operator &
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator & (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) & result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::int_type, N> operator & (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) & result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator & (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) & result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator & (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) & result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator & (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) & result_type(b[i]);
	return r;
}

// operator |
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator | (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) | result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::int_type, N> operator | (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) | result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator | (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) | result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator | (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) | result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator | (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) | result_type(b[i]);
	return r;
}

// operator <<
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator << (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) << result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::int_type, N> operator << (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) << result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator << (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) << result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator << (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) << result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator << (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) << result_type(b[i]);
	return r;
}

// operator >>
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator >> (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) >> result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::int_type, N> operator >> (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) >> result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator >> (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) >> result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator >> (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) >> result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::int_type, N> operator >> (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::int_type result_type;
	vector<result_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) >> result_type(b[i]);
	return r;
}

// operator <
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator < (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) < result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator < (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) < result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator < (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) < result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator < (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) < result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator < (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) < result_type(b[i]);
	return r;
}

// operator >
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator > (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) > result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator > (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) > result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator > (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) > result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator > (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) > result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator > (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) > result_type(b[i]);
	return r;
}

// operator <=
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator <= (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) <= result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator <= (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) <= result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator <= (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) <= result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator <= (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) <= result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator <= (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) <= result_type(b[i]);
	return r;
}

// operator >=
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator >= (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) >= result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator >= (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) >= result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator >= (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) >= result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator >= (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) >= result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator >= (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) >= result_type(b[i]);
	return r;
}

// operator ==
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator == (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) == result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator == (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) == result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator == (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) == result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator == (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) == result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator == (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) == result_type(b[i]);
	return r;
}

// operator !=
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator != (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) != result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator != (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) != result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator != (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) != result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator != (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) != result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator != (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) != result_type(b[i]);
	return r;
}

// operator &&
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator && (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) && result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator && (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) && result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator && (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) && result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator && (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) && result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator && (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) && result_type(b[i]);
	return r;
}

// operator ||
template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator || (const vector_usage<T1, N, S1> & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) || result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator || (const vector_usage<T1, N, S1> & a, const T2 & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) || result_type(static_cast<T2>(b));
	return r;
}

template <typename T1, typename T2, int N, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator || (const T1 & a, const vector_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(static_cast<T1>(a)) || result_type(b[i]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator || (const vector_plural_usage<T1, N, S1> & a, const vector_usage<T2, 1, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[i]) || result_type(b[0]);
	return r;
}

template <typename T1, typename T2, int N, typename S1, typename S2>
vector<typename scalar_traits<T1, T2>::bool_type, N> operator || (const vector_usage<T1, 1, S1> & a, const vector_plural_usage<T2, N, S2> & b)
{
	typedef typename scalar_traits<T1, T2>::result_type result_type;
	typedef typename scalar_traits<T1, T2>::bool_type bool_type;
	vector<bool_type, N> r;
	for (int i = 0; i < N; ++i)
		r[i] = result_type(a[0]) || result_type(b[i]);
	return r;
}
}
}