#include <string>

class Solution {
public:
    int minOperations(std::string s) {
        int zeroOne = 0;
        int oneZero = 0;
        int position = 0;

        for(char c : s){
            if(position % 2 == 0){
                if(c == '0'){
                    oneZero++;
                } else {
                    zeroOne++;
                }
            } else {
                if(c == '0'){
                    zeroOne++;
                } else {
                    oneZero++;
                }
            }
            position++;
        }

        return std::min(zeroOne, oneZero);
    }
};