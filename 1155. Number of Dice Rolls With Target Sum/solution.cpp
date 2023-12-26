#include <vector>
#include <iostream>

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        // dp[i][j]: number of ways to get sum j using i dice
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));

        // Base case: one die
        for (int face = 1; face <= k && face <= target; ++face) {
            dp[1][face] = 1;
        }

        // Fill the dp table
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int face = 1; face <= k && face < j; ++face) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::cout << sol.numRollsToTarget(1, 6, 3) << std::endl;  // Expected output: 1

    // Test Case 2
    std::cout << sol.numRollsToTarget(2, 6, 7) << std::endl;  // Expected output: 6

    // Test Case 3
    std::cout << sol.numRollsToTarget(30, 30, 500) << std::endl;  // Expected output: 222616187
}