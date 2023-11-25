// Normal DP Problem , find the number of subsets divisible by 7

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

typedef long long int ll;
const ll M = 1000000007;
int n;
const int k = 7;
ll dp[100005][7];
ll rec(ll lv,ll mod){
    if(lv==n)   return mod==0;
    ll &ans = dp[lv][mod];
    if(ans!=-1) return ans;
    ans = 0;
    (ans+=rec(lv+1,(mod+arr[lv])%7))%=M;
    (ans+=rec(lv+1,mod))%=M;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n ;
        arr.assign(n,0);
        for(auto &itr:arr)  cin>>itr;
        for(int i=0;i<=n;i++){
            for(int j=0;j<7;j++)    dp[i][j] = -1;
        }
        cout<<rec(0,0)<<"\n";

    }
}
