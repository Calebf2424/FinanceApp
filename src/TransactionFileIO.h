#ifndef TRANSACTIONFILEIO_H
#define TRANSACTIONFILEIO_H
#include "Transaction.h"
#include "TransactionManager.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class TransactionFileIO {
 public:
  static void saveToFile(const std::vector<Transaction>& transactions, const std::string& filename);
  static std::vector<Transaction> loadFromFile(const std::string& filename);
};
#endif
