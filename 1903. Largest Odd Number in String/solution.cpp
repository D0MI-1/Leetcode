#include <string>

class Solution {
public:
    std::string largestOddNumber(std::string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            //subtracting '0' converts the character '0' to the integer 0, '1' to 1
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};