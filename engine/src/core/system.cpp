/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <stdexcept>
#include <string_view>
#include <vector>

#include <SDL.h>

#include "engine/core/system.h"

namespace Engine {
	static std::vector<std::string_view> s_args;

	void init(int argc, char** argv) {
		s_args = std::vector<std::string_view>(argv, argv + argc);

		// TODO: Check does this even need to be done?
		if (SDL_Init(0) != 0) {
			throw std::runtime_error("Failed to initialize SDL");
		}
	}

	void shutdown() {
		SDL_Quit();
	}

	std::span<std::string_view> getArgs() {
		return s_args;
	}
}