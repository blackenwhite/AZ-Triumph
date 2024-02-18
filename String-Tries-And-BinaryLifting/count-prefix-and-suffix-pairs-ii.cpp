    struct TrieNode {
        unordered_map<int, TrieNode*> next;
        int count = 0;
    };

    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        long long res = 0;
        for (const string& w : words) {
            TrieNode* x = root;
            for (int i = 0, n = w.size(); i < n; ++i) {
                x = x->next.insert({w[i] * 128 + w[n - 1 - i], new TrieNode()}).first->second;
                res += x->count;
            }
            x->count++;
        }

        return res;
    }
