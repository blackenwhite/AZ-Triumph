#include<bits/stdc++.h>
using namespace std;

int n;
int a[10010];
int b[10010];
int d[10010];
int k;

int dp[101][101][101][101];

// MC - O(#s)
// TC - O(#s(1+#t))

int rec(int shop,int money_left,int p,int q){
    // pruning
    if(money_left<0){
        return 0;
    }
    // base case
    if(shop==n){
        return min(p,q);
    }
    // cache check
    if (dp[shop][money_left][p][q]!=-1){
        return dp[shop][money_left][p][q];
    }
    // transition 
    int ans = 0;
    ans = max(ans,rec(shop+1,money_left,p,q));
    ans = max(ans,rec(shop+1,money_left-a[shop],p+1,q));
    ans = max(ans,rec(shop+1,money_left-b[shop],p,q+1));
    ans = max(ans,rec(shop+1,money_left-a[shop]-b[shop]+d[shop],p+1,q+1));
    
    // save and return
    dp[shop][money_left][p][q]=ans;
    return ans;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>d[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,k,0,0)<<endl;
}

int main(){
    solve();
}
