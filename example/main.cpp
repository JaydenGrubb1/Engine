/*
 * Copyright (c) 2024, Jayden Grubb
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv) {
	std::printf("Hello, World!\n");

	for (int i = 0; i < argc; i++) {
		std::printf("argv[%d] = %s\n", i, argv[i]);
	}

	return EXIT_SUCCESS;
}