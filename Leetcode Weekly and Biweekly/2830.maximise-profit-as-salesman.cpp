/*
You are given an integer n representing the number of houses on a number line, numbered from 0 to n - 1.

Additionally, you are given a 2D integer array offers where offers[i] = [starti, endi, goldi], indicating that ith buyer wants to buy all the houses from starti to endi for goldi amount of gold.

As a salesman, your goal is to maximize your earnings by strategically selecting and selling houses to buyers.

Return the maximum amount of gold you can earn.

Note that different buyers can't buy the same house, and some houses may remain unsold.
*/

class Solution {
public:
    vector<int>dp;
    
    void print(vector<vector<int>>&v){
        cout<<"printing vector\n";
        for(auto it:v){
            cout<<"["<<it[0]<<","<<it[1]<<","<<it[2]<<"] ";
        }
        cout<<"\n";
    }
    
    int find_next_ind(vector<vector<int>>&v, int x, int i){
        int lo=i+1;
        int hi = v.size()-1;
        int ans = v.size();
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(v[mid][0]>x) {
                ans = mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
    
    int rec(vector<vector<int>>&v, int ind, int n){
        int m = v.size();
        if(ind>=m) {
            return 0;
        }

        if(dp[ind]!=-1) return dp[ind];
        // takes
        int take = 0, not_take = 0;
        not_take = rec(v, ind+1, n);
        take+= v[ind][2];
        // if takes, then find the next possible index
        int next_ind = find_next_ind(v, v[ind][1], ind);
        if(next_ind<m) {
            take+=rec(v, next_ind, n);
        }
        
        
        return dp[ind]=max(take, not_take);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int ans = 0;
        auto compare = [](vector<int>& a, vector<int>& b) {
            if(a[0]==b[0]) {
                return a[1]<b[1];
            }
            return a[0]<b[0];  
        };
        dp.resize(100005,-1);
        sort(offers.begin(), offers.end(), compare);
        // print(offers);
        ans = rec(offers, 0, n);
        return ans;
    }
};
