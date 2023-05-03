#include <bits/stdc++.h>
using namespace std;
class AddMul
{
public:
    long long i, m, MOD;
    vector<long long> v;

    AddMul()
    {
        i = 0, m = 1, MOD = 1e9 + 7;
    }

    long long power(long long a, long long b)
    {
        long long res = 1;
        a = a % MOD;
        while (b > 0)
        {
            if (b & 1)
            {
                res = (res * a) % MOD;
                b--;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long inverse(long long x)
    {
        return power(x, MOD - 2);
    }

    void append(long long val)
    {
        (val += MOD - i) %= MOD;
        (val *= inverse(m)) %= MOD;
        v.push_back(val);
    }

    void add(long long inc)
    {
        (i += inc) %= MOD;
    }

    void mult(long long mul)
    {
        (m *= mul) %= MOD;
        (i *= mul) %= MOD;
    }

    int get(int idx)
    {
        if (idx >= v.size())
            return -1;
        return (v[idx] * m % MOD + i) % MOD;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    
    AddMul *obj = new AddMul();
    
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        
        if (op == "append")
        {
            int val;
            cin >> val;
            obj->append(val);
        }
        else if (op == "add")
        {
            int inc;
            cin >> inc;
            obj->add(inc);
        }
        else if (op == "mult")
        {
            int mul;
            cin >> mul;
            obj->mult(mul);
        }
        else
        {
            int idx;
            cin >> idx;
            cout << obj->get(idx) << '\n';
        }
    }
    
    return 0;
}
