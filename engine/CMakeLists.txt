set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(EngineCore) # TODO: Change project title

set(ENGINE_SRC
	core/system.cpp
	gfx/system.cpp
	gfx/window.cpp
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
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${Vulkan_INCLUDE_DIRS}
	${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
	Vulkan::Vulkan
	SDL2::SDL2
)