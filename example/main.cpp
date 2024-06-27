#include <cstdio>
#include <cstdlib>

#include <test.h>

int main(int argc, char **argv) {
	std::printf("Hello, World!\n");

	for (int i = 0; i < argc; i++) {
		std::printf("argv[%d] = %s\n", i, argv[i]);
	}

	auto ret = test(1, 2);
	std::printf("test(1, 2) = %d\n", ret);

	return EXIT_SUCCESS;
}