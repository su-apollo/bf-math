#pragma once
#include "scalar.hpp"

#include <exception>

namespace bf {


template <typename T, std::size_t N, std::size_t... Indices>
class swizzle_storage {
	static_assert(I < N, "Index out of range");
private:
	typename scalar_traits<T>::scalar_type value[N];



};
}