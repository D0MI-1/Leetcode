#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<int> dp = {0};  // dp[i] represents the maximum length of unique characters for the first i strings

        for (const std::string& s : arr) {
            int charMask = 0;
            bool hasDuplicate = false;

            for (char c : s) {
                int charBit = 1 << (c - 'a');
                if (charMask & charBit) {
                    hasDuplicate = true;
                    break;
                }
                charMask |= charBit;
            }

            if (hasDuplicate) {
                continue;  // Skip strings with duplicate characters
            }

            for (int i = dp.size() - 1; i >= 0; --i) {
                if ((dp[i] & charMask) == 0) {
                    dp.push_back(dp[i] | charMask);
                }
            }
        }

        int maxLen = 0;
        for (int bitmask : dp) {
            // 123 is 1111011, and __builtin_popcount will return 6 because there are six set bits
            maxLen = std::max(maxLen, __builtin_popcount(bitmask));
        }

        return maxLen;
    }
};


int main() {
    std::vector<std::string> arr1 = {"un", "iq", "ue"};
    std::vector<std::string> arr2 = {"cha", "r", "act", "ers"};

    Solution sol;

    std::cout << "Example 1: " << sol.maxLength(arr1) << std::endl;  // Expected output: 4
    std::cout << "Example 2: " << sol.maxLength(arr2) << std::endl;  // Expected output: 6

    return 0;
}