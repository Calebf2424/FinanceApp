#include "TransactionManager.h"
#include <iostream>

void TransactionManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void TransactionManager::removeTransaction(size_t index) {
    if (index < transactions.size()) {
        transactions.erase(transactions.begin() + index);
    } else {
        std::cerr << "Invalid index" << std::endl;
    }
}

void TransactionManager::displayTransactions() const {
    for (size_t i = 0; i < transactions.size(); ++i) {
        const Transaction& t = transactions[i];
        std::cout << "Transaction " << i + 1 << ":\n"
                  << "Amount: " << t.getAmount() << "\n"
                  << "Description: " << t.getDesc() << "\n"
                  << "Date: " << std::put_time(std::localtime(&t.getDate()), "%Y-%m-%d") << "\n"
                  << "Category: " << static_cast<int>(t.getCategory()) << "\n\n";
    }
}
