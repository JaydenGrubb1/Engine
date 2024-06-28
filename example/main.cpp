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
	AppInfo::Get().name = "Example";
	AppInfo::Get().SetVersion(1, 0, 0);

	Engine::Init(argc, argv);
	GFX::Init();

	GFX::Window window("Example", 800, 600);

	Engine::Shutdown();
	return EXIT_SUCCESS;
}