#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

class Solution {
public:
    struct customComparator
    {
        template<typename T, typename U>
        bool operator()(const T& a, const U& b) const { return std::tie(std::get<0>(a), std::get<1>(a)) < std::tie(std::get<0>(b), std::get<1>(b)); }
    };

    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
        //(sum, row, value)
        std::vector<std::tuple<int, int, int>> elements;
        std::vector<int> solution;

        for (size_t i = 0; i < nums.size(); i++){
            for (size_t j = 0; j < nums[i].size(); j++){
                //-i so the customCoparator works like intended sorting by lowest sum and then highest row
                elements.push_back(std::make_tuple(i + j, -i, nums.at(i).at(j)));
            }       
        }

        std::sort(elements.begin(), elements.end(), customComparator());

        for(const auto& element : elements) {
            solution.push_back(std::get<2>(element));
        }

        return solution;
    }
};


/*
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int n = nums.size();
        queue<pair<int, int>> q;
        q.emplace(make_pair(0, 0));
        vector<int> res;

        while(!q.empty())
        {
            pair<int, int> it = q.front();
            q.pop();
            res.emplace_back(nums[it.first][it.second]);

            if(it.second == 0 && it.first < n - 1)
            {
                q.emplace(make_pair(it.first + 1, it.second));
            }

            if(it.second + 1 < nums[it.first].size())
            {
                q.emplace(make_pair(it.first, it.second + 1));
            }
        }

        return res;
    }
};

int n = nums.size(); - Get the number of rows in the 2D vector.

queue<pair<int, int>> q; - Initialize a queue to store pairs of indices. Each pair represents the row and column index of an element in the 2D vector.

q.emplace(make_pair(0, 0)); - Add the first element’s indices (0, 0) to the queue.

vector<int> res; - Initialize an empty vector to store the result.

while(!q.empty()) - Start a loop that continues until the queue is empty.

pair<int, int> it = q.front(); - Get the indices of the next element from the front of the queue.

q.pop(); - Remove the front element from the queue.

res.emplace_back(nums[it.first][it.second]); - Add the value of the current element to the result vector.

if(it.second == 0 && it.first < n - 1) - If the current element is in the first column and not in the last row, add the element below it to the queue.

q.emplace(make_pair(it.first + 1, it.second)); - Add the indices of the element below the current element to the queue.

if(it.second + 1 < nums[it.first].size()) - If there is an element to the right of the current element, add it to the queue.

q.emplace(make_pair(it.first, it.second + 1)); - Add the indices of the element to the right of the current element to the queue.

return res; - After the queue is empty, return the result vector.

Now, let’s run this code with an example:

Consider the 2D vector:

nums = [[1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]]

The order in which the elements are added to the result vector is: 1, 4, 2, 7, 5, 3, 8, 6, 9.

So, the output of the function will be [1, 4, 2, 7, 5, 3, 8, 6, 9]
*/