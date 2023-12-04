#include <iostream>
#include <vector>
#include <string>
#include <regex>

class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        std::regex pattern("(\\d)\\1\\1");
        
        std::sregex_iterator iter(num.begin(), num.end(), pattern);
        std::sregex_iterator end;

        std::vector<int> capturedDigits;

        while (iter != end) {
            std::smatch match = *iter;
            int capturedDigit = std::stoi(match[1].str());
            capturedDigits.push_back(capturedDigit);
            ++iter;
        }

        if (!capturedDigits.empty()) {
            int largestDigit = *std::max_element(capturedDigits.begin(), capturedDigits.end());
            return std::to_string(largestDigit) + std::to_string(largestDigit) + std::to_string(largestDigit);
        }

        return "";
    }
};