#include <string>
#include <unordered_set>

class Solution {
public:
    bool isPathCrossing(std::string path) {
        std::unordered_set<std::string> visited;
        int x = 0, y = 0;
        visited.insert("0,0");

        for (char direction : path) {
            switch (direction) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }

            std::string currentPosition = std::to_string(x) + "," + std::to_string(y);
            if (visited.contains(currentPosition)) {
                return true;
            }

            visited.insert(currentPosition);
        }

        return false;
    }
};