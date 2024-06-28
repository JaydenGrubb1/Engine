/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <format>
#include <iostream>

namespace Engine::Log {
	template<typename ...Args>
	inline void info(const std::format_string<Args...> fmt, Args&& ...args) {
		std::cout << std::format(fmt, std::forward<Args>(args)...) << std::endl;
	}

	template<typename ...Args>
	inline void error(const std::format_string<Args...> fmt, Args&& ...args) {
		std::cerr << std::format(fmt, std::forward<Args>(args)...) << std::endl;
	}
}

#ifndef NDEBUG
#define LOG_INFO(...) Engine::Log::info(__VA_ARGS__)
#define LOG_ERROR(...) Engine::Log::error(__VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOG_ERROR(...)
#endif