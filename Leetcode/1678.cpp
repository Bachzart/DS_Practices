class Solution {
public:
    string interpret(string command) {
        string ret;
        int i = 0;
        while(i < command.length()) {
            if(command[i] == 'G') {
                ret += "G";
                i++;
            } else if(command[i] == '(' && command[i + 1] == ')') {
                ret += "o";
                i += 2;
            } else {
                ret += "al";
                i += 4;
            }
        }
        return ret;
    }
};