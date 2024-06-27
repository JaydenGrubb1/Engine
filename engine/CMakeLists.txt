cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

project(EngineCore) # TODO: Change project title
enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
	-Wall
	-Wextra
	-Wpedantic
	-Wold-style-cast
)

set(ENGINE_SRC
	test.cpp
)

list(TRANSFORM ENGINE_SRC PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/")
add_library(${PROJECT_NAME} SHARED ${ENGINE_SRC})

find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE
	${Vulkan_INCLUDE_DIRS}
	${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
	Vulkan::Vulkan
	SDL2::SDL2
)