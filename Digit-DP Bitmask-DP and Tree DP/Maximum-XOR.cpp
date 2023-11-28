/*
You are given two integers L and R. You have to pick any two integers(they may be the same) in the range L to R(both inclusive) such that the xor of those two integers is maximum.
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
    // cout<<"Printing vector---\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j];
        }
        cout << "\n";
    }
}

int n = 60;
vector<int> lv(n), rv(n);
int dp[60][2][2][2][2];

int rec(int lvl, int tlo1, int thi1, int tlo2, int thi2)
{
    if (lvl < 0)
    {
        return 0;
    }

    if (dp[lvl][tlo1][thi1][tlo2][thi2] != -1)
    {
        return dp[lvl][tlo1][thi1][tlo2][thi2];
    }

    int ans = 0;
    int lo1 = 0, hi1 = 1, lo2 = 0, hi2 = 1;

    if (tlo1 == 1)
        lo1 = lv[lvl] - 0;
    if (thi1 == 1)
        hi1 = rv[lvl] - 0;

    if (tlo2 == 1)
        lo2 = lv[lvl] - 0;
    if (thi2 == 1)
        hi2 = rv[lvl] - 0;

    for (int i = lo1; i <= hi1; i++)
    {
        for (int j = lo2; j <= hi2; j++)
        {
            int ntlo1 = tlo1, nthi1 = thi1, ntlo2 = tlo2, nthi2 = thi2;
            if (i != lo1)
                ntlo1 = 0;
            if (i != hi1)
                nthi1 = 0;
            if (j != lo2)
                ntlo2 = 0;
            if (j != hi2)
                nthi2 = 0;

            ans = max(ans, (i ^ j)*(1LL<<lvl) + rec(lvl - 1, ntlo1, nthi1, ntlo2, nthi2));
        }
    }
    // printf("Ans for lvl = %lld, tlo1=%lld, thi1 = %lld, tlo2 = %lld, thi2=%lld is ---> %lld\n", lvl, tlo1, thi1, tlo2, thi2, ans);
    return dp[lvl][tlo1][thi1][tlo2][thi2] = ans;
}

void solve()
{
    int L, R;
    cin >> L >> R;
    memset(dp, -1, sizeof(dp));

    int bit = (int)(1) << (n - 1);
    for (int j = n - 1; j >= 0; j--, bit >>= 1)
    {
        // printf("bit = %lld, and j= %lld\n", bit, j);
        if (bit & L)
            lv[j] = 1;
        if (bit & R)
            rv[j] = 1;
    }

    int ans = rec(n-1, 1, 1, 1, 1);
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
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
