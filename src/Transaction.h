#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <ctime>

class Transaction {
 public:

  //user inputted constructor
  Transaction();

    double getAmount() const { return amount; }
    std::string getDesc() const { return desc; }
    std::time_t getDate() const { return date; }

 private:
  double amount;
  std::string desc;
  std::time_t date;
  void userInput();
  std::time_t userInputDate();
};




#endif
