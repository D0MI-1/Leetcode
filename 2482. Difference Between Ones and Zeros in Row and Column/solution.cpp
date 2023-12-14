#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) {
        std::vector<int> rowOnes (grid.size(), 0);
        std::vector<int> rowZeros (grid.size(), 0);

        std::vector<int> colOnes (grid[0].size(), 0);   
        std::vector<int> colZeros (grid[0].size(), 0);   

        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    rowOnes[i]++;
                    colOnes[j]++;   
                }else{
                    rowZeros[i]++;
                    colZeros[j]++; 
                }

            }
        }

        std::vector<std::vector<int>> diff(grid.size(), std::vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                diff[i][j] = rowOnes[i] + colOnes[j] - rowZeros[i] - colZeros[j]; 
            }
        }

        return diff;
    }
};