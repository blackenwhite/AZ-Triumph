/*
Description

Find the number of unordered ways, 
N
 can be partitioned into 
K
 positive integers (i.e 
>
0
 ), i.e sum of all 
K
 numbers must be 
N
.

Print the answer 
m
o
d
 
10
9
+
7
.

For eg. 
N
=
7
, 
K
=
3
, then the number of unordered ways are 
4
.
Explanation : { 1, 5, 1 }, { 2, 2, 3 }, { 4, 2, 1 }, and { 3, 1, 3 }.
Note : { 1, 5, 1 }, { 1, 1, 5 } and { 5, 1, 1 } are treated as same combination, i.e order doesn't matter.
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

void pr(vector<int> &v)
{
    cout << "Printing vector---\n";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int n,k;

int dp[5005][5005]={0}; // dp[K][N]

int rec(int n, int k) {
    if(n==0) return 1;
    if(n<0 || k==0 ) return 0;
    auto &ans = dp[n][k];
    if(ans!=-1) return ans;
    ans = rec(n-k,k);
    (ans+= rec(n,k-1)) %= mod;
    return ans;
}

void solve()
{   
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        cout<<rec(n-k,k)<<"\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
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
