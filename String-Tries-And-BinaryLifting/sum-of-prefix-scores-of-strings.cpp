// LC 2416

struct TrieNode{
    unordered_map<int,TrieNode*> mp;
    int cnt=0;
};
class Trie{
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string s){
        int n = s.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            int c = s[i]-'a';
            if(cur->mp.find(c)==cur->mp.end()){
                cur->mp[c] = new TrieNode();
            }
            cur = cur->mp[c];
            cur->cnt++;
        }
    }

    int getScore(string& s){
        int n = s.size();
        int ans = 0;
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            int c = s[i]-'a';
            cur = cur->mp[c];
            ans+=cur->cnt;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        Trie trie;
        for(string s:words){
            trie.insert(s);
        }

        for(string s:words){
            int temp = trie.getScore(s);
            ans.push_back(temp);
        }
        return ans;
    }
};
