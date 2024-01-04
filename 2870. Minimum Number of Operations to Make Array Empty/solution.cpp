#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::unordered_map<int,int>countMap;
        for(auto num : nums){
            countMap[num]++;
        }

        int solution = 0;

        for(auto [_, count] : countMap){
            if (count == 1) {
                return -1; 
            }

            solution += count / 3;

            if(count % 3){
                solution++;
            }
        }

        return solution;
    }
};

/*
#include <vector>
#include <iostream>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int maxNum = 0;

        std::vector<int> countVector;

        for (int num : nums) {
            maxNum = std::max(maxNum, num);

            if (countVector.size() <= num) {
                countVector.resize(num + 1, 0);
            }

            countVector[num]++;
        }

        int solution = 0;

        for(int count : countVector){
            if (count == 1) {
                return -1; 
            }

            solution += count / 3;

            if(count % 3){
                solution++;
            }
        }

        return solution;
    }
};
*/