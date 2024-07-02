cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

project(Engine) # TODO: Change project title
enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
	add_compile_options(
		/W4
	)
else ()
	add_compile_options(
		-Wall
		-Wextra
		-Wpedantic
		-Wold-style-cast
	)
endif ()

add_subdirectory(engine)
add_subdirectory(example)