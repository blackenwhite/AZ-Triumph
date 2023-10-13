/*
Description

You are given a tree consisting of n nodes. d(u, v) is the distance between nodes u and v, or number of edges in between the path connecting two nodes u and v. Your task is to find the sum of distances over all possible pairs of nodes.


Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


Output Format

Print the sum as mentioned in the problem statement.
*/

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
#define N 100005
int inf = 1e18;
struct less_than_key {
    bool operator()(const pii& a, const pii& b){
        return (a.first-a.second)>(b.first-b.second);
    }
};

int mult(int a, int b) // O(1)
{
    return ((a % mod) * (b % mod)) % mod;
}

int exponent(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

class UnionFind{
public:
	int *par, *sz;
	int comp;

	void init(int n = N) {
		par = new int[n+1];
		sz = new int[n+1];
		comp = n;
		for(int i=0;i<=n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}

	int root(int idx) {
		int x = idx;
		while(x!=par[x]){
			par[x] = par[par[x]];
			x = par[x];
		}
		return x;
	}

	bool unite(int a, int b) {
		int x = root(a), y = root(b);
		if(sz[x]< sz[y]){
			swap(x,y);
		}
		if(x!=y){
			par[y] = x;
			sz[x]+=sz[y];
			sz[y] = 0;
			comp--;
			return false;
		}
		return true;
	}

	bool check(int a, int b) {
		return (root(a)==root(b));
	}
};

int inverse(int a)
{
    return exponent(a, mod - 2);
}

int fact[N];
int invFact[N];

void init(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=mult(i, fact[i-1]);
    }

    invFact[N-1] = inverse(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        invFact[i] = mult(invFact[i+1], i+1);
    }
}

int nCr(int n, int r){
    return mult(fact[n] , mult(invFact[n-r], invFact[r]));
}

int add(int a, int b)
{ // O(1)
    int ans = (a + b);
    if (ans >= mod)
        ans -= mod;
    if (ans < 0)
        ans += mod;
    return ans;
}

vector<int> g[200100];
int dep[200100];
int par[200100];
int sz[200100];
int n;

void dfs(int node, int parent, int& ans){
	par[node]=parent;
	sz[node]=1;
	for(auto v:g[node]){
		if(v!=parent){
			dfs(v,node, ans);
			sz[node]+=sz[v];
		}
	}
	ans+=sz[node]*(n-sz[node]);
}

void solve()
{

	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	dfs(1,0,ans);
	cout<<ans<<"\n";
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
