#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int reverseNumber(int num) {
        long long reversed = 0;  

        while (num != 0) {
            int digit = num % 10;               // Get the last digit
            reversed = reversed * 10 + digit;  // Append the digit to the reversed number
            num /= 10;                        // Remove the last digit from the original number
        }

        return reversed;
    }

    int countNicePairs(std::vector<int>& nums) {
        std::unordered_map<int, int> frequencyMap;
        long long result = 0;  

        for (int num : nums) {
            int reversed = reverseNumber(num);
            int diff = num - reversed;

            frequencyMap[diff]++;
        }

        const int MOD = 1e9 + 7;

        for (const auto& entry : frequencyMap) {
            int count = entry.second;

            if (count > 1) {
                result = (result + static_cast<long long>(count) * (count - 1) / 2) % MOD;
            }
        }

        return static_cast<int>(result);  
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {32, 42, 11, 23};

    int result = solution.countNicePairs(nums);

    std::cout << "Result: " << result << std::endl;

    return 0;
}