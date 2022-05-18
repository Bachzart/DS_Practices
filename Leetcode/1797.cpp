/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

class AuthenticationManager {
    unordered_map<string, int> ht;
    int timetolive;
public:
    AuthenticationManager(int timeToLive) {
        timetolive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        ht[tokenId] = currentTime + timetolive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(ht.count(tokenId) != 0 && ht[tokenId] > currentTime) {
            ht[tokenId] = currentTime + timetolive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto &[_, time]: ht) {
            if(time > currentTime) cnt++;
        }
        return cnt;
    }
};