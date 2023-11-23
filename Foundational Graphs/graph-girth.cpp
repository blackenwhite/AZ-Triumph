// finding shortest cycle in an undirected graph

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'
vector<int> d;
int g;
void bfs(vector<int> adj[], int s) {
    queue<int> q;
    q.push(s);

    d[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto x : adj[v]) {
            if (d[x] == INT_MAX) {
                q.push(x);
                d[x] = d[v] + 1;
            }
            else if (d[v] <= d[x]) {
                g = min(g, d[v] + d[x] + 1);
                if (d[v] == d[x]) {   // optimisation.
                    return;
                }
            }

        }
    }
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    g = INT_MAX;
    for (int i = 1; i <= n; i++) {
        d.assign(n + 1, INT_MAX);
        bfs(adj, i);
    }
    cout << ((g == INT_MAX) ? -1 : g);
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
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
