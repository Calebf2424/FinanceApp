#include "Transaction.h"
#include "TransactionManager.h"
#include "TransactionFileIO.h"
#include "Utility.h"
#include <iomanip>
#include <climits>
#include <sstream>
#include <iostream>

Transaction::Transaction() {
    userInput(); // Call function to handle user input
}

Transaction::Transaction(double amount, const std::string& desc)
        : amount(amount), desc(desc) {}

void Transaction::userInput() {
      std::cout << "Enter transaction details:" << std::endl;

    // Input amount
    std::cout << "Amount: ";
    int choice;
    while (!isValidInt(choice, 0, INT_MAX)) {
            std::cout << "Enter your choice: ";
        }

    // Input description
    std::cout << "Description: ";
    std::cin.ignore(); // Ignore newline character left in the stream
    std::getline(std::cin, desc);
}
