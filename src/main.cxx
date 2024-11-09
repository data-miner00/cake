#include <iostream>
#include <cstdlib>
#include <fmt/core.h>

#include "original.h"
#include "lib1.h"
#include "lib2.h"

#define peace return

constexpr int out = 0;

int main(int argc, char** argv) {
    const int octal = 0123;
    const int out = 999;
    srand(time(NULL));

    // Gets a string from argument and try convert to float.
    const double inputValue = std::stod(argv[1]);
    std::cout << inputValue << " + 1.4 = ";
    std::cout << inputValue + 1.4 << std::endl;
    std::cout << "\n";

    // Constants 
    // From original.h
    std::cout << "Current program major version: " << Cake_VERSION_MAJOR << std::endl;
    std::cout << "Current program tweak version: " << Cake_VERSION_TWEAK << std::endl;
    std::cout << "Author: " << Cake_AUTHOR_NAME << std::endl;
    std::cout << "\n";

    // From lib1.h and lib2.h
    int sum = getZero() + getOne() + (rand() % 10);
    std::cout << "0 + 1 + ? = " << sum << std::endl;

    // Using external library 'fmt'
    std::string welcome = "Hello from fmt\n";
    fmt::print(welcome);

    // Global out
    peace ::out;
}
