/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <cstdlib>
#include <engine/engine.h>

using namespace Engine;

int main(int argc, char** argv) {
	AppInfo::get().name = "Example";
	AppInfo::get().setVersion(1, 0, 0);

	Engine::init(argc, argv);
	GFX::init();

	GFX::Window window("Example", 800, 600);
	window.setSize(800, 600);
	window.setFullscreen(false);
	window.setResizable(true);

	Engine::shutdown();
	return EXIT_SUCCESS;
}