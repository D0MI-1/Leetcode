#include <vector>
#include <iostream>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        std::vector<int> row (mat.size(), 0);
        std::vector<int> col (mat[0].size(), 0);
        int solution {0};

        for (int i = 0; i < mat.size(); ++i){
            for (int j = 0; j < mat[0].size(); ++j){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }

        int result {0};
        for(int i = 0; i < row.size(); ++i){
            if (row[i] == 1){
                for (int j = 0; j < col.size(); ++j){
                    if (col[j] == 1 && mat[i][j] == 1){
                        result++;
                    }
                }
            }
        }

        return result;
    }
};

int main(){
    Solution solution;

    std::vector<std::vector<int>> matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> matrix2 = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};

    std::cout << solution.numSpecial(matrix) << std::endl;
    std::cout << solution.numSpecial(matrix2) << std::endl;

}
