using pii = pair<int,int>;

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

class qNode{
    public:
    int xi = 0;
    int mi = 0;
    int index = 0;

    qNode(){

    }

    qNode(int a, int b, int c){
        xi = a;
        mi = b;
        index = c;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(),nums.end());
        
        vector<qNode>q(m);
        for(int i=0;i<queries.size();i++){
            q[i] = qNode(queries[i][0], queries[i][1], i);
        }

        sort(q.begin(),q.end(), [](qNode const &a, qNode const &b){
            return a.mi<b.mi;
        });
        // for(auto it:q){
        //     cout<<it.mi<<" "<<it.xi<<" " <<it.index<<"\n";
        // }
        BitTrie bt;
        int i=0;
        for(auto it:q){
            int qm = it.mi;
            while(i<n && nums[i]<=qm){
                bt.insert(nums[i]);
                i++;
            }
            if(i==0){
                ans[it.index] = -1;
                continue;
            }
            // do the actual query
            int res = bt.getMaxXor(it.xi);
            ans[it.index] = res;
        }
        return ans;
    }
};
