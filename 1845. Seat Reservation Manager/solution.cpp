#include <iostream>
#include <vector>
#include "solution.h"
#include <set>


class SeatManager {
private:
    std::set<int> seatStatus;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
        {
            seatStatus.insert(i);
        }
            
    }
    
    int reserve() {
        int seatNumber = *seatStatus.begin();
        seatStatus.erase(seatNumber);
        
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        seatStatus.insert(seatNumber);
    }
};

int main(){
    SeatManager manager(5);

    std::cout << "1" << std::endl;
    manager.reserve();

    std::cout << "2" << std::endl;
    manager.reserve();
    
    std::cout << "un 2" << std::endl;
    manager.unreserve(2);

    std::cout << "2" << std::endl;
    manager.reserve();
    std::cout << "3" << std::endl;
    manager.reserve();
    std::cout << "4" << std::endl;
    manager.reserve();
    std::cout << "5" << std::endl;
    manager.reserve();
    std::cout << "un 5" << std::endl;
    manager.unreserve(5);

    return 0;
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */