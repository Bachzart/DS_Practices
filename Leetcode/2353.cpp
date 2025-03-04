/* 
method 1: violent solution, TLE

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings): Foods(foods), Cuisines(cuisines), Ratings(ratings) {
        n = Foods.size();
    }
    
    void changeRating(string food, int newRating) {
        int idx = 0;
        for(; idx < n; ++idx) 
            if(Foods[idx] == food) break;
        if(idx < n) Ratings[idx] = newRating;
    }
    
    string highestRated(string cuisine) {
        int i, topscore;
        for(i = 0; i < n; ++i)
            if(Cuisines[i] == cuisine) {
                topscore = Ratings[i];
                break;
            }
        for(; i < n; ++i)
            if(Cuisines[i] == cuisine && Ratings[i] > topscore) 
                topscore = Ratings[i];
        set<string> tmp;
        for(int i = 0; i < n; ++i) {
            if(Cuisines[i] == cuisine && Ratings[i] == topscore) 
                tmp.insert(Foods[i]);
        }
        return *tmp.begin();
    }
private:
    vector<string> Foods;
    vector<string> Cuisines;
    int n;
    vector<int> Ratings;
};

/*
// method 2: use map and set

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for(int i = 0; i < n; ++i) {
            auto &food = foods[i], &cuisine = cuisines[i];
            int rating = ratings[i];
            foodMap[food] = {rating, cuisine};
            ratingMap[cuisine].emplace(n - rating, food);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[rating, cuisine] = foodMap[food];
        auto &s = ratingMap[cuisine];
        s.erase({n - rating, food});
        s.insert({n - newRating, food});
        rating = newRating;
    }
    
    string highestRated(string cuisine) {
        return ratingMap[cuisine].begin()->second;
    }
private:
    unordered_map<string, pair<int, string>> foodMap;
    unordered_map<string, set<pair<int, string>>> ratingMap;
    int n;
};

*/

/*
method 3: use heap
*/
class FoodRatings {
private:
    unordered_map<string, pair<int, string>> foodMap;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>>> ratingMap;
    int n;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for(int i = 0; i < n; ++i) {
            auto &food = foods[i], &cuisine = cuisines[i];
            int rating = ratings[i];
            foodMap[food] = {rating, cuisine};
            ratingMap[cuisine].emplace(n - rating, food);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[rating, cuisine] = foodMap[food];
        ratingMap[cuisine].emplace(n - rating, food);
        rating = newRating;
    }
    
    string highestRated(string cuisine) {
        auto &q = ratingMap[cuisine];
        auto &[rating, food] = q.top();
        while(n - rating != foodMap[food].first)
            q.pop();
        return q.pop().second();
    }
};