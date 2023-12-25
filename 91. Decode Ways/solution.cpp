#include <string>
#include <iostream>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int count1 = 1, count2 = 0;
        for (int i = 1; i < s.size(); ++i) {
            int temp = count1;
            
            if (s[i] == '0') {
                count1 = 0;
            } else {
                count1 = count1 + count2;
            }

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                count2 = temp;
            } else {
                count2 = 0;
            }
        }

        return count1 + count2;
    }   
};

int main() {
    Solution solution;

    std::cout << "Test Case 1: " << solution.numDecodings("12") << std::endl; // Output: 2
    std::cout << "Test Case 2: " << solution.numDecodings("226") << std::endl; // Output: 3
    std::cout << "Test Case 3: " << solution.numDecodings("06") << std::endl; // Output: 0
}

/* dp solution
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') dp[i] += dp[i+1];
            if (i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};
*/