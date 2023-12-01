/*
You are given a tree consisting exactly of n
 vertices. Tree is a connected undirected graph with n−1
 edges. Each vertex v
 of this tree has a value av
 assigned to it.

Let dist(x,y)
 be the distance between the vertices x
 and y
. The distance between the vertices is the number of edges on the simple path between them.

Let's define the cost of the tree as the following value: firstly, let's fix some vertex of the tree. Let it be v
. Then the cost of the tree is ∑i=1ndist(i,v)⋅ai
.

Your task is to calculate the maximum possible cost of the tree if you can choose v
 arbitrarily.

Input
The first line contains one integer n
, the number of vertices in the tree (1≤n≤2⋅105
).

The second line of the input contains n
 integers a1,a2,…,an
 (1≤ai≤2⋅105
), where ai
 is the value of the vertex i
.

Each of the next n−1
 lines describes an edge of the tree. Edge i
 is denoted by two integers ui
 and vi
, the labels of vertices it connects (1≤ui,vi≤n
, ui≠vi
).

It is guaranteed that the given edges form a tree.

Output
Print one integer — the maximum possible cost of the tree if you can choose any vertex as v
.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int, int>
#define N 100005
int inf = 1e18;
struct less_than_key
{
    bool operator()(const pii &a, const pii &b)
    {
        return (a.first - a.second) > (b.first - b.second);
    }
};

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(a % b, b);
}

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

int inverse(int a)
{
    return exponent(a, mod - 2);
}

int fact[N];
int invFact[N];

void init()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mult(i, fact[i - 1]);
    }

    invFact[N - 1] = inverse(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invFact[i] = mult(invFact[i + 1], i + 1);
    }
}

int nCr(int n, int r)
{
    return mult(fact[n], mult(invFact[n - r], invFact[r]));
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

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void pr(vector<int>&v)
{
    cout << "Printing vector---\n";
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int n;
vector<int>a;

int tot_sum;
vector<int>sub_tot;
vector<int>indp,outdp;

vector<vector<int>>g;

void indfs(int nn, int pp) {
    sub_tot[nn] = a[nn];
    indp[nn] = 0;

    for(auto v:g[nn]){
        if(v!=pp) {
            indfs(v,nn);
            indp[nn]+=(indp[v]+sub_tot[v]);
            sub_tot[nn] += sub_tot[v];
        }
    }
    tot_sum+=a[nn];
    // indp[nn]+= sub_tot[nn];
}

void outdfs(int nn, int pp){
    outdp[nn] = outdp[pp] + indp[pp] - (indp[nn] + sub_tot[nn]) + (tot_sum-sub_tot[nn]); 
    for(auto v:g[nn]){
        if(v!=pp) {
            outdfs(v,nn);
        }
    }
}

void solve()
{
    cin >> n;
    a.clear();
    sub_tot.clear();
    indp.clear();
    outdp.clear();
    g.clear();
    a.resize(n+1);
    sub_tot.resize(n+1);
    indp.resize(n+1);
    outdp.resize(n+1);
    g.resize(n+1);
    tot_sum = 0;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=0;i<(n-1);i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    indfs(1,0);
    // printf("tot_sum = %lld\n", tot_sum);
    for(auto v:g[1]){
        outdfs(v,1);
    }
    
    // pr(indp);
    // pr(sub_tot);
    // pr(outdp);
    int maxx = -1, minn = inf;
    for(int i=1;i<=n;i++) {
        maxx=max(maxx, indp[i]+outdp[i]);
        minn = min(minn, indp[i]+outdp[i]);
    }
    cout<<maxx<<" "<<minn<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    // init();
    while (t--)
    {
        solve();
    }
    // for(tt=1;tt<=t;tt++){
    //     cin>>s;
    //     cout<<rec(0,1,1)<<"\n";
    // }
    return 0;
}
