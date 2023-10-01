/*
Description

You have given an undirected graph G with N nodes, indexed from 1 to N and M edges, indexed from 1 to M.

There are two types of operations:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.


Input Format

The first line of contains three space-separated numbers N, M, Q (1 ≤ N, M, Q ≤ 100000).

The next M lines contain 2 space-separated integers u and v which depicts an edge between nodes u and v (1 ≤ u, v ≤ N). ith line denotes the ith edge.

This is followed by Q lines, each describing an operation in the following format:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

There are no self-loops or multiple edges in the graph.

Note: If there are multiple queries for removal of the same edge, then the last such query should be considered. Also, the index of the edges does not change after the removal of any of the edges between the nodes.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

class wunionfind {
  public:
    int *id, *sz;
    int cnt = 0;
    wunionfind(int n = N) {
        id = new int[n + 1];
        sz = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        cnt = n;
    }
    int root(int idx) {
        int x = idx;
        while(x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }
    bool uni(int a, int b) {
        int x = root(a), y = root(b);
        if(sz[x] < sz[y]) {
            swap(x, y);
        }
        if (x != y) {
            cnt--;
            id[y] = x;
            sz[x] += sz[y];
            sz[y] = 0;
            return false;
        }
        return true;
    }
};

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, q; cin >> n >> m >> q;

    bool marked[m + 1];
    memset(marked, false, sizeof(marked));

    pair<int,int> query[q];
    pair<int,int> edge[m + 1];

    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        edge[i] = {u, v};
    }

    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 2) query[i] = {2, -1};
        else {
            int x; cin >> x;
            query[i] = {1, x};
            marked[x] = true;
        }
    }

    wunionfind W(n);

    for(int i = 1; i <= m; i++) {
        if(!marked[i]) {
            int u = edge[i].first;
            int v = edge[i].second;
            W.uni(u, v);
        }
    }

    vector<int> ans;

    for(int i = q - 1; i >= 0; i--) {
        if(query[i].first == 2) ans.push_back(W.cnt);
        else {
            int u = query[i].second;
            W.uni(edge[u].first, edge[u].second);
        }
    }

    reverse(ans.begin(), ans.end());

    for(int u : ans) cout << u << "\n";

    return 0;
}
