#include <string>
#include <vector> 

class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        int amount2 = 0;
        bool mul = true;
        int solution = 0;
        
        for (std::string& floor : bank){
            int amount = 0;

            for (char& c : floor){
                if (c == '1'){
                    amount++;
                }
            }

            if (amount > 0){
                if (mul == true){
                    amount2 = amount;
                    mul = false;
                } else if (mul == false){
                    solution += amount * amount2;
                    amount2 = amount;
                }
            }
        }

        return solution;
    }
};