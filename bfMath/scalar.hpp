#pragma once

namespace bf {
namespace math{
template <typename T1, typename T2 = T1>
struct scalar_traits {};

template <>
struct scalar_traits<float> {
	typedef float scalar_type;
	typedef bool bool_type;
};

template <>
struct scalar_traits<int> {
	typedef int scalar_type;
	typedef bool bool_type;
	typedef int int_type;
};

template <>
struct scalar_traits<bool> {
	typedef bool scalar_type;
	typedef bool bool_type;
};

template <>
struct scalar_traits<double> {
	typedef double scalar_type;
	typedef bool bool_type;
};


template <>
struct scalar_traits<float, int> : scalar_traits<float>{};

template <>
struct scalar_traits<int, float> : scalar_traits<float>{};

template <>
struct scalar_traits<double, float> : scalar_traits<double>{};

template <>
struct scalar_traits<float, double> : scalar_traits<double>{};

template <>
struct scalar_traits<double, int> : scalar_traits<double>{};

template <>
struct scalar_traits<int, double> : scalar_traits<double>{};
}
}