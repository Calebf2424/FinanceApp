#include "TransactionManager.h"
#include "Transaction.h"
#include "TransactionFileIO.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstddef>

void TransactionManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void TransactionManager::removeTransaction(std::size_t index) {
    if (index < transactions.size()) {
        transactions.erase(transactions.begin() + index);
    } else {
        std::cerr << "Invalid index" << std::endl;
    }
}

void TransactionManager::displayTransactions() const {
    for (size_t i = 0; i < transactions.size(); ++i) {
        const Transaction& t = transactions[i];
        std::cout << "\nTransaction " << i + 1 << ":\n"
                  << "Amount: " << t.getAmount() << "\n"
                  << "Description: " << t.getDesc() << std::endl;
    }
}


double TransactionManager::getSum(){
    double total = 0.0;
    for (const Transaction& t : transactions) {
        total += t.getAmount();
    }
    return total;
}

double TransactionManager::getMonthGoal() {
    double goal;
    std::cout << "Enter goal limit for the month :\n";
    std::cin >> goal;
    return goal;
}

const std::vector<Transaction>& TransactionManager::getAllTransactions() const {
    return transactions;
}

void TransactionManager::clearTransactions() {
    transactions.clear();
}
