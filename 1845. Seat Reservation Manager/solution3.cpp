#include <iostream>
#include <vector>
#include "solution.h"
#include <queue>

class SeatManager {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int maxmseat = 0;
    SeatManager(int n) {
    }
    
    int reserve() {
        int top = pq.empty() ? ++maxmseat : pq.top();
        if (!pq.empty()) pq.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};