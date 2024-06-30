#include <iostream>
#include <fstream>
#include <string>
#include "TransactionManager.h"
#include "Transaction.h"
#include "TransactionFileIO.h"
#includen "Utility.h"

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
                  << "2. Edit Transaction\n"
                  << "3. Delete Transaction\n"
                  << "4. Display Transactions\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        
        while (!isValidInt(choice, 1, 5)) {
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
                //std::size_t index;
                //std::cout << "Enter index of transaction to edit: ";
                //std::cin >> index;
                //manager.editTransaction(index - 1); // Assuming index is 1-based
                break;
            }
            case 3: {
                std::size_t index;
                std::cout << "Enter index of transaction to delete: ";
                std::cin >> index;
                manager.removeTransaction(index - 1); // Assuming index is 1-based
                clearScreen();
                break;
            }
            case 4: {
                manager.displayTransactions();
                std::cout << "Total: " << manager.getSum() << "\n" << std::endl;
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 5);

    // Save transactions back to file before exiting
    const std::vector<Transaction>& allTransactions = manager.getAllTransactions();
    TransactionFileIO::saveToFile(allTransactions, filename);

    return 0;
}
