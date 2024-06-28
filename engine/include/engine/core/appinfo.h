/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <string_view>
#include <tuple>

#include "types.h"

namespace Engine {
	struct AppInfo {
		std::string_view name{};
		u32 version{};

		/**
		 * @brief Set the version of the application
		 * @param major The major version
		 * @param minor The minor version
		 * @param patch The patch version
		 */
		constexpr void SetVersion(u8 major = 1, u8 minor = 0, u8 patch = 0) {
			version = (major << 22) | (minor << 12) | patch;
		}

		/**
		 * @brief Get the version of the application
		 * @return The version of the application
		 */
		[[nodiscard]] constexpr std::tuple<u8, u8, u8> GetVersion() const {
			return std::make_tuple(
				(version >> 22) & 0x3FF,
				(version >> 12) & 0x3FF,
				version & 0xFFF
			);
		}

		/**
		 * @brief Get the application information
		 * @return The application information
		 */
		[[nodiscard]] static AppInfo& Get() {
			static AppInfo info;
			return info;
		}
	};
}