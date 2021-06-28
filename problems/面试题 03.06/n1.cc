#include "..\..\leetcode.h"

class AnimalShelf {
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {

        if (animal[1] == 0) cats.emplace(animal[0]);
        else dogs.emplace(animal[0]);
    }
    
    vector<int> dequeueAny() {
        
        if (cats.empty() && dogs.empty()) return {-1, -1};

        vector<int> res;
        if (cats.empty()) {
            res = {dogs.front(), 1}; dogs.pop();
        }
        else if (dogs.empty()) {
            res = {cats.front(), 0}; cats.pop();
        }
        else if (cats.front() < dogs.front()) {
            res = {cats.front(), 0}; cats.pop();
        }
        else {
            res = {dogs.front(), 1}; dogs.pop();
        }
        return res;
    }
    
    vector<int> dequeueDog() {

        if (dogs.empty()) return {-1, -1};

        vector<int> res{dogs.front(), 1}; dogs.pop();
        return res;
    }
    
    vector<int> dequeueCat() {

        if (cats.empty()) return {-1, -1};

        vector<int> res{cats.front(), 0}; cats.pop();
        return res;
    }

private:
    queue<int> cats;
    queue<int> dogs;
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */