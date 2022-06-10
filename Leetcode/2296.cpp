/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

/* violent solution, TLE. */
class TextEditor {
    string te;
    int pos;
public:
    TextEditor() : pos(-1){
    }
    
    void addText(string text) {
        if(pos == -1) {
            pos = text.length();
            for(int i = 0; i < te.size(); i++) {
                text.push_back(te[i]);
            }
            te = text;
        } else if(pos == te.length()) {
            te += text;
            pos = te.length();
        } else {
            string tmp = "";
            for(int i = 0; i < pos; i++) {
                tmp.push_back(te[i]);
            }
            tmp += text;
            int t = pos;
            pos = tmp.length();
            while(t < te.length()) {
                tmp.push_back(te[t]);
                t++;
            }
            te = tmp;
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            if(pos > 0) {
                te.erase(te.begin() + pos - 1);
                pos--;
                cnt++;
            } else break;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        string tmp = "";
        pos -= k;
        if(pos < 0) {
            pos = -1;
            return tmp;
        }
        cout << pos << endl;
        int tpos = pos - 1, i = 10;
        while(tpos >= 0 && i > 0) {
            tmp.push_back(te[tpos]);
            tpos--;
            i--;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
    
    string cursorRight(int k) {
        string tmp = "";
        if(pos == -1) pos = k;
        else pos += k;
        if(pos > te.length()) pos = te.length();
        int tpos = pos - 1, i = 10;
        cout << pos << ' ' << tpos << endl;
        while(tpos >= 0 && i > 0) {
            tmp.push_back(te[tpos]);
            tpos--;
            i--;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};

/* violent solution, AC. */
class TextEditor {
public:
    TextEditor() : curpos(0) {}
    
    void addText(string text) {
        te.insert(curpos, text);
        curpos += text.length();
    }
    
    int deleteText(int k) {
        int pos = max(0, curpos - k);
        int num = curpos - pos;
        text.erase(pos, num);
        curpos = pos;
        return num;
    }
    
    string cursorLeft(int k) {
        curpos = max(0, curpos - k);
        int num = min(10, curpos);
        return te.substr(curpos - num, num);
    }
    
    string cursorRight(int k) {
        int len = te.length();
        curpos = min(len, curpos + k);
        int num = min(10, curpos);
        return te.substr(curpos - num, num);
    }
private:
    string te;
    int curpos;
};

/* double linked list */
class TextEditor {
public:
    struct Node {
        char ch;
        Node *pre, *next;
        Node(){}
        Node(char _ch): ch(_ch), pre(nullptr), next(nullptr){}
    };
    Node* insert(Node* pos, Node* node) {
        node->pre = pos;
        node->next = pos->next;
        node->pre->next = node;
        node->next->pre = node;
        return node;
    }
    void remove(Node* pos) {
        pos->pre->next = pos->next;
        pos->next->pre = pos->pre;
    }
    TextEditor() {
        head = new Node();
        head->pre = head->next = head;
        cur = head;
    }
    
    void addText(string text) {
        for(char ch: text) {
            Node *tmp = new Node(ch);
            cur = insert(cur, tmp);
        }
    }
    
    int deleteText(int k) {
        int tmp = k;
        while(k && cur != head) {
            cur = cur->pre;
            remove(cur->next);
            k--;
        }
        return tmp - k;
    }
    string text() {
        Node *p = cur;
        string tmp = "";
        int k = 10;
        while(k && p != head) {
            tmp.push_back(p->ch);
            k--;
            p = p->pre;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }

    string cursorLeft(int k) {
        while(k && cur != head) {
            cur = cur->pre;
            k--;
        }
        return text();
    }
    
    string cursorRight(int k) {
        while(k && cur->next != head) {
            cur = cur->next;
            k--;
        }
        return text();
    }
private:
    Node *cur, *head;
};

/* use list to simulate */
class TextEditor {
private:
    list<char> l;
    list<char>::iterator cur = l.begin();
public:
    TextEditor() {}
    
    void addText(string text) {
        for(char ch: text) {
            l.insert(cur, ch);
        }
    }
    
    int deleteText(int k) {
        int k0 = k;
        for(; k && cur != l.begin(); k--) {
            cur = l.erase(prev(cur));
        }
        return k0 - k;
    }
    string text() {
        string tmp;
        auto it = cur;
        for(int k = 10; k && it != l.begin(); k--) {
            it = prev(it);
            tmp.push_back(*it);
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }

    string cursorLeft(int k) {
        for(; k && cur != l.begin(); k--) {
            cur = prev(cur);
        }
        return text();
    }
    
    string cursorRight(int k) {
        for(; k && cur != l.end(); k--) {
            cur = next(cur);
        }
        return text();
    }
};

/* use two stack to simulate */
class TextEditor {
private:
    stack<char> left, right;
public:
    TextEditor() {}
    
    void addText(string text) {
        for(char ch: text) {
            left.push(ch);
        }
    }
    
    int deleteText(int k) {
        int k0 = k;
        while(k && !left.empty()) {
            left.pop();
            k--;
        }
        return k0 - k;
    }

    string text() {
        int k = 10;
        string tmp;
        while(k && !left.empty()) {
            tmp.push_back(left.top());
            k--;
            left.pop();
        }
        reverse(tmp.begin(), tmp.end());
        for(char &ch: tmp) {
            left.push(ch);
        }
        return tmp;
    }

    string cursorLeft(int k) {
        while(k && !left.empty()) {
            k--;
            right.push(left.top());
            left.pop();
        }
        return text();
    }
    
    string cursorRight(int k) {
        while(k && !right.empty()) {
            k--;
            left.push(right.top());
            right.pop();
        }
        return text();
    }
};

/* use two string to simulate */
class TextEditor {
    string left, right;
public:
    TextEditor() {
        left = right = "";
    }
    
    void addText(string text) {
        left += text;
    }
    
    int deleteText(int k) {
        int k0 = k;
        for(; k && left.length() > 0; k--) {
            left.pop_back();
        }
        return k0 - k;
    }
    
    string cursorLeft(int k) {
        if(left.length() < k) k = left.length();
        for(int i = 0; i < k; i++) {
            right.push_back(left.back());
            left.pop_back();
        }
        string ans(left.end() - min(10, (int)left.length()), left.end());
        return ans;
    }
    
    string cursorRight(int k) {
        if(right.length() < k) k = right.length();
        for(int i = 0; i < k; i++) {
            left.push_back(right.back());
            right.pop_back();
        }
        string ans(left.end() - min(10, (int)left.length()), left.end());
        return ans;
    }
};