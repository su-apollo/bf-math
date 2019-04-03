#pragma once
#include <cmath>
#include <algorithm>

namespace bf {
class rotation {
public:
	float c, s;

	explicit rotation(const float angle) {		
		c = std::cos(angle);
		s = std::sin(angle);
	}




};	
}
