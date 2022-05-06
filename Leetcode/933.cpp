/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/* method 1: violent solution */
class RecentCounter {
    vector<int> requests;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        requests.push_back(t);
        int size = requests.size(), lower = t - 3000, upper = t, cnt = 1;
        for(int i = 0; i < size - 1; i++) {
            if(lower <= requests[i] && requests[i] <= t) cnt++;
        }
        return cnt;
    }
};

/* method 2: binary search */
class RecentCounter {
    vector<int> requests;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        requests.push_back(t);
        auto pos = lower_bound(requests.begin(), requests.end(), t - 3000);
        return requests.end() - pos;
    }
};

/* method 3: queue */
class RecentCounter {
    queue<int> requests;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        requests.push(t);
        while(!requests.empty()) {
            if(requests.front() < t - 3000) requests.pop();
            else break;
        }
        return requests.size();
    }
};