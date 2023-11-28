#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfWays(std::string corridor) {
        std::vector<int> positions;

        for(int i = 0; i < corridor.size(); i++){
            if(corridor.at(i) == 'S'){
    	        positions.push_back(i);
            }    
        }

        if(positions.size() % 2 != 0 || positions.size() == 0){
            return 0;
        }

        long long  result = 1;

        for(int i = 2; i < positions.size() - 1; i += 2){
            result = (result * (positions[i] - positions[i - 1])) % MOD;
        }

        return result;
    }
};