#include "Transaction.h"
#include "TransactionManager.h"
#include <iomanip>
#include <sstream>
#include <iostream>

Transaction::Transaction() {
    userInput(); // Call function to handle user input
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
}
