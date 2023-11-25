/*
DP Problem with a hint of digit DP+ strings
Description

Given a positive integer 
K
, and an array 
A
 consisting of 
N
( 
=
9
) integers such that 
A
i
 represents the cost of the digit (
i
+
1
). The task is to find the largest number that can be formed using the digits over the range 
[
1
,
9
]
 such that the sum of the cost of digits of the number formed is 
K
.


Input Format

The first line of input contains a single integer 
T
, denoting the number of test cases. Next, the test cases follow. Description of each test case:
The first line contains a single integer 
K
, denoting the total cost.
The second line contains 
9
 space-separated integers , 
A
1
,
A
2
,
.
.
.
,
A
9
, denoting the digit costs.


Output Format

Print 
T
 lines each containing a single integer, denoting the maximum number achievable or "IMPOSSIBLE" if this is not possible for any number.


Constraints

1
≤
T
≤
10
5

N
=
9

1
≤
K
≤
2000

1
≤
A
i
≤
K

It's guaranteed that the sum of all 
K
2
 over all test cases is 
≤
4
×
10
6
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

int k;
vector<int>cost;
string dp[2005];

string maxx(const string& A, const string& B) {
    string a = A;
    string b = B;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    while(a.size()<b.size()){
        a.push_back('0');
    }

    while(b.size()<a.size()){
        b.push_back('0');
    }

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a>b){
        return A;
    }
    return B;
}

string rec(int left) {
    if(left<0) {
        return "-2";
    }
    if(left==0) {
        return "";
    }

    auto ans=dp[left];
    if(ans!="-1"){
        return ans;
    }
    ans = "-2";
    for(int i=1;i<=9;i++) {
        string cur = to_string(i);
        if(ans=="-2") {
            string val = rec(left-cost[i]);
            if(val!="-2"){
                ans = cur+val;
            }
        }else{
            string val = rec(left-cost[i]);
            if(val!="-2"){
                ans=maxx(ans,cur+val);
            }
        }
    }
    return dp[left] = ans;
}

void solve()
{
    cin>>k;
    for(int i=0;i<=k;i++){
        dp[i] = "-1";
    }
    cost.assign(10,0);

    for(int i=1;i<=9;i++) {
        cin>>cost[i];
    }

    string res = rec(k);
    if(res=="-2") res = "IMPOSSIBLE";
    cout<<res<<"\n";
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
