#include <bits/stdc++.h>
using namespace std;

#define int long long

int d[15][15];
int dp[(1<<15)][15];

int dfs(int vis, int pos, int n) {
    if(vis == (1<<n)-1) {
        return d[pos][0];
    }
    if(dp[vis][pos]) {
        return dp[vis][pos];
    }
    int ans = 2e18;
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = d[pos][i] + dfs(vis | (1<<i), i, n);
            ans = min(ans, temp);
        }
    }
    dp[vis][pos] = ans;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> d[i][j];
            }
        }
        cout << dfs(1, 0, n) << "\n";
    }
    return 0;
}#include <bits/stdc++.h>
using namespace std;

#define int long long

int d[15][15];
int dp[(1<<15)][15];

int dfs(int vis, int pos, int n) {
    if(vis == (1<<n)-1) {
        return d[pos][0];
    }
    if(dp[vis][pos]) {
        return dp[vis][pos];
    }
    int ans = 2e18;
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = d[pos][i] + dfs(vis | (1<<i), i, n);
            ans = min(ans, temp);
        }
    }
    dp[vis][pos] = ans;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> d[i][j];
            }
        }
        cout << dfs(1, 0, n) << "\n";
    }
    return 0;
}
