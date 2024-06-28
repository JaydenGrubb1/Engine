/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <SDL.h>

#include "engine/gfx/window.h"

namespace Engine::GFX {
	Window::Window(std::string_view title, int width, int height) {
		m_window = SDL_CreateWindow(
			title.data(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width, height,
			SDL_WINDOW_VULKAN
		);
	}

	Window::~Window() {
		SDL_DestroyWindow(reinterpret_cast<SDL_Window*>(m_window));
	}

	void Window::setTitle(std::string_view title) {
		SDL_SetWindowTitle(reinterpret_cast<SDL_Window*>(m_window), title.data());
	}

	void Window::setSize(int width, int height) {
		SDL_SetWindowSize(reinterpret_cast<SDL_Window*>(m_window), width, height);
	}

	void Window::setFullscreen(bool fullscreen) {
		SDL_SetWindowFullscreen(
			reinterpret_cast<SDL_Window*>(m_window),
			fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0
		);
	}

	void Window::setResizable(bool resizable) {
		SDL_SetWindowResizable(
			reinterpret_cast<SDL_Window*>(m_window),
			resizable ? SDL_TRUE : SDL_FALSE
		);
	}
}