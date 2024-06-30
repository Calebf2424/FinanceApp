#ifndef UTILS_H
#define UTILS_H

bool isValidInt(int &input, int min, int max);
bool isValidDouble(const std::string& str) {
    std::istringstream iss(str);
    double d;
    char c;
    // Try to parse the string as a double and ensure there are no extra characters
    return iss >> d && !(iss >> c);
}

#endif // UTILS_H
