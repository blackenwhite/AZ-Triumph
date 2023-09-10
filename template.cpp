#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define N 100005
#define ll long long
#define ld long double
#define pii pair<ll, ll>

ll n, m, q;
vector<vector<ll>> arr;
vector<vector<ll>> P;
ll mod = (ll)(1e9 + 7);

/*
------------------ Sieve
*/

vector<int> GetPrimes(int limit){
    vector<int> not_prime(limit);
    vector<int> primes;
    for(int i=2;i<limit;i++){
        if(not_prime[i]){
            continue;
        }

        primes.push_back(i);

        for(int j=i*i;j<limit;j+=i){
            not_prime[j]=1;
        }
    }
    return primes;
}

ll gcd(ll a, ll b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(a % b, b);
}

ll exponent(ll a, ll b)
{
    ll ans = 1;
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
ll inverse(ll a)
{
    return exponent(a, mod - 2);
}
ll mult(ll a, ll b) // O(1)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b)
{ // O(1)
    ll ans = (a + b);
    if (ans >= mod)
        ans -= mod;
    if (ans < 0)
        ans += mod;
    return ans;
}

ll sub(ll a, ll b)
{ // O(1)
    return add(a, -b);
}

void pr(vector<ll> v)
{
    // for(ll i=0;i<v.size();i++){
    //     for(ll j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << "\n";
}

//  =================  String Rolling hash ================
// struct hasher{
//     ll sz,mod,p;
//     vector<ll> fHash;
//     void init(string s, ll _p,ll _mod){
//         mod = _mod;
//         p=_p;
//         sz = s.length();
//         fHash.resize(sz);
//         fHash[0] = (s[0]-'a'+1);
//         for(ll i=1;i<s.length();i++){
//             fHash[i] = (fHash[i-1]*p + (s[i]-'a'+1))%mod;
//         }
//     }

//     ll getHash(ll l,ll r){
//         if(l==0) return fHash[r];
//         else return ((fHash[r]-fHash[l-1]*p_to_x[r-l+1]))
//     }
// };

vector<ll> getKMP(string s)
{
    // cout<<"hi\n";
    ll n = s.length();
    vector<ll> res(n + 1);
    ll i = 0, j = -1;
    res[0] = -1;
    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
        {
            j = res[j];
        }
        i++;
        j++;
        res[i] = j;
    }
    return res;
}

// manacher's algorithm
class Manacher
{ // O(N) using manacher algorithm.
public:
    vector<int> manacher(string s)
    { // gives 2n-1 size manacher array. (a#c#...#d )
        string s1 = "@";
        for (auto c : s)
            s1 += c, s1 += "#";
        s1.back() = '&';
        vector<int> ans(s1.size() - 1);
        int lo = 0, hi = 0;
        for (int i = 1; i <= s1.size() - 2; i++)
        {
            if (i != 1)
                ans[i] = min(hi - i, ans[hi - i + lo]);
            while (s1[i - ans[i] - 1] == s1[i + ans[i] + 1])
                ans[i]++;
            if (i + ans[i] > hi)
                lo = i - ans[i], hi = i + ans[i];
        }
        ans.erase(begin(ans));
        for (int i = 0; i <= ans.size() - 1; i++)
            if ((i & 1) == (ans[i] & 1))
                ans[i]++;
        return ans;
    }
    string getLPS(string s)
    { // gives one of the long. palindromic substr.
        auto a = manacher(s);
        auto it = max_element(a.begin(), a.end());
        int l = *it, p;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == l)
            {
                p = i;
                break;
            }
        }
        return s.substr((p + 1) / 2 - l / 2, l);
    }
};
//=============end of manacher===============

// BIT Tries

class node
{
public:
    int cnt;
    vector<node *> ch;

    node()
    {
        cnt = 0;
        ch.resize(2);
        ch[0] = nullptr;
        ch[1] = nullptr;
    }
};

class trie
{
public:
    node *root;
    int LN = 32;
    trie()
    {
        root = new node();
    }

    void add(ll n)
    {
        node *cur = root;
        for (ll i = LN - 1; i >= 0; --i)
        {
            cur->cnt++;
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->ch[x] == nullptr)
            {
                cur->ch[x] = new node();
            }
            cur = cur->ch[x];
        }
        cur->cnt++;
    }

    void remove(ll n)
    {
        node *cur = root;
        for (ll i = LN - 1; i >= 0; i--)
        {
            cur->cnt--;
            int x = (n & (1 << i)) ? 1 : 0;
            cur = cur->ch[x];
        }
        cur->cnt--;
    }

    ll get_Max(ll n)
    {
        ll ans = 0;
        node *cur = root;
        for (ll i = LN - 1; i >= 0; i--)
        {
            int x = (n & (1 << i)) ? 1 : 0;
            int wanted = x ^ 1;
            if (cur->ch[wanted] != nullptr && cur->ch[wanted]->cnt > 0)
            {
                cur = cur->ch[wanted];
                ans ^= (1 << i);
            }
            else
            {
                cur = cur->ch[x];
            }
        }
        return ans;
    }
};


// string tries
class s_node
{
public:
    s_node *child[26];
    int prefix;
    vector<string> wend;
    s_node()
    {
        prefix = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        wend.resize(0);
    }
};

class s_trie
{
    s_node *root;
    s_trie()
    {
        root = new s_node();
    }

    void insert(string s)
    {
        s_node *cur = root;
        for (int i = 0; i < s.length(); i++)
        {
            cur->prefix++;
            int x = s[i] - 'a';
            if (!cur->child[x])
            {
                cur->child[x] = new s_node();
            }
            cur = cur->child[x];
        }
        cur->wend.push_back(s);
    }
};
int fact[N];
int invFact[N];
void init(){
    fact[0] = 1;
    for(int i=1;i<=N;i++){
        fact[i]=mult(i, fact[i-1]);
    }

    invFact[N]=inverse(fact[N]);
    for(int i=N-1;i>=1;i--){
        invFact[i]=mult(fact[i+1],i+1);
    }

}

int main() {
    return 0;
}
