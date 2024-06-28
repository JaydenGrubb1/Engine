/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <span>
#include <string_view>

namespace Engine {
	/**
	 * @brief Initialize the engine
	 * @param argc The number of arguments
	 * @param argv The arguments
	 */
	void init(int argc = 0, char** argv = nullptr);

	/**
	 * @brief shutdown the engine
	 */
	void shutdown();

	/**
	 * @brief get the arguments passed to the application
	 * @return A span of arguments
	 */
	std::span<std::string_view> getArgs();
}