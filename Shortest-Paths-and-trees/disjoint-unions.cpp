/*
Description

Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint set where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries. There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents the type of queries. '0' denotes unite and '1' denotes same operation (x != y).

*/


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

	void init(int n = N) {
		par = new int[n+1];
		sz = new int[n+1];
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


void solve()
{
	int n,q;
	cin>>n>>q;
	UnionFind uf = UnionFind();
	uf.init(n);
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
//		cout<<"yo\n";
		if(a==0){
			uf.unite(b,c);
		}
		if(a==1){
			int ans = uf.check(b,c);
			cout<<ans<<"\n";
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
