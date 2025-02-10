#include "application.h"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main(void) {
    Application application{};
    try {
        application.run();
    }
    catch (std::exception &exception) {
        std::cerr << exception.what() << '\n';

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}