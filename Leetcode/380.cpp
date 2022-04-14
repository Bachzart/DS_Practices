/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
public:
    
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(indices.count(val)) return false;
        int index = data.size();
        data.push_back(val);
        indices[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(!indices.count(val)) return false;
        int index = indices[val];
        int last = datas.back();
        nums[index] = last;
        indices[last] = index;
        data.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand()%data.size();
        return data[randomIndex];
    }
private:
    vector<int> data;
    unordered_map<int, int> indices;
};