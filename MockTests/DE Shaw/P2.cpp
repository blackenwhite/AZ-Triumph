/* 
Description

We are given an array 
A
 of 
n
 elements. We need to count the number of non-empty subsequences such that these individual subsequences have the same values of bitwise AND, OR and XOR. For example, we need to count a subsequence 
(
x
,
y
,
z
)
 if 
(
x
|
y
|
z
)
 is equal to 
(
x
&
y
&
z
)
 and 
(
x
⊕
y
⊕
z
)
. For a single element subsequence, we consider the element itself as a result of XOR, AND and OR. Therefore all single element subsequences are always counted as part of the result.

The answer can be too large, print it with modulo 
10
9
+
7
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

int n;

void solve()
{
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[v[i]]++;
    }

    int ans = 0;
    ans+=exponent(2, mp[0]);
    ans--;
    ans%=mod;
    for(auto it:mp){
        if(it.first==0) continue;
        else {
            ans+=exponent(2,it.second-1);
            ans%=mod;
        }
    }
    cout<<ans<<"\n";
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
