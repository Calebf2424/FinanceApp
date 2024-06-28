#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <ctime>

class Transaction {
 public:
    enum class Category {
        Living,
        Leisure,
        Other
    };

  //user inputted constructor
  Transaction() {
    input();
  }

    double getAmount() const { return amount; }
    std::string getDesc() const { return desc; }
    std::time_t getDate() const { return date; }

 private:
  double amount;
  std::string desc;
  std::time_t date;
  Category category;
  void input();
  std::time_t userInputDate();
};




#endif
