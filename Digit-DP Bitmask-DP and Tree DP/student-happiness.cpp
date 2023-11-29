/*
There are N Ranks and M students in a class. Each student has a happiness value for the rank in the class he gets. The i th Student gets happy[i][j] on getting a rank j. It's ok to not keep all students in the ranks (They get 0 happiness). At most one student can be assigned to a rank. The total happiness of the assignment can be calculated as Sum of Happiness of each of the students in the class. Find the best way to calculate.
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
    cout<<"Printing vector---\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j]<<" ";
        }
        cout << "\n";
    }
}

int n,m;
int mat[60][20];
int dp[55][40000];

int rec(int ind, int mask) {
    if(ind==(m+1)){
        return 0;
    }

    if(dp[ind][mask]!=-1) return dp[ind][mask];
    int &ans = dp[ind][mask];
    int not_give = rec(ind+1,mask);
    for(int j=1;j<=n;j++) {
        if((1LL<<j)&mask){
            continue;
        }else{
            ans = max(ans,mat[ind][j]+rec(ind+1,mask|(1LL<<j)));
        }
    }
    ans = max(ans,not_give);
    return ans;
}

void solve()
{
    cin>>n>>m;
    // mat.resize(m+1,vector<int>(n+1));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>mat[i][j];
        }
    }
    // pr(mat);
    memset(dp,-1,sizeof(dp));
    int ans = rec(1,0);
    
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
    // for(tt=1;tt<=t;tt++){
    //     cin>>s;
    //     cout<<rec(0,1,1)<<"\n";
    // }
    return 0;
}
