/*
Description

Consider the following function.

long long get(long long L, long long R, long long m) {
    long long sum = 0;
    for(long long i = L; i <= R; i++) {
        sum += (i % m);
        sum %= 1000000007;
    }
    return sum;
}
The above program is very inefficient for larger values of L, R, m.
Your challenge is to write an efficient program, that will find the value of get function in very less time.


Input Format

The first line of input contains one integer T — the number of test cases. Then T test cases follow.
The only line of each test case contains three space-separated numbers L, R, and m.


Output Format

For each test case, print a number on a new line denoting the answer return by get function in the above program.


Constraints

1 ≤ T ≤ 105
1 ≤ L ≤ R ≤ 1018
1 ≤ m ≤ 1018
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int,int>
#define N 100005
struct less_than_key {
    bool operator()(const pii& a, const pii& b){
        return (a.first-a.second)>(b.first-b.second);
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

void init(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=mult(i, fact[i-1]);
    }

    invFact[N-1] = inverse(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        invFact[i] = mult(invFact[i+1], i+1);
    }
}

int nCr(int n, int r){
    return mult(fact[n] , mult(invFact[n-r], invFact[r]));
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

int get(int r, int m){
    int q = r/m;
    int R = r%m;
    int ans = mult(mult(m,m-1),inverse(2));
    ans = mult(ans, q);
    int rem = mult(mult(R, R+1), inverse(2));
    ans = add(ans, rem);
    return ans;
}

void solve()
{
    int l,r,m;
    cin>>l>>r>>m;
    int ans = get(r,m)-get(l-1, m);
    ans = (ans+mod)%mod;
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
