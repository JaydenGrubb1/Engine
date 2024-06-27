cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

project(Example)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
	-Wall
	-Wextra
	-Wpedantic
	-Wold-style-cast
)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	EngineCore # TODO: Change this once the engine has a proper name
)

if (CMAKE_IMPORT_LIBRARY_SUFFIX)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND_EXPAND_LISTS
	)
endif ()