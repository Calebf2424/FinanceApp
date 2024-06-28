#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

class Transaction {
 public:
  //user inputted constructor
  Transaction();

  double getAmount() const { return amount; }
  std::string getDesc() const { return desc; }

 private:
  double amount;
  std::string desc;
  void userInput();
};




#endif
