#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

class FoodRatings {
public:
    std::unordered_map<std::string, int> foodToRating;
    std::unordered_map<std::string, std::string> foodToCuisine;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> cuisineToFood;

    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodToRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineToFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(std::string food, int newRating) {
            std::string cuisine = foodToCuisine[food];

        auto oldElementIterator = cuisineToFood[cuisine].find({ -foodToRating[food], food});
        cuisineToFood[cuisine].erase(oldElementIterator);

        foodToRating[food] = newRating;
        cuisineToFood[cuisine].insert({-newRating, food });
    }
    
    std::string highestRated(std::string cuisine) {
        auto highestRated = *cuisineToFood[cuisine].begin();
        return highestRated.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */