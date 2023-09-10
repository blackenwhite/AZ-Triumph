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

void solve()
{
    int n, c1, c2, c3;
    cin>>n>>c1>>c2>>c3;
    int ans = mult(fact[n], invFact[c1]);
    ans=mult(ans, mult(invFact[c2], invFact[c3]));
    cout<<ans<<"\n";
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
    {
        solve();
    }
    return 0;
}
