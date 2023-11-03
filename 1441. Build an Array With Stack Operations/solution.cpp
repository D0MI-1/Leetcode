#include <iostream>
#include <vector>
#include "solution.h"

class Solution {

public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> solution;
        int targetIndex = 0;

        //start at 1 because "stream of the integers in the range [1, n]"
        for (size_t i = 1; i <= n; i++)
        {
            //If we should ever get bigger break
            if (targetIndex >= target.size()) {
                break;
            }

            //Always need atleast one Push
            solution.push_back("Push");

            //If the Number is different to our stream then we need to Pop
            //and loop until we find the same i at the index in target and
            //our targetIndex 
            if(target.at(targetIndex) != i){
                solution.push_back("Pop");
            }else{
                targetIndex++;
            }
        }

        return solution;
    }
};