#include <vector>  
#include <algorithm>  


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int prev1 = 0;
        int prev2 = 0;

        for (auto const& num : nums) {
            int tmp = prev1;
            prev1 = std::max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};