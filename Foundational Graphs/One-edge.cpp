/*
Description

You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.


Input Format

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.


Output Format

Print the number of ways to add such edge, described in the statement
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100010;

int mod = 1e9 + 7;

vector<int> graph[N];
bool visited[N];
ll temp = 0;

void dfs(int cur)
{
    if (visited[cur])
        return;
    temp++;
    visited[cur] = true;
    for (int u : graph[cur])
    {
        dfs(u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));

    ll sqsum = 0, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        temp = 0;
        dfs(i);
        sqsum += temp * temp;
        sum += temp;
    }

    cout << (sum * sum - sqsum) / 2 << "\n";

    return 0;
}
