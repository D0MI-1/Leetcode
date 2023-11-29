#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //Check if n == 0   -> yes return 0
        //                  -> no check if LSB in n is 1
        //                        -> e.g.  n = 1110 & 0001 => 0
        //                        -> then add 1 or 0 to the hammingWeight and shift n to right by one bit n = 111
        return n == 0 ? 0 : (n & 1) + hammingWeight(n >> 1);
    }
};