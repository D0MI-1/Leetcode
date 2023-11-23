#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

class Solution {
public:
    bool isArithmetic(const std::vector<int>& nums, int left, int right) {
        int subVectorSize = right - left + 1;
        
        if (subVectorSize < 2) 
            return false;
        
        std::vector<int> subVector(nums.begin() + left, nums.begin() + right + 1);

        std::sort(subVector.begin(), subVector.end());

        int commonDif = subVector.at(1) - subVector.at(0);

        for (int i = 2; i < subVectorSize; ++i) {
            if (subVector[i] - subVector[i - 1] != commonDif) {
                return false;
            }
        }

        return true;
    }

    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        std::vector<bool> solution;
        solution.reserve(l.size());

        for (size_t i = 0; i < l.size(); i++){
            solution.push_back(isArithmetic(nums, l.at(i), r.at(i)));
        }

        return solution;   
    }
};