#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"
#include <vector>

class TransactionManager {
public:
    void addTransaction(const Transaction& transaction);
    void removeTransaction(size_t index);
    void displayTransactions() const;
    int getSum();

private:
    std::vector<Transaction> transactions;
    int sum;
};

#endif
