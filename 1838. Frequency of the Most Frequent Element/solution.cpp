#include <iostream>
#include <vector>

//Adding this speeds everything up and lets u beat 100% xd 



class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        long int j = 0, sum = 0, maxFrequency = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while((i - j + 1) * nums[i] - sum > k){
                sum -= nums[j];
                j++;
            }

            maxFrequency = std::max(maxFrequency, i - j + 1);
        }

        return maxFrequency;
    }
};

/*
we have the window between j and i 
i - j + 1 returns the current Window length plus 1 because we start at 0 

[1,1,4, ...] k = 2

i = 2 
j = 0

2 - 0 + 1 = 3 
3 * 4 = 12 
12 - 6 = 6 > 2 

sum(6) = sum - nums[j] = 5 
j = 1

2 - 1 + 1 = 2 Window length 
2 * 4 = 8 
8 - 5 = 3 
3 > 2 

sum(5) = sum - nums[j] = 4 
j = 2
*/

/* 
Best memory was worse than mine 
______________________________________________________________________________________________________________________________
best run time submission 
seems like only the stuff before the method speed things up 


//m1
//without binary search overhead.


//Thinking Process

//[A] brute-force method for a fixed number:
//1. for a fixed number
//2. sort the whole array.
//3. increase each neighboring numbers forwards, and use all k.
//4. O(n^2)

//[B] can we speed up?
//1. we can get the the range sum of increase needed for a fixed number by variant prefix sum, called "prefix deficit".

//[C] Monotonic Deficit Triangle.
//1. so we can use two pointer / sliding window by the montonic triangle.

//[D] Summary
//1. instead of sort + binary searches in method 0,
//2. still O(nlogn) but without binary search overhead.

#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());


        int max_freq = 0;
        long long deficit = 0;
        //[j, i-1] applied with the increment operations.
        //so [j, i] good, 
        int j = 0;
        for(int i=0;i<n;i++){
            if(i-1>=0){
                long long height_diff = nums[i] - nums[i-1];
                long long len = (i-1) - (j-1);
                assert(len >= 1);
                deficit += height_diff * len;
            }

            while(j<n && deficit > k){
                deficit -= (long long)nums[i] - (long long)nums[j];

                j++;
            }

            max_freq = max(
                max_freq,
                i - (j-1)
            );
        }

        return max_freq;
    }
};

*/