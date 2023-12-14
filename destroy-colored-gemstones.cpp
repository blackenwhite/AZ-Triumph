/*

You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.*/ 

#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;
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

int inverse(int a) { return exponent(a, mod - 2); }

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

// int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> dirs;

void pr(vector<int> &v)
{
    cout << "Printing vector---\n";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int n;
vector<int>a;

int dp[202][202];

int rec(int l, int r) {
    // printf("rec called for l=%lld, r=%lld\n", l, r);
    if(l>r) return 0;
    if(l==r) {
        return dp[l][r] = 1;
    }

    if(dp[l][r]!=-1) return dp[l][r];

    // int j = l;
    // while(j<n && a[j]==a[l]) j++;

    int ans = 1 + rec(l+1,r);
    if(l<n-1 && a[l]==a[l+1]){
        ans = min(ans, 1+rec(l+2,r));
    }

    for(int i=l+2;i<=r;i++) {
        if(a[l]==a[i]) {
            ans = min(ans, rec(l+1,i-1) + rec(i+1,r));
        }
    }

    return dp[l][r] = ans;

}

void solve()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<rec(0,n-1)<<"\n";
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
