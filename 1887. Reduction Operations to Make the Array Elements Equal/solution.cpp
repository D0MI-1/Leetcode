#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    struct greater
    {
        template<class T>
        bool operator()(T const &a, T const &b) const { return a > b; }
    };

    int reductionOperations(std::vector<int>& nums) {
        int operations{0};

        std::sort(nums.begin(), nums.end(), greater());

        for (size_t i = 1; i < nums.size(); i++){   
            if (nums.at(i) < nums.at(i - 1)) {
               operations += i; 
            }
        }
        
        return operations;
    }
};