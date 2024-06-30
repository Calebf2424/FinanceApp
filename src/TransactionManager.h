#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"
#include <vector>
#include <cstddef>

class TransactionManager {
public:
    void addTransaction(const Transaction& transaction);
    void removeTransaction(std::size_t index);
    void displayTransactions() const;
    void editTransaction(std::size_t index);
    double getSum();
    const std::vector<Transaction>& getAllTransactions() const;

private:
    std::vector<Transaction> transactions;
    double total;
};

#endif
