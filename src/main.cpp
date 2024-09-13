#include <iostream>

#include "raylib.h"

int main(void) {
    std::cout << "Hello, World!\n";
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);
    return 0;
}