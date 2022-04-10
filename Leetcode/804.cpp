class Solution {
public:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for(int i = 0; i < words.size(); i++) {
            string tmp = "";
            for(auto ch: words[i]) {
                tmp += morse[ch - 'a'];
            }
            st.insert(tmp);
        }
        return st.size();
    }
};