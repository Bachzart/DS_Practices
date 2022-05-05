/* method 1: simulation + queue */
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> players;
        for(int i = 1; i <= n; i++) {
            players.push(i);
        }
        int tmp;
        while(players.size() != 1) {
            for(int i = 0; i < k; i++) {
                tmp = players.front(); players.pop();
                if(i != k - 1) players.push(tmp);
            }
        }
        return players.front();
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> players;
        for(int i = 1; i <= n; i++) {
            players.push(i);
        }
        int tmp;
        while(players.size() != 1) {
            for(int i = 1; i < k; i++) {
                players.push(players.front());
                players.pop();
            }
            q.pop();
        }
        return players.front();
    }
};

/* method 2: recursion + math */
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) return 1;
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }
};

/* method 3: iteration + math */
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for(int i = 2; i <= n; i++) {
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }
};