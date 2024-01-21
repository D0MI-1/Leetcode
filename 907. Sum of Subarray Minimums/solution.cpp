#include <vector>
#include <stack>

const int MOD = 1000000007;

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        std::stack<int> s;
        std::vector<int> left(n), right(n);

        // Calculate the count of previous smaller elements for each element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        // Calculate the count of next smaller elements for each element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        // Calculate the contribution of each element to the result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return static_cast<int>(result);
    }
};
