// https://practice.geeksforgeeks.org/problems/count-the-substring--170645/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
using ll = long long;
class Solution{
public:

    vector<ll>v;
    ll ans = 0;
    
    void merge(ll start, ll mid, ll end) {
        vector<int>temp(end-start+1);
        ll k = 0;
        ll i = start, j = mid+1;
        while(i<=mid && j<=end) {
            if(v[i]<v[j]){
                ans+=(end-j+1);
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        
        while(i<=mid) {
            temp[k++] = v[i++];
        }
        
        while(j<=end) {
            temp[k++] = v[j++];
        }
        
        for(int i=start;i<=end;i++) {
            v[i] = temp[i-start];
        }
    }
    
    void merge_sort(ll start,ll end) {
        if(start>=end){
            return;
        }
        ll mid = (start+end)/2;
        merge_sort(start,mid);
        merge_sort(mid+1,end);
        merge(start,mid,end);
    }
    
    void print(vector<ll>& pref){
        for(auto it:pref){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    
  ll countSubstring(string s){
    // code here
    ll n = s.size();
    v.resize(n+1);
    for(int i=0;i<n;i++) {
        if(s[i]=='0') v[i+1] = -1;
        else v[i+1] = 1;
        v[i+1]+=v[i];
    }
    
    // pref.resize(n+1);
    // for(int i=1;i<=n;i++){
    //     pref[i] = pref[i-1]+v[i];
    // }
    
    // print(v);
    
    merge_sort(0,n);
    return ans;
  }
};
