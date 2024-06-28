#include "Transaction.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

Transaction::Transaction() {
    userInput(); // Call function to handle user input
}

std::time_t Transaction::getUserInputDate() {
    std::tm tm = {};
    std::string dateStr;

    std::cout << "Enter the date (YYYY-MM-DD): ";
    std::getline(std::cin, dateStr);

    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");

    if (ss.fail()) {
        std::cerr << "Failed to parse date. Please use the correct format." << std::endl;
        return std::time(nullptr); // Return current time as a fallback
    }

    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0; // Set time to midnight
    std::time_t date = std::mktime(&tm);
    
    if (date == -1) {
        std::cerr << "Error in converting time." << std::endl;
        return std::time(nullptr); // Return current time as a fallback
    }
    
    return date;
}

void Transaction::userInput() {
      std::cout << "Enter transaction details:" << std::endl;

    // Input amount
    std::cout << "Amount: ";
    std::cin >> amount;

    // Input description
    std::cout << "Description: ";
    std::cin.ignore(); // Ignore newline character left in the stream
    std::getline(std::cin, desc);

    // Input date (assuming current time for simplicity)
    date = getUserInputDate();

    // Input category
    int categoryChoice;
    std::cout << "Category (0: Living, 1: Leisure, 2: Other): ";
    std::cin >> categoryChoice;
    switch (categoryChoice) {
        case 0:
            category = Category::Living;
            break;
        case 1:
            category = Category::Leisure;
            break;
        case 2:
            category = Category::Other;
            break;
        default:
            std::cerr << "Invalid category choice. Defaulting to Other." << std::endl;
            category = Category::Other;
            break;
}
