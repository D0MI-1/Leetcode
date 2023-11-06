#include <iostream>
#include <vector>
#include "solution.h"
#include <set>

class SeatManager {
private:
    std::set<int> seatStatus;
    int currentSeat = 1;

public:
    SeatManager(int n) {

    }
    
    int reserve() {
        int tmpCurrent = currentSeat;
        if (seatStatus.size() > 0){
            tmpCurrent = *seatStatus.begin();
            seatStatus.erase(seatStatus.begin());
            return tmpCurrent;
        }

        currentSeat++;

        return tmpCurrent;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber < currentSeat){
			seatStatus.insert(seatNumber);
        }
    }
};