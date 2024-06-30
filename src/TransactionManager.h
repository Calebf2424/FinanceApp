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
    double getSum();
    double getAccountBalance() const;
    double setAccountBalance();

private:
    std::vector<Transaction> transactions;
    double total;
};

#endif
