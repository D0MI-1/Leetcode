#include <string>
#include <vector>
#include <iostream>
#include <limits>

class Solution {
public:
    int getLengthOfOptimalCompression(std::string s, int k) {
        int n = s.size();
        int maxInt = std::numeric_limits<int>::max();

        // returns 1, 2, 3, 4 ... for 0 - 9 , 10 - 99, 100 - 999 , 1000 - 9999 ...
        auto getEncodedLen = [](int count) {
            return count > 1 ? std::to_string(count).size() : 0;
        };

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, maxInt));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                // Case 1: Delete the current character
                if (j > 0)
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);

                // Case 2: Keep the current character
                int count = 0;
                for (int x = i; x >= 1; --x) {
                    if (s[x - 1] == s[i - 1]) {
                        count++;
                    }

                    int encodedLen = 1 + getEncodedLen(count);
                    int del = i - x + 1 - count; // number of different characters in the substring from x to i
                    if (j - del >= 0) {
                        dp[i][j] = std::min(dp[i][j], dp[x - 1][j - del] + encodedLen);
                    }
                }
            }
        }

        int result = dp[n][k];
        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "aaaaaaaaaaa";
    int k = 0;

    int result = solution.getLengthOfOptimalCompression(s, k);
    std::cout << "The length of optimal compression for s = \"" << s << "\", k = " << k << " is: " << result << std::endl;

    return 0;
}
