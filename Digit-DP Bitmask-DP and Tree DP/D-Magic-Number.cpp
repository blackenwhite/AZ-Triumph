/*
Description

A number N is said to be D-Magic if digit D appears in the decimal representation of the number on only even positions. You have to tell the number of D-Magic numbers in the range A to B(both inclusive) that are multiple of M. Since the answer can be large, print the number of integers modulo 109 + 7.

It is given that the number of digits in A and B is the same and A ≤ B.

 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers M and D.

The second line of each test case contains one integer A.

The third line of each test case contains one integer B.


Output Format

Print single integer denoting the number of D-Magic numbers in the range A to B(both inclusive) that are multiple of M, modulo 10^9 + 7.
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

int dir[4][2] = {{0,1}, {0, -1}, {1,0}, {-1,0}};


void pr(vector<vector<int>>&v) {
    // cout<<"Printing vector---\n";
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j];
        }
        cout<<"\n";
    }
}

int len,m,d;
string a,b;

int dp[2005][2][2][2005][2];

int rec(int lvl, int tlo, int thi, int sum, int flag) {
    if(lvl==len){
        if(sum%m==0) return 1;
        return 0;
    }

    if(dp[lvl][tlo][thi][sum][flag]!=-1){
        return dp[lvl][tlo][thi][sum][flag];
    }
    int& ans = dp[lvl][tlo][thi][sum][flag];
    ans=0;
    int lo=0,hi=9;
    if(tlo==1) lo = a[lvl]-'0';
    if(thi==1) hi = b[lvl]-'0';

    for(int i=lo;i<=hi;i++){
        int ntlo = tlo, nthi = thi;
        if(i!=lo) ntlo = 0;
        if(i!=hi) nthi = 0;

        if(flag==0 && i!=d) {
            ans+=rec(lvl+1, ntlo,nthi, (sum*10+i)%m, (lvl+1)%2);
        }
        if(flag==1 && i==d) {
            ans+=rec(lvl+1,ntlo,nthi,(sum*10+i)%m, (lvl+1)%2);
        }
        ans%=mod;

    }
    return ans;
}
void solve()
{
    cin>>m>>d>>a>>b;
    len = a.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0,0)<<"\n";
    
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
    return 0;
}
