#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int h1 = 0,h2 = 0;

        for(int num : nums){
            if(num > h1){
                h2 = h1;
                h1 = num;
            } else if(num > h2){
                h2 = num;
            }
        }

        return (h1 - 1) * (h2 - 1);
    }
};