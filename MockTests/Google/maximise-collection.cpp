// Q: https://www.geeksforgeeks.org/problems/maximum-number-of-toys/1


//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
//User function Template for C++
#define ll long long 
int mod = 1e9+7;
using pii = pair<ll,ll>;
#define ff first
#define ss second


class Solution{
    vector<pii>v;
    vector<ll>pref;
    ll n,k,q,C;
    map<ll,ll> mp;
public:

    ll solve(vector<int>&query) {
        C = query[0];
        k = query[1];
        
        set<ll>st;
        for(int i=0;i<k;i++) {
            st.insert(mp[query[2+i]]);
        }
        
        ll lo=1, hi = n;
        ll ans = 0;
        while(lo<=hi) {
            ll mid = (lo+hi)/2;
            if(pref[mid]<=C){
                ans = mid;
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }
        
        ll rem_money = C-pref[ans];
        ll j = ans;
        // printf("init. ans = %lld, rem_mon = ", j, rem_money);
        for(auto it:st){
            if(it<=j){
                // printf("oops have to delete %lld\n", it);
                rem_money+=v[it].ff;
                ans--;
            }
            
            if(j<n && rem_money>=v[j+1].ff){
                ans++;
                j++;
                rem_money-=v[j].ff;
            }
        }
        return ans;
    }
    
    void print(vector<pii>&v) {
        cout<<"printing sorted array\n";
        for(auto it:v){
            printf("(%lld,%lld), ", it.ff, it.ss);
        }
        cout<<"\n";
    }
    
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
      n = N;
      v.resize(n+1);
      pref.resize(n+1);
      
      for(int i=0;i<n;i++) {
          v[i+1] = {A[i],i+1};
      }
      
      sort(v.begin(), v.end());
      
    //   print(v);
      
      for(int i=1;i<=n;i++) {
          mp[v[i].ss] = i;
      }
      
      for(int i=1;i<=n;i++) {
          pref[i] = pref[i-1]+v[i].ff;
      }
      
      vector<int> ans;
      for(auto it:Queries) {
          ans.push_back((int)solve(it));
      }
      
      return ans;
      
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends
