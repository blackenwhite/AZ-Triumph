#include<bits/stdc++.h>
using namespace std;

long long n;
vector<vector<string>> arr(100100, vector<string>(2));
long long cost[100100];
long long dp[100100][2];

long long rec(long long level, long long st){
    if(level == 0){
        if(st == 0) return 0;
        else return cost[0];
    }
    
    if(dp[level][st] != -1) return dp[level][st];
    
    long long ans = 1e17;
    if(st == 0){
        if(arr[level][0] >= arr[level-1][0]){
            ans = min(ans, rec(level-1, 0));
        }
        
        if(arr[level][0] >= arr[level-1][1]){
            ans = min(ans, rec(level-1, 1));
        }
    }else{
        if(arr[level][1] >= arr[level-1][0]){
            ans = min(ans, cost[level]+rec(level-1, 0));
        }
        
        if(arr[level][1] >= arr[level-1][1]){
            ans = min(ans, cost[level]+rec(level-1, 1));
        }
    }

    // cout << level << " " << st << " " << ans << '\n';
    
    
    return dp[level][st] = ans;
    
}

void solve(){
    cin >> n;
    for(long long i = 0; i <= n; i++){
        for(long long j = 0; j < 2; j++){
            dp[i][j] = -1;
        }
    }
    
    for(long long i = 0; i < n; i++) cin >> cost[i];
    
    for(long long i = 0; i < n; i++){
        cin >> arr[i][0];
        arr[i][1] = arr[i][0];
        reverse(arr[i][1].begin(), arr[i][1].end());
    }

    long long ans = min(rec(n-1, 0), rec(n-1, 1));
    if(ans >= 1e17){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc--){
        solve();
    }
    
    return 0;
}
