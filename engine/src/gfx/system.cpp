/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <vulkan/vulkan.hpp>

#include <SDL.h>
#include <SDL_vulkan.h>

#include "engine/core/appinfo.h"
#include "engine/core/logging.h"
#include "engine/core/types.h"
#include "engine/gfx/system.h"

static constexpr std::array VALIDATION_LAYERS = {
	"VK_LAYER_KHRONOS_validation"
};

namespace Engine::GFX {
	static vk::Instance s_instance;

	void Init() {
		SDL_InitSubSystem(SDL_INIT_VIDEO);

		u32 api_version = vk::enumerateInstanceVersion();
		if (api_version < VK_API_VERSION_1_2) {
			throw std::runtime_error("Vulkan 1.2 is not supported on this system!");
		}
		// TODO: Configurable API version

		LOG_INFO("Vulkan: API version = {}.{}.{}-{}",
			VK_API_VERSION_MAJOR(api_version),
			VK_API_VERSION_MINOR(api_version),
			VK_API_VERSION_PATCH(api_version),
			VK_API_VERSION_VARIANT(api_version)
		);
		// TODO: Store API version somewhere

		vk::ApplicationInfo app_info(
			AppInfo::Get().name.data(),
			AppInfo::Get().version,
			"Engine",                        // TODO: Add engine name
			VK_MAKE_API_VERSION(0, 1, 0, 0), // TODO: Add engine version
			VK_API_VERSION_1_2                  // TODO: Identify the API version needed
		);
		vk::InstanceCreateInfo create_info(
			{},
			&app_info,
			VALIDATION_LAYERS.size(), VALIDATION_LAYERS.data(),
			0, nullptr
		);
		// TODO: Vulkan extensions

		auto res = vk::createInstance(&create_info, nullptr, &s_instance);
		if (res != vk::Result::eSuccess) {
			throw std::runtime_error("Failed to create Vulkan instance!");
		}
	}

	void Shutdown() {
		s_instance.destroy();
	}
}