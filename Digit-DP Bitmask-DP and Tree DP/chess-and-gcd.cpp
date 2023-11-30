/*
There are 2*N Chess players and N Boards in a chess tournament. The rating of the Chess Player is given by array A. Every player can play only with one player. N board pairing to be done, and if you match Player i and Player j in the board K, then the Happiness Score increases by K*abs(A[i]-A[j])*gcd(A[i],A[j]). Find the Maximum Happiness score you can make by designing an ideal pairing. Every player should play a match.
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

void pr(vector<vector<int>> &v)
{
    cout << "Printing vector---\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int n;
vector<int> a;
int dp[(1 << 21)];
vector<vector<int>> g;

int rec(int board, int mask)
{
    if (mask == (1 << (2 * n)) - 1)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (i != j && (mask & ((1 << i) | (1 << j))) == 0)
            {
                ans = max(ans, board * abs(a[i] - a[j]) * g[i][j] + rec(board + 1, (mask | ((1 << i) | (1 << j)))));
            }
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    cin >> n;
    a.clear();
    g.clear();
    a.resize(2 * n);
    g.resize(2 * n, vector<int>(2 * n));
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            g[i][j] = gcd(a[i], a[j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(1, 0) << "\n";
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
