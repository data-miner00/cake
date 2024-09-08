#include <iostream>
#include <cstdlib>
#include <fmt/core.h>

#include "bubble_sort.h"
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
    number_t sum = getZero() + getOne() + (rand() % 10);
    std::cout << "0 + 1 + ? = " << sum << std::endl;

    // Using external library 'fmt'
    text_t welcome = "Hello from fmt\n";
    fmt::print(welcome);

    // Sorting array
    int array[] = { 83, 123, 4, 45, 8, 2, 95, 18, 54 };
    bubble_sort(array, sizeof(array)/sizeof(int));

    for (auto element : array) {
         std::cout << element << ' ';
    }

    std::cout << '\n';

    // Pointers
    text_t* addr = &welcome;
    text_t* invalid = nullptr;

    // Heap alloc
    int* persist = new int;
    *persist = 33;
    delete persist;

    // template usage
    std::cout << getSelf(53) << '\n';

    int int_default {};
    std::cout << int_default << '\n';

    int brance_init(500);
    std::cout << brance_init << '\n';

    // Global out
    peace ::out;
}
