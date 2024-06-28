#include "Transaction.h"
#include "TransactionManager.h"
#include <iostream>

int main() {
    // Create TransactionManager object
    TransactionManager manager;

    // Add some transactions
    Transaction t1;
    manager.addTransaction(t1);

    Transaction t2;
    manager.addTransaction(t2);

    // Display all transactions
    std::cout << "Displaying all transactions:" << std::endl;
    manager.displayTransactions();

    // Remove a transaction (e.g., the second one)
    std::cout << "\nRemoving transaction at index 1:" << std::endl;
    manager.removeTransaction(1);

    // Display updated transactions
    std::cout << "\nDisplaying updated transactions:" << std::endl;
    manager.displayTransactions();

    // Calculate and display total sum
    int totalSum = manager.getSum();
    std::cout << "\nTotal sum of transactions: " << totalSum << std::endl;

    return 0;
}
