/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/* violent solution */
class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(auto &[s, e]: calendar) {
            if(!(start >= e || end <= s)) return false;
        }
        calendar.push_back(make_pair(start, end));
        return true;
    }
private:
    vector<pair<int, int>> calendar; 
};

class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(auto &[s, e]: calendar) {
            if(start < e && end > s) return false;
        }
        calendar.push_back(make_pair(start, end));
        return true;
    }
private:
    vector<pair<int, int>> calendar; 
};

/* set + binary search */
class MyCalendar {
public:
    MyCalendar() {

    }
    bool book(int start, int end) {
        if(calendar.size() == 0) {
            calendar.insert(make_pair(start, end));
            return true;
        } else {
            auto pos = calendar.lower_bound(make_pair(start, 0));
            if(pos == calendar.end()) {
                pos--;
                if(pos->second <= start) {
                    calendar.insert(make_pair(start, end));
                    return true;
                } else return false;
            } else if(pos == calendar.begin()) {
                if(pos->first >= end) {
                    calendar.insert(make_pair(start, end));
                    return true;
                } else return false;
            } else {
                if(pos->first >= end) {
                    pos--;
                    if(pos->second <= start) {
                        calendar.insert(make_pair(start, end));
                        return true;
                    } else return false;
                } else return false;
            }
        }
    }
private:
    set<pair<int, int>> calendar; 
};

class MyCalendar {
public:
    MyCalendar() {

    }
    bool book(int start, int end) {
        if(calendar.size() == 0) {
            calendar.insert({start, end});
            return true;
        } else {
            auto pos = calendar.lower_bound({start, 0});
            if(pos == calendar.end()) {
                pos--;
                if(pos->second <= start) {
                    calendar.insert({start, end});
                    return true;
                } else return false;
            } else if(pos == calendar.begin()) {
                if(pos->first >= end) {
                    calendar.insert({start, end});
                    return true;
                } else return false;
            } else {
                if(pos->first >= end) {
                    pos--;
                    if(pos->second <= start) {
                        calendar.insert({start, end});
                        return true;
                    } else return false;
                } else return false;
            }
        }
    }
private:
    set<pair<int, int>> calendar; 
};

/* map + binary search */
class MyCalendar {
public:
    MyCalendar() {
        calendar[-1] = -1;
    }
    bool book(int start, int end) {
        auto pos = calendar.lower_bound(end);
        if((--pos)->second <= start) {
            calendar[start] = end;
            return true;
        }
        return false;
    }
private:
    map<int, int> calendar;
};