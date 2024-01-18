class Solution {
public:
    int climbStairs(int n) {
        int ways = 1;

        for (int i = 1; i <= n / 2; i++) {
            double sum = 1;

            for (int j = i; j < 2 * i; j++) {
                sum *= (double)(n - j) / (j - i + 1);
            }

            ways +=sum;
        }

        return ways;
    }
};

/*
class Solution {
public:

    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int c = 0;
        
        for(int i = 0; i < n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
*/