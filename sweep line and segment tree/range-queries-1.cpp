//============================================================================
// Name        : yo.cpp
// Author      : nabajyoti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int,int>
const int N = 200001;
int Tree[4*N];

int A[N];

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        Tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
    return;
}

int query(int node, int start, int end, int l, int r) {
    if(start > r || end < l) return 0;
    if(start >= l && end <= r) return Tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void solve()
{
	int n, q;
	cin >> n >> q;

	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		update(1, 0, n - 1, i, x);
	}

	while(q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1) {
			a--;
			update(1, 0, n - 1, a, b);
		}
		else {
			a--; b--;
			cout << query(1, 0, n - 1, a, b) << "\n";
		}
	}
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin >> t;
    // init();
    while (t--)
    {
        solve();
    }
    return 0;
}
