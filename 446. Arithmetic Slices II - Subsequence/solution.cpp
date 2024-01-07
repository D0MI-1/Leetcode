#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int count = 0; // Total count of arithmetic subsequences

        // Create a vector of unordered_maps to store the number of subsequences ending at index i with common difference j
        std::vector<std::unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                
                // Update the count and dp array
                int prevCount = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += prevCount + 1; // Increment count for subsequences ending at index i with common difference diff
                count += prevCount; // Update total count
            }
        }

        return count;
    }
};