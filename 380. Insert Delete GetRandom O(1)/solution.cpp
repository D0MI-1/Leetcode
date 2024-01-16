#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (indexMap.find(val) != indexMap.end()) {
            return false; 
        }

        values.push_back(val);
        indexMap[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            return false; 
        }

        int lastElement = values.back();
        int indexToRemove = indexMap[val];
        values[indexToRemove] = lastElement;
        indexMap[lastElement] = indexToRemove;

        values.pop_back();
        indexMap.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }

private:
    std::vector<int> values;
    std::unordered_map<int, int> indexMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*
Using Only a Vector:

Insertion and Removal (average case): Appending to the end of a vector (insert)
    is O(1) on average. However, removing an element from the middle of a vector
    requires shifting elements, making it O(N) on average.
Random Access (getRandom): Accessing elements by index in a vector is O(1).

Using Only a Map:

Insertion and Removal (average case): Insertion and removal in an unordered_map
    is O(1) on average. However, random access (getting a random element) is not
    straightforward since unordered_map doesn't maintain the order of elements.
Random Access (getRandom): Generating a truly random element would require 
    iterating through the entire map or using additional data structures.
*/