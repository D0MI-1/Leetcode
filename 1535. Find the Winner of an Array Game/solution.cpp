#include <iostream>
#include <vector>
#include "solution.h"

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) {
        int wins = 0;
        int winner = arr.at(0);
        
        for (size_t i = 1; i < arr.size(); i++)
        {
            if(winner > arr.at(i)){
                wins++;
                if(wins == k) 
                    return winner;
            }else{
                winner = arr.at(i);
                wins = 1;
            }
        }
        return winner;
    }
};