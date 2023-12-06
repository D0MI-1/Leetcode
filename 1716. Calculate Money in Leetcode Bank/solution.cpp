class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int weeks = n / 7;
        int daysAfterWeeks = n % 7;

        for (int i = 0; i < weeks; i++)
        {
            sum += 28 + (7 * i); 
        }
        
        sum += ((daysAfterWeeks * (daysAfterWeeks + 1)) / 2) + (weeks * daysAfterWeeks);

        return sum;
    }
};