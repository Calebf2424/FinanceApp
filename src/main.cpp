#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
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
    time_t t = time(0);
    struct tm *now = localtime(&t);
    
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    int daysInMonth = getDaysInMonth(month, year);
    int remainingDays = daysInMonth - day + 1;

    int choice;
    clearScreen();
    std::cout << "Budget Application\n" << std::endl;

    double goal = manager.getMonthGoal();

    do {
        
        // Display menu
        std::cout << "\nMenu:\n"
                  << "1. Add Transaction\n"
                  << "2. Delete specific Transaction\n"
                  << "3. Delete all Transactions\n"
                  << "4. Display all Transactions\n"
                  << "5. Clear the display\n"
                  << "6. Save and exit the application\n"
                  << "Enter your choice: ";
        
        while (!isValidInt(choice, 1, 6)) {
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
                manager.clearTransactions();
                std::cout << "Deleted all transactions:\n";
                break;
            }
            case 4: {
                manager.displayTransactions();
                std::cout << "\nTotal: " << manager.getSum() << "\n" << std::endl;
                double diff = goal - manager.getSum();
                if (diff > 0){
                    int remaining = diff / remainingDays;
                    std::cout << "\nRemaining in budget:" << diff << "\n" << std::endl;
                    std::cout << "You can spend " << remaining << " per day for the remainder of the month\n" << std::endl;
                }
                else {
                    std::cout << "\nYou are over budget by " << abs(diff) <<"\n" << std::endl;
                }
                break;
            }
            case 5: {
                clearScreen();
                break;
            }
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 6);

    // Save transactions back to file before exiting
    const std::vector<Transaction>& allTransactions = manager.getAllTransactions();
    TransactionFileIO::saveToFile(allTransactions, filename);

    return 0;
}
