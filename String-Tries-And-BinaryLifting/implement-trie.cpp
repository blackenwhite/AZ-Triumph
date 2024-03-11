// LC 208
struct TrieNode{
    unordered_map<int,TrieNode*> mp;
    int cnt = 0;
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++) {
            int c = word[i]-'a';
            if(cur->mp.find(c)==cur->mp.end()){
                cur->mp[c] = new TrieNode();
            }
            cur = cur->mp[c];
            cur->cnt++;
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            int c = word[i]-'a';
            if(cur->mp.find(c)==cur->mp.end()){
                return false;
            }
            cur = cur->mp[c];
        }
        return cur->isEnd==true;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++) {
            int c = prefix[i]-'a';
            if(cur->mp.find(c)==cur->mp.end()) {
                return false;
            }
            cur = cur->mp[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
