#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
        std::vector<int>& tmp = piles; 
        int solution = 0;
        auto it = piles.begin();
        auto n = piles.size() / 3;

        std::sort(piles.begin(), piles.end(), std::greater<int>());
        

        for (size_t i = 0; i < n; i++)
        {
            std::advance(it, 2);
            solution += *it;

            // Skip one element (lowest value)
            ++it;
        }
        

        return solution;
    }
};