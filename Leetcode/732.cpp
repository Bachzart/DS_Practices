/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

/* flag method: difference thought. */
class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        dates[start]++;
        dates[end]--;
        int ans = 0, cur = 0;
        for(auto &[_, cnt]: dates) {
            cur += cnt;
            ans = max(cur, ans);
        }
        return ans;
    }
private:
    map<int, int> dates;
};

/* segment tree, next time. */
