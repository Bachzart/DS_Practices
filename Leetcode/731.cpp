/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

/* violent solution, TLE. */
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        memset(dates, 0, sizeof(dates));
    }
    
    bool book(int start, int end) {
        for(int i = start; i < end; i++) {
            if(dates[i] == 2) return false;
        }
        while(start < end) {
            dates[start]++;
            start++;
        }
        return true;
    }
private:
    int dates[100000005];
};


/* violent solution, use two set to maintain intervals */
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for(auto it = merged_intervals.begin(); it != merged_intervals.end(); it++) {
            if(start < it->second && end > it->first) return false;
        }
        for(auto it = intervals.begin(); it != intervals.end(); it++) {
            if(start < it->second && end > it->first) {
                merged_intervals.insert({max(start, it->first), min(end, it->second)});
            }
        }
        intervals.insert({start, end});
        return true;
    }
private:
    multiset<pair<int, int>> intervals, merged_intervals;
};

/* flag method */
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        records[start]++;
        records[end]--;
        int cnt = 0;
        for(auto &[date, i]: records) {
            cnt += i;
            if(cnt > 2) {
                records[start]--, records[end]++;
                return false;
            }
        }
        return true;
    }
private:
    map<int, int> records;
};