#include <vector>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        const int MOD = 1000000007;
        int solution = 0;

        for(int i = 0; i < arr.size(); i++){
            if (i == 0){
                solution += arr.size() * arr[i];
                solution %= MOD;
            } else if (i == arr.size() - 1){
                solution += arr.size() * arr[i];
                solution %= MOD;
            } else {
                solution += (arr.size() - i) * arr[i];
                solution %= MOD;
            }
        }

        return solution;
    }
};