/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <string_view>

#pragma once

namespace Engine::GFX {
	class Window {
	 public:
		Window(std::string_view title, int width, int height);
		~Window();
		void SetTitle(std::string_view title);
		void SetSize(int width, int height);
		void SetFullscreen(bool fullscreen);
		void SetResizable(bool resizable);
	 private:
		void* m_window;
	};
}