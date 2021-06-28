#include "..\..\leetcode.h"

class AnimalShelf {
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {

        if (animal[1] == 0) cat.emplace(animal);
        else dog.emplace(animal);
    }
    
    vector<int> dequeueAny() {

        if (dog.empty() && cat.empty()) {
            return { -1, -1 };
        }

        vector<int> res;
        if (dog.empty()) {
            res = cat.front();
            cat.pop();
        }
        else if (cat.empty()) {
            res = dog.front();
            dog.pop();
        }
        else if (cat.front()[0] < dog.front()[0]) {
            res = cat.front();
            cat.pop();
        }
        else {
            res = dog.front();
            dog.pop();
        }
        return res;
    }
    
    vector<int> dequeueDog() {

        if (dog.empty()) return { -1, -1 };

        vector<int> res = dog.front();
        dog.pop();
        return res;
    }
    
    vector<int> dequeueCat() {

        if (cat.empty()) return { -1, -1 };

        vector<int> res = cat.front();
        cat.pop();
        return res;
    }

private:
    queue<vector<int>> cat;
    queue<vector<int>> dog;
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */