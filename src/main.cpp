#include <iostream>
#include <fstream>
#include <string>
#include "TransactionManager.h"
#include "Transaction.h"
#include "TransactionFileIO.h"
#include "Utility.h"

// Function to load transactions from a file
void loadTransactionsFromFile(TransactionManager& manager, const std::string& filename) {
    std::vector<Transaction> transactions = TransactionFileIO::loadFromFile(filename);
    for (const auto& transaction : transactions) {
        manager.addTransaction(transaction);
    }
}

void clearScreen() {
    int result = system("cls");
    if (result != 0) {
        std::cerr << "Failed to clear screen using cls." << std::endl;
    }
}

int main() {
    TransactionManager manager;
    const std::string filename = "../data/transactions.txt";

    // Load existing transactions from file
    loadTransactionsFromFile(manager, filename);

    int choice;
    clearScreen();
    std::cout << "Budget Application\n" << std::endl;

    do {
        
        // Display menu
        std::cout << "\nMenu:\n"
                  << "1. Add Transaction\n"
                  << "2. Delete Transaction\n"
                  << "3. Display Transactions\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        
        while (!isValidInt(choice, 1, 4)) {
            std::cout << "Enter your choice: ";
        }
        
        switch (choice) {
            case 1: {
                Transaction transaction;
                manager.addTransaction(transaction);
                clearScreen();
                break;
            }
            case 2: {
                std::size_t index;
                std::cout << "Enter index of transaction to delete: ";
                std::cin >> index;
                manager.removeTransaction(index - 1); // Assuming index is 1-based
                clearScreen();
                break;
            }
            case 3: {
                manager.displayTransactions();
                std::cout << "\nTotal: " << manager.getSum() << "\n" << std::endl;
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 4);

    // Save transactions back to file before exiting
    const std::vector<Transaction>& allTransactions = manager.getAllTransactions();
    TransactionFileIO::saveToFile(allTransactions, filename);

    return 0;
}
