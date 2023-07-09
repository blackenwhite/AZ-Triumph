#include<bits/stdc++.h>
using namespace std;

int n;
int arr[501];
int dp[501][501];

int rec(int l,int r){
    if(l==r){
        return 0;
    }
    if(dp[l][r]==-1){
        int ans = 1e9;
        int tot = 0;
        for(int i=l;i<=r;i++){
            tot+=arr[i];
        }
        int sum = 0;
        for(int mid=l;mid<r;mid++){
            sum += arr[mid];
            ans = min(ans,rec(l,mid)+rec(mid+1,r)+ ((sum)%100)*((tot-sum)%100));
        }
        dp[l][r]=ans;
    }
    return dp[l][r];
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}    

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}
