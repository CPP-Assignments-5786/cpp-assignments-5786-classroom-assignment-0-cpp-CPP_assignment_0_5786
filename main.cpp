#include "Student.hpp"
#include <iostream>

int main() {
    std::cout << "=== Welcome to CPP course! ===" << std::endl;

    std::cout << greet("Avi") << std::endl;
    // Expected output: Welcome to CPP course, Avi!

    std::cout << greet("Erel") << std::endl;
    // Expected output: Welcome to CPP course, Erel!

    return 0;
}
