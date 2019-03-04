#include "vector.hpp"

#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

/*
void create_console() {
	if (::AllocConsole())
	{
		auto h_crt = ::_open_osfhandle(intptr_t(::GetStdHandle(STD_OUTPUT_HANDLE)), _O_TEXT);
		auto hf = ::_fdopen(h_crt, "w");
		const auto so = stdout;
		const auto se = stderr;
		*so = *hf;
		::setvbuf(stdout, nullptr, _IONBF, 0);

		h_crt = ::_open_osfhandle(intptr_t(::GetStdHandle(STD_ERROR_HANDLE)), _O_TEXT);
		hf = ::_fdopen(h_crt, "w");
		*se = *hf;
		::setvbuf(stderr, nullptr, _IONBF, 0);
	}
}
*/

// program entry
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//create_console();

	std::cout << "Hello World!" << std::endl;

	/*
	const auto vec1 = bf::float1(1.f);
	const auto vec2 = bf::float2(1.f, 2.f);
	const auto vec3 = bf::float3(1.f, 2.f, 3.f);
	const auto vec4 = bf::float4(1.f, 2.f, 3.f, 4.f);
	*/

	bf::float1 vec1(1.f);
	bf::float2 vec2(1.f, 2.f);
	bf::float3 vec3(1.f, 2.f, 3.f);
	bf::float4 vec4(1.f, 2.f, 3.f, 4.f);

	std::cout << vec1.x << std::endl;
	std::cout << vec2.y << std::endl;
	std::cout << vec3.z << std::endl;
	std::cout << vec4.w << std::endl;

	/*
	auto foo = bf::float4(0);
	foo.yx = bf::float2(2, 1);
	foo.zw = foo.xy * 2;

	auto temp = std::move(foo);
	auto temp2(std::move(temp));

	std::cout << temp2.y << std::endl;
	*/

	//system("PAUSE");
	// Exit program
	exit(EXIT_SUCCESS);
}