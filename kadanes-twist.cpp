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

int n, m;
vector<int> arr[51];

struct max_sum_value
{
    int best = -1;
    int prebest;
    int suffbest;
    int tot;

    void build(vector<int>& v)
    {
        int n = v.size();
        tot = 0;
        for (int i = 0; i < n; i++) {
            tot += v[i];
        }
            
        // cout<<"tot = "<<tot<<"\n";
        prebest = v[0];
        int pref_sum = v[0];
        for (int i = 1; i < n; i++)
        {
            pref_sum += v[i];
            prebest = max(prebest, pref_sum);
        }

        suffbest = v[n - 1];
        int suff_sum = v[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suff_sum += v[i];
            suffbest = max(suffbest, suff_sum);
        }

        best = tot;
        int last_best = 0;
        for (int i = 0; i < n; i++)
        {
            last_best = max(last_best+v[i], v[i]);
            best = max(best, last_best);
        }

        // cout<<"best from function = "<<best<<"\n";
    }

    void print() {
        printf("tot = %lld, prebest = %lld, suffbest = %lld, best = %lld\n", tot, prebest, suffbest, best);
    }
};

// max_sum_value converted[51];
vector<max_sum_value> converted(51);

max_sum_value merge(max_sum_value a, max_sum_value b) {
    max_sum_value ans;
    ans.best = max({a.best, b.best, a.suffbest + b.prebest});
    ans.prebest  = max(a.prebest, a.tot+b.prebest);
    ans.suffbest = max(b.suffbest, b.tot+a.suffbest);
    ans.tot = a.tot+b.tot;
    return ans;
}


void solve()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) {
        int l; cin>>l;
        arr[i].clear();
        for(int j=0;j<l;j++) {
            int x;
            cin>>x;
            arr[i].push_back(x);
        }
        converted[i].build(arr[i]);
        // converted[i].print();
        // printf("best at i=%lld = %lld\n",i,converted[i].tot);
    }

    int final_pos[m];
    for(int j=0;j<m;j++) {
        cin>>final_pos[j];
    }

    max_sum_value final_ans = converted[final_pos[0]];
    for(int j=1;j<m;j++) {
        final_ans = merge(final_ans, converted[final_pos[j]]);
    }
    cout<<final_ans.best<<"\n";
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
