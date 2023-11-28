#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(), 0);
        int totalSum = 0;
        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++) {
            int leftValue = i * nums[i] - leftSum;
            int rightValue = (totalSum - leftSum - nums[i]) - (nums.size() - i - 1) * nums[i];
            leftSum += nums[i];
            ans[i] = leftValue + rightValue; 
        }

        return ans;
    }
};