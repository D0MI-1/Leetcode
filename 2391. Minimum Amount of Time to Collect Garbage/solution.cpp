#include <iostream>
#include <vector>

class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
        int M = 0, P = 0, G = 0, totalTime = 0;
        bool Mb = false, Pb = false, Gb = false;

        // Start iterating from the end of the vector
        for (int i = garbage.size() - 1; i >= 0; --i) {
            for (char c : garbage[i]) {
                if (c == 'M') {
                    M += 1;
                    Mb = true;
                } else if (c == 'P') {
                    P += 1;
                    Pb = true;
                } else if (c == 'G') {
                    G += 1;
                    Gb = true;
                }
            }

            if (i > 0 && (Mb || Pb || Gb)) {
                totalTime += travel.at(i - 1) * ((Mb ? 1 : 0) + (Gb ? 1 : 0) + (Pb ? 1 : 0));
            }
        }

        totalTime += M + P + G;

        return totalTime;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    std::vector<std::string> garbage = {"G","P","G","GGP"};
    std::vector<int> travel = {2,4,3};

    int result = solution.garbageCollection(garbage, travel);

    std::cout << "Total time needed: " << result << std::endl;

    return 0;
}
