#include <vector>
#include <limits>
#include <climits>

class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        int h1 = 0,h2 = 0, l1 = INT_MAX, l2 = std::numeric_limits<int>::max();;

        for(int num : nums){
            if(num > h1){
                h2 = h1;
                h1 = num;
            } else if(num > h2){
                h2 = num;
            }

            if(num < l1){
                l2 = l1;
                l1 = num;
            } else if(num < l2){
                l2 = num;
            }
        }

        return (h1 * h2) - (l1 * l2);
    }
};

//1464 Maximum Product of Two Elements in an Array