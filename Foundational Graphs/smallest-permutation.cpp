/*
Description

Among the sequences 
P
 that are permutations of 
(
1
,
2
,
…
,
N
)
 and satisfy the condition below, find the lexicographically smallest sequence.

For each 
i
=
1
,
…
,
M
, 
A
i
 appears earlier than 
B
i
​ in 
P
.
If there is no such 
P
, print -1.


Input Format

Input is given from Standard Input in the following format:

N
M

A
1
 
B
1

:
:
A
M
 
B
M

Output Format

Print the answer.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1], in_deg(n + 1, 0), ans;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_deg[v]++;
    }
    priority_queue < int , vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)if (in_deg[i] == 0)pq.push(i);
    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        ans.push_back(v);
        for (auto x : adj[v]) {
            in_deg[x]--;
            if (in_deg[x] == 0)pq.push(x);
        }
    }
    if (ans.size() != n) {
        cout << -1 << endl;
        return;
    }
    for (auto x : ans)cout << x << " ";
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
