#include "vector.hpp"

#include <Windows.h>
#include <iostream>

// program entry
int main() {
	std::cout << "Hello World!" << std::endl;

	bf::float1 vec1(1.f);
	bf::float2 vec2(1.f, 2.f);
	bf::float3 vec3(1.f, 2.f, 3.f);
	bf::float4 vec4(1.f, 2.f, 3.f, 4.f);

	std::cout << vec1.x << std::endl;
	std::cout << vec2.y << std::endl;
	std::cout << vec3.z << std::endl;
	std::cout << vec4.w << std::endl;

	system("PAUSE");
	return 0;
}