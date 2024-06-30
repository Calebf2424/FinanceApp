#include <iostream>
#include <limits>
#include <ctime>
#include "Utility.h"

bool isValidInt(int &input, int min, int max) {
    std::cin >> input;
    if (std::cin.fail() || input < min || input > max) {
        std::cin.clear(); // clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a valid number:" << ".\n";
        return false;
    }
    return true;
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        // Check if the year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}
