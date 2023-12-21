#include <vector>
#include <limits>
#include <climits>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {
        int l1 = INT_MAX, l2 = std::numeric_limits<int>::max();;

        for(int num : prices){
            if(num < l1){
                l2 = l1;
                l1 = num;
            } else if(num < l2){
                l2 = num;
            }
        }

        if(l1 + l2 > money)
            return money;

        return money - (l1 + l2);
    }
};