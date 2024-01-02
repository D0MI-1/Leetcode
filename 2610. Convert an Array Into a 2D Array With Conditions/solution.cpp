#include <vector>
#include <array>

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
        std::vector<std::vector<int>> solution;

        const int size = 201;

        std::array<int, size> numsCounter = {0};

        for (int num : nums){
            int index = numsCounter[num];

            if (index == solution.size()) {
                solution.push_back({});
            }

            solution[index].push_back(num);

            numsCounter[num]++;
        }

        return solution;
    }
};

/*

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1);
        
        vector<vector<int>> result;
        for (int num : nums) {
            if (frequency[num] >= result.size()) {
                result.push_back({});
            }
            
            
            result[frequency[num]].push_back(num);
            frequency[num]++;
        }
        
        return result;
    }
};


*/