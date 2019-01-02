#include "xyzw.hpp"
#include "vector.hpp"

#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <vector>
#include <string>
#include <type_traits>

void CreateConsole() {
	if (::AllocConsole())
	{
		int hCrt = ::_open_osfhandle((intptr_t) ::GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
		FILE *hf = ::_fdopen(hCrt, "w");
		*stdout = *hf;
		::setvbuf(stdout, NULL, _IONBF, 0);

		hCrt = ::_open_osfhandle((intptr_t) ::GetStdHandle(STD_ERROR_HANDLE), _O_TEXT);
		hf = ::_fdopen(hCrt, "w");
		*stderr = *hf;
		::setvbuf(stderr, NULL, _IONBF, 0);
	}
}

// program entry
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CreateConsole();

	std::cout << "Hello World!" << std::endl;

	std::vector<int> temp;

	std::string test;

	if (std::is_scalar<int>::value)
		std::cout << "int is scalar" << std::endl;

	if (std::is_scalar<bool>::value)
		std::cout << "bool is scalar" << std::endl;

	bf::float1 vec1(1.f);
	bf::float2 vec2(1.f, 2.f);
	bf::float3 vec3(1.f, 2.f, 3.f);
	bf::float4 vec4(1.f, 2.f, 3.f, 4.f);

	bf::float4 foo(0);
	foo.yx = bf::float2(2, 1);
	foo.zw = foo.xy * 2;

	system("PAUSE");
	// Exit program
	exit(EXIT_SUCCESS);
}