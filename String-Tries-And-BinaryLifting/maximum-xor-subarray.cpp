struct Node{
    int cnt=0;
    Node* ch[2] = {nullptr};
    int lvl=0;
};

class BitTrie{
    public:
    const int LN = 31;
    Node* root;

    BitTrie() {
        root = new Node();
    }

    void insert(int n) {
        Node* cur = root;
        for(int i=LN-1;i>=0;--i) {
            cur->cnt++;
            cur->lvl = i+1;
            int x = (n&(1<<i))>0?1:0;
            if(cur->ch[x]==nullptr) {
                cur->ch[x] = new Node();
            }
            cur = cur->ch[x];
        }
        cur->cnt++;
        cur->lvl = 0;
    }

    int getMaxXor(int n){
        int ans = 0;
        Node* cur = root;
        for(int i=LN-1;i>=0;i--){
            int x = (n&(1<<i))>0?1:0;
            int want = x^1;
            if(cur->ch[want]!=nullptr){
                ans+=(1<<(i));
                cur = cur->ch[want];
            }else {
                cur = cur->ch[x];
            }
        }
        return ans;
    }


};
