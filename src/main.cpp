#include <iostream>
#include <fstream>
#include <string>
#include "TransactionManager.h"
#include "Transaction.h"
#include "TransactionFileIO.h"

// Function to load transactions from a file
void loadTransactionsFromFile(TransactionManager& manager, const std::string& filename) {
    std::vector<Transaction> transactions = TransactionFileIO::loadFromFile(filename);
    for (const auto& transaction : transactions) {
        manager.addTransaction(transaction);
    }
}

int main() {
    TransactionManager manager;
    const std::string filename = "transactions.txt";

    // Load existing transactions from file
    loadTransactionsFromFile(manager, filename);

    int choice;
    do {
        // Display menu
        std::cout << "\nMenu:\n"
                  << "1. Add Transaction\n"
                  << "2. Edit Transaction\n"
                  << "3. Delete Transaction\n"
                  << "4. Display Transactions\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Transaction transaction;
                manager.addTransaction(transaction);
                break;
            }
            case 2: {
                // Implement edit transaction functionality
                break;
            }
            case 3: {
                std::size_t index;
                std::cout << "Enter index of transaction to delete: ";
                std::cin >> index;
                manager.removeTransaction(index - 1); // Assuming index is 1-based
                break;
            }
            case 4: {
                manager.displayTransactions();
                std::cout << "Total: " << manager.getSum() << std::endl;
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
