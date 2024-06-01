/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.
*/

auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct DSU {
    vector<int> sz;
    vector<int> par;

    DSU(int n) {
        sz.resize(n, 1);
        par.resize(n);
        for (int j = 0; j < n; j++)
            par[j] = j;
    }

    int Leader(int x) {
        if (x == par[x])
            return x;
        return (par[x] = Leader(par[x]));
    }

    void merge(int x, int y) {
        x = Leader(x);
        y = Leader(y);

        if (x == y)
            return;
        if (sz[x] > sz[y])
            swap(x, y);
        sz[y] += sz[x];
        par[x] = y;
    }
};

class Solution {
public:
    int n;
    vector<int> v;
    vector<bool> is_active;
    vector<int> g[30003];
    int nC2(int x) { return (x * (x - 1)) / 2; }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        n = vals.size();
        v = vals;
        is_active = vector<bool>(n, false);

        // make the graph
        for (auto it : edges) {
            int u = it[0], v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        DSU dsu(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[v[i]].push_back(i);
        }

        // main algo
        int ans = n;
        for (auto it : mp) {
            int val = it.first;
            // cout << "Doing for val = " << val << "--->\n";
            // activate all the nodes

            for (auto p : it.second) {
                cout << " activating " << p << "\n";
                is_active[p] = true;
            }
            unordered_map<int, int> ump; // {leader, cnt}
            // try to merge these nodes to some active cluster
            for (auto p : it.second) {
                for (auto nn : g[p]) {
                    if (is_active[nn]) {
                        // cout << " merging " << p << " to " << nn << "\n";
                        dsu.merge(p, nn);
                        // int leader = dsu.Leader(p);
                        // ump[leader]++;
                    }
                }
            }

            for (auto p : it.second) {
                int leader = dsu.Leader(p);
                ump[leader]++;
            }

            // add contri. to the ans
            for (auto x : ump) {
                ans += nC2(x.second);
            }
            // cout << " ans after val = " << val << " is " << ans << "\n";
        }
        return ans;
    }
};
