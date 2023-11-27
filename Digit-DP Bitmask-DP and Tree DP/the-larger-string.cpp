/*
Description

String P is given, consisting of uppercase alphabets. You have to find the number of strings Q, such that string Q is lexicographically larger than string P and reverse of string Q is lexicographically larger than the reverse of string P. Since the answer can be large, print the number of integers modulo 109 + 7.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line and only line of input contain string P.


Output Format

For each test case, print the number of strings Q.


Constraints

1 ≤ T ≤ 100

1 ≤ |P| ≤ 105 where |P| is the length of string P.

It is guaranteed that the sum of |P| for all test cases is not greater than 105.
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

string s;
int tt; // current test case
int testcase[100100][2][2]={0}; // which testcase dp array is storing for

int dp[100100][2][2];

// t1 -> tight for same as P from start or end
// t2 -> tight for same or smaller as P from end or not


void solve()
{
    
    
}

int rec(int pos, int t1, int t2){
    if(pos==s.length()){
        if(t2==0 && t1==0) return 1;
        return 0;
    }
    if(testcase[pos][t1][t2]==tt) {
        return dp[pos][t1][t2];
    }
    // cout<<"hello\n";
    int ans = 0;
    for(char dig = 'A';dig<='Z';dig++){
        if(t1==1 && dig<s[pos]) continue;
        int nt1 = t1;
        if(t1==1 && dig>s[pos]) nt1=0;

        int nt2;
        if(dig==s[pos]) {
            nt2 = t2;
        }
        else if(dig>s[pos]){
            nt2=0;
        }
        else nt2=1;

        ans=(ans+rec(pos+1,nt1,nt2))%mod;
    }
    testcase[pos][t1][t2] = tt;
    return dp[pos][t1][t2]=ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    // init();
    // while (t--)
    // {
    //     solve();
    // }
    for(tt=1;tt<=t;tt++){
        cin>>s;
        cout<<rec(0,1,1)<<"\n";
    }
    return 0;
}
