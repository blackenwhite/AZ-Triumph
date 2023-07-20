// without doing prefix Sum O(nm)^(3/2)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string s;
// int dp[1001][1001];

ll getBestSubarraySum(vector<ll>arr){
    ll global_max= arr[0];
    ll local_max = arr[0];
    for(ll i=1;i<arr.size();i++){
        if(arr[i]<(local_max+arr[i])) local_max = arr[i]+local_max;
        else local_max = arr[i];
        global_max = max(global_max, local_max);
        // if(global_max==0) {
        //     cout<<"0 mila i= "<<i<<"\n";
        // }
    }
    // cout<<"global_max = "<<global_max<<"\n";
    return global_max;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    ll ans = -2e18;
    // m<n
    if(m<n) {
        for(ll c1=0;c1<m;c1++){
            vector<ll>rowSum(n,0);
            for(ll c2=c1;c2<m;c2++){
                for(ll r=0;r<n;r++){
                    rowSum[r]+=arr[r][c2];
                }
                ans = max(ans, getBestSubarraySum(rowSum));
            }
        }
    }else {
        for(ll r1=0;r1<n;r1++){
            vector<ll>colSum(m,0);
            for(ll r2=r1;r2<n;r2++){
                for(ll c=0;c<m;c++){
                    colSum[c]+=arr[r2][c];
                }
                ans = max(ans, getBestSubarraySum(colSum));
            }
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
