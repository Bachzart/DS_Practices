/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

class CountIntervals {
    int cnt = 0;
    set<pair<int, int>> st;
public:
    CountIntervals() {

    }
    
    void add(int left, int right) {
        int l = left, r = right;
        auto it = st.lower_bound({left - 1, -2e9});
        while(it != st.end() && it->second <= right) {
            l = min(l, it->second);
            r = max(r, it->first);
            cnt -= it->first - it->second + 1;
            st.erase(it++);
        }
        cnt += r - l + 1;
        st.insert({r, l});
    }
    
    int count() {
        return cnt;
    }
};