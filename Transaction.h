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

  Transaction() {
    input();
  }
  Transaction(double amount, const std::string& desc, std::time_t date, bool isIncome, Category category)
        : amount(amount), desc(desc), date(date), isIncome(isIncome), Category(category) {}

    double getAmount() const { return amount; }
    std::string getDesc() const { return desc; }
    std::time_t getDate() const { return date; }
    bool getIsIncome() const { return isIncome; }

 private:
  double amount;
  std::string desc;
  std::time_t date;
  Category category;
  bool isIncome
  void input();
};












#endif
