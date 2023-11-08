#include <iostream>
#include <stdlib.h>  


//Runtime beats 100% but memory is a joke, even copied top 1 solution for memory
//as my last run and it changed nothing
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1){
            return false;
        }
        return (std::max(std::abs(sx - fx), std::abs(sy - fy)) <= t);
    }
};