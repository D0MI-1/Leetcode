#include <iostream>
#include <stdlib.h>  
#include <limits.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int maxStop = -1;

        for (const auto& route : routes) {
            for (int stop : route) {
                maxStop = std::max(maxStop, stop);
            }
        }

        if (maxStop < target) {
            return -1;
        }

        int n = routes.size();
        std::vector<int> minBusesToReach(maxStop + 1, INT_MAX);
        minBusesToReach[source] = 0;
        bool flag = true;

        while(flag){        
            flag = false;
            for(const auto& route : routes){
                int min = n + 1;
                for(int stop : route){
                    min = std::min(min, minBusesToReach[stop]);
                }

                min++;
                for(int stop : route){
                    if (minBusesToReach[stop] > min){
                        minBusesToReach[stop] = min;
                        flag = true;
                    }
                }
            }
        }

        return (minBusesToReach[target] < n + 1) ? minBusesToReach[target] : -1;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};

    int source = 1;
    int target = 6;

    int result = solution.numBusesToDestination(routes, source, target);

    std::cout << "Minimum number of buses to reach the destination: " << result << std::endl;

    return 0;
}