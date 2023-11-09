#include <iostream>
#include <vector>
#include <cmath>

// 1 + 2 + ... + n 
// = n * (n + 1) / 2
class Solution {
public:
    int countHomogenous(std::string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        int counter = 0;
        long long solution = 0;
        char lastChar;
        
        for (std::string::iterator it=s.begin(); it!=s.end(); ++it){
            if(counter == 0){
                counter++;
                lastChar = *it;
            }else{
                if (lastChar == *it){
                    counter++;
                }else{
                    solution += ((long long)counter * (counter +1)) / 2;
                    counter = 1;
                    lastChar = *it;
                }
            }
        }
        solution += ((long long)counter * (counter + 1)) / 2;

        return solution % 1000000007;
    }
};