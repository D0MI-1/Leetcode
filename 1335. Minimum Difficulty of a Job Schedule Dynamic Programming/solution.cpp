#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minDifficulty(std::vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d) {
            return -1;
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(d + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= d; ++j) {
                int maxDifficulty = 0;
                
                for (int x = i; x > 0; --x) {
                    maxDifficulty = std::max(maxDifficulty, jobDifficulty[x - 1]);

                    if (dp[x - 1][j - 1] != INT_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[x - 1][j - 1] + maxDifficulty);
                    }
                }
            }
        }

        return dp[n][d] == INT_MAX ? -1 : dp[n][d];

    }
};
