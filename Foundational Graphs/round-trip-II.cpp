/*
cycle detection(excluding cycle of size 2) with directed graph 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n, m;
vector<int> color;
vector<vector<int>> adj;
bool f;
void dfs(int v) {
    if (f)return;
    color[v] = 1;// being visited
    for (auto x : adj[v]) {
        if (color[x] == 1) {
            f = true;
            return;
        }
        if (color[x] == 0) {
            dfs(x);
        }
    }
    color[v] = 2; // already visted
}
void solve() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    color.assign(n + 1, 0);
    f = false;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0)dfs(i);
    }
    if (!f)cout << "No" << endl;
    else cout << "Yes" << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
