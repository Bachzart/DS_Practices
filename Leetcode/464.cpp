/* dfs + violent solution, tle */
class Solution {
public:
    bool dfs(unordered_set<int>& chooseable, int sum, int maxChoosableInteger, int desiredTotal) {
        for(int x: chooseable) {
            if(sum + x >= desiredTotal) return true;
            unordered_set<int> chooseable_copy = chooseable;
            chooseable_copy.erase(x);
            if(!dfs(chooseable_copy, sum + x, maxChoosableInteger, desiredTotal)) return true;
        }
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        unordered_set<int> chooseable;
        for(int i = 1; i <= maxChoosableInteger; i++) {
            chooseable.insert(i);
        }
        return dfs(chooseable, 0, maxChoosableInteger, desiredTotal);
    }
};

/* dfs + violent solution + optimize, tle */
class Solution {
public:
    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
        for(int x = 1; x <= maxChoosableInteger; x++) {
            if((1 << x) & state) continue;
            if(sum + x >= desiredTotal) return true;
            if(!dfs((1 << x) | state, sum + x, maxChoosableInteger, desiredTotal)) return true;
        }
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
};

/* dfs + violent solution + mnemonic search, but can not accpet. */
class Solution {
public:
    int vis[1 << 21];
    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
        if(vis[state] == 1) return true;
        if(vis[state] == 2) return false;
        for(int x = 1; x <= maxChoosableInteger; x++) {
            if((1 << x) & state) continue;
            if(sum + x >= desiredTotal) {
                vis[state] = 1;
                return true;
            }
            if(!dfs((1 << x) | state, sum + x, maxChoosableInteger, desiredTotal)) {
                vis[state] = 1;
                return true;
            }
        }
        vis[state] = 2;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
};

/* dfs + violent solution + mnemonic search + optimize, accept. */
class Solution {
public:
    int vis[1 << 21];
    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
        if(vis[state] == 1) return true;
        if(vis[state] == 2) return false;
        for(int x = 1; x <= maxChoosableInteger; x++) {
            if((1 << x) & state) continue;
            if(sum + x >= desiredTotal) {
                vis[state] = 1;
                return true;
            }
            if(!dfs((1 << x) | state, sum + x, maxChoosableInteger, desiredTotal)) {
                vis[state] = 1;
                return true;
            }
        }
        vis[state] = 2;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
};