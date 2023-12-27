#include <string>
#include <vector>
#include <limits>

class Solution
{
public:
    int minCost(std::string colors, std::vector<int> &neededTime)
    {
        int n = colors.size();
        int minTotalTime = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            if (colors[i] == colors[i + 1])
            {

                if (neededTime[i + 1] > neededTime[i])
                {
                    minTotalTime += neededTime[i];
                }
                else
                {
                    minTotalTime += neededTime[i + 1];
                    neededTime[i + 1] = neededTime[i];
                }
            }
        }

        return minTotalTime;
    }
};