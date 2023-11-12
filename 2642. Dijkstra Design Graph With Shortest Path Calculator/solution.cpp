#include <iostream>
#include <stdlib.h>  
#include <limits.h>
#include <vector>
#include <queue>


class Graph {
public:
    //nodes[0] [(2,3) (4,6)] All edges of 0 to 2 and 4 with cost 3 and 6
    std::vector<std::vector<std::pair<int, int>>> nodes;

    Graph(int n, std::vector<std::vector<int>>& edges) {
        nodes.resize(n);
        for(auto edge : edges) {
            //emplace back better than push back cause push makes copys
            nodes[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }
    
    void addEdge(std::vector<int> edge) {
        nodes[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1,node2);
    }

    struct CompareByCost {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second; // Compare based on the second int in the pair
        }
    };

    int dijkstra(int start, int goal){
        std::vector<int> pathCost(nodes.size(), INT_MAX);
        pathCost[start] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareByCost> frontier;
        frontier.push({start, 0});

        while(!frontier.empty()){        
            int currentNode = frontier.top().first;
            int currentCost = frontier.top().second;

            frontier.pop();

            if(currentNode == goal)
                return currentCost;

            if(currentCost > pathCost[currentNode])
                continue;

            for(auto node : nodes[currentNode]) {
                int neighbor = node.first;
                int neighborCost = node.second;
                int newRouteCost = neighborCost + pathCost[currentNode];

                if (pathCost[neighbor] > newRouteCost) {
                    pathCost[neighbor] = newRouteCost;
                    frontier.push({neighbor, newRouteCost});
                }
            }
        }
        return ((pathCost[goal] == INT_MAX) ? -1 : pathCost[goal]);
    }
};