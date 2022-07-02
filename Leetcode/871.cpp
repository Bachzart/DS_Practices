/* method 1: Greedy */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ret = 0, n = stations.size();
        int pre = 0, tank = startFuel;
        priority_queue<int> heap;
        for(int i = 0; i <= n; i++) {
            int cur = i < n ? stations[i][0] : target;
            tank -= cur - pre;
            cout << tank << ' ' << cur << ' ' << pre << heap.size() << endl;
            while(tank < 0 && !heap.empty()) {
                tank += heap.top();
                heap.pop();
                ret++;
            }
            if(tank < 0) return -1;
            if(i < n) {
                heap.push(stations[i][1]);
                pre = cur;
            }
        }
        return ret;
    }
};