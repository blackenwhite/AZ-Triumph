/*
You are given a 0-indexed integer array nums.

The distinct count of a subarray of nums is defined as:

Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
Return the sum of the squares of distinct counts of all subarrays of nums.

Since the answer may be very large, return it modulo 109 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

#define int long long
const int mod =1e9+7;

struct node{
    int lazy;
    int sumsecond;
    int sumfirst;

    void set(int x){
        lazy = 0;
        sumsecond = (x*x)%mod;
        sumfirst = x%mod;
    }
};

int base[100100];
node t[400400];

void push(int id, int l, int r) {
    if(t[id].lazy){
        t[id].sumsecond += (2*t[id].lazy*t[id].sumfirst)%mod + ((t[id].lazy*t[id].lazy%mod)*(r-l+1))%mod;
        t[id].sumfirst+= t[id].lazy*(r-l+1)%mod;
        t[id].sumsecond%=mod;
        t[id].sumfirst%=mod;
        if(l!=r){
            t[id<<1].lazy += t[id].lazy;
            t[id<<1|1].lazy+= t[id].lazy;
        }
        t[id].lazy = 0;
    }
}

node merge(node a, node b) {
    node ans;
    ans.sumfirst = (a.sumfirst + b.sumfirst)%mod;
    ans.sumsecond = (a.sumsecond + b.sumsecond)%mod;
    ans.lazy = 0;
    return ans;
}

#define mid ((l+r)>>1)

void build(int id, int l, int r) {
    if(l==r) {
        t[id].set(0);
        return;
    }
    build(id<<1,l, mid);
    build(id<<1|1,mid+1, r);
    t[id] = merge(t[id<<1],t[id<<1|1]);
}

void update(int id, int l, int r, int lq, int rq, int x) {
    push(id,l,r);
    if(lq>r||l>rq) return;
    if(lq<=l && r<=rq) {
        t[id].lazy+=x;
        push(id,l,r);
        return;
    }
    update(id<<1, l, mid, lq, rq, x);
    update(id<<1|1, mid+1, r, lq, rq, x);
    t[id] = merge(t[id<<1], t[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq) {
    push(id,l,r);
    if(lq>r || l> rq) {
        node temp;
        temp.set(0);
        return temp;
    }

    if(lq<=l && r<=rq) {
        return t[id];
    }
    return merge(query(id<<1,l,mid,lq,rq), query(id<<1|1, mid+1, r, lq, rq));
}
#undef mid
#undef int

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        build(1,0,n-1);
        map<int,int>last_seen;
        long long ans = 0;

        for(int i=0;i<n;i++) {
            int prev = -1;
            if(last_seen.find(nums[i])!=last_seen.end()){
                prev = last_seen[nums[i]];
            }
            update(1,0,n-1,prev+1,i,1);
            node temp = query(1,0,n-1,0,i);
            ans = (ans+temp.sumsecond)%mod;
            last_seen[nums[i]]=i;
        }
        return ans;
    }
};
