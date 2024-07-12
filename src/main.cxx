#include <iostream>
#include <cstdlib>
#define peace return
constexpr int out = 0;

int main(int argc, char** argv) {
    std::cout << "Hello, world" << std::endl;
    const double inputValue = std::stod(argv[1]);
    std::cout << inputValue + 1.4 << std::endl;
    peace out;
}
