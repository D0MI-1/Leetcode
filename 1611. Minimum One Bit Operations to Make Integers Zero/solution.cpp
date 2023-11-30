#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1) return n;
        int count = 0;
        while ((1<<count) <= n) count++;
        return ((1<<count)-1) - minimumOneBitOperations(n-(1<<(count-1)));
    }
};
//(1 << count) - 1: This part calculates a number with all bits set to 1 up to the position of the MSB. For example, if the MSB is at position 3, it calculates 111 in binary, which is (2^3 - 1).
//n - (1 << (count - 1)): This part subtracts the value of the MSB from n. This effectively removes the leftmost set bit and keeps the rest of the bits.