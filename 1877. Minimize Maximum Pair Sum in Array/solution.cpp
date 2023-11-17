#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        /* Makes u top 100% in speed
        i also took top 100% of memory and i only beat 30% with it nice one 
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        */
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n / 2; ++i) {
            int pairSum = nums[i] + nums[n - 1 - i];
            maxSum = std::max(maxSum, pairSum);
        }

        return maxSum;
    }
};