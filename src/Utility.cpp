// main.cpp
#include <iostream>
#include <limits>
#include "utility.h"

bool isValidInt(int &input, int min, int max) {
    std::cin >> input;
    if (std::cin.fail() || input < min || input > max) {
        std::cin.clear(); // clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        return false;
    }
    return true;
}

// Your main function and other code...
