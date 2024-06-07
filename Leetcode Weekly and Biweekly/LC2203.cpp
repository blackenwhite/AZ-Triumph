/*
You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.

You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.

Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.

Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.

A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.
*/

#define ll long long
#define ss second
#define ff first

const ll inf = 1e18;
using pii = pair<ll, ll>;

class Dijkstra {
public:
    vector<ll> dist;
    vector<ll> par;
    vector<vector<pii>> g;

    int n;
    int source;

    Dijkstra(int _source, int _n, vector<vector<int>>& edges, bool reverse)
        : n(_n), source(_source) {
        g.resize(n);
        dist.resize(n, inf);
        par.resize(n, -1);

        for (auto it : edges) {
            int from = it[0];
            int to = it[1];
            int w = it[2];

            if (reverse) {
                g[to].push_back({from, w});
            } else {
                g[from].push_back({to, w});
            }
        }

        Run();
    }

    void Run() {
        dist[source] = 0;
        par[source] = source;

        set<pii> nodes;
        for (int j = 0; j < n; j++)
            nodes.insert({dist[j], j});
        while (!nodes.empty()) {
            pii cur = *nodes.begin();
            nodes.erase(nodes.begin());

            if (dist[cur.ss] != cur.ff)
                continue;
            for (auto edge : g[cur.ss]) {
                ll w = edge.ss;
                ll to = edge.ff;

                if (dist[to] > (cur.ff + w)) {
                    dist[to] = cur.ff + w;
                    nodes.insert({dist[to], to});
                    par[to] = cur.ss;
                }
            }
        }
    }
};

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        Dijkstra d_src1(src1, n, edges, false);
        Dijkstra d_src2(src2, n, edges, false);
        Dijkstra d_dest(dest, n, edges, true);

        ll ans = d_src1.dist[dest] + d_src2.dist[dest];
        if(ans>=inf) return -1;

        for(int j=0;j<n;j++) {
            ll temp = d_src1.dist[j] + d_src2.dist[j] + d_dest.dist[j];
            ans = min(ans, temp);
        }
        return ans;
    }
};
