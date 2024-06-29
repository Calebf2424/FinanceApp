#include "Transaction.h"
#include "TransactionManager.h"
#include "TransactionFileIO.h"
#include <iomanip>
#include <sstream>
#include <iostream>

Transaction::Transaction() {
    userInput(); // Call function to handle user input
}

Transaction::Transaction(double amt, const std::string& desc)
        : amount(amt), desc(desc) {}

void Transaction::userInput() {
      std::cout << "Enter transaction details:" << std::endl;

    // Input amount
    std::cout << "Amount: ";
    std::cin >> amount;

    // Input description
    std::cout << "Description: ";
    std::cin.ignore(); // Ignore newline character left in the stream
    std::getline(std::cin, desc);
}
