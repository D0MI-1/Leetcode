#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

class Solution {
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) {
        std::unordered_map<int, std::vector<int>> pairs;

        for (const std::vector<int>& pair : adjacentPairs) {
            pairs[pair[0]].push_back(pair[1]);
            pairs[pair[1]].push_back(pair[0]);
        }

        std::vector<int> solution;

        for (const std::pair<int, std::vector<int>>& pair : pairs) {
            if (pair.second.size() == 1) {
                solution.push_back(pair.first);
                break;
            }
        }

        int start = solution[0];
        int left = solution[0];
        
        for (int i = 1; i < adjacentPairs.size() + 1; ++i) {
            const std::vector<int>& entryVec = pairs[start];
            int next = (entryVec[0] == left) ? entryVec[1] : entryVec[0];
            solution.push_back(next);
            left = start;
            start = next;
        }
        
        return solution;
    }
};