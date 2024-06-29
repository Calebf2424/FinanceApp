#include "TransactionFileIO.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void TransactionFileIO::saveToFile(const std::vector<Transaction>& transactions, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << " Could not save data" << std::endl;
        return;
    }

    for (const auto& transaction : transactions) {
        outFile << transaction.getAmount() << "," << transaction.getDesc() << std::endl;
    }

    outFile.close();
}

std::vector<Transaction> TransactionFileIO::loadFromFile(const std::string& filename) {
    std::vector<Transaction> transactions;
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << " No data loaded" << std::endl;
        return {};
    }

    double amount;
    std::string desc;

    while (inFile >> amount) {
        if (inFile.peek() == ',') {
            inFile.ignore();
        }
        std::getline(inFile, desc);
        transactions.emplace_back(amount, desc);
    }

    inFile.close();
    return transactions;
}
