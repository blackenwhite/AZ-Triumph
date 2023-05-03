#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class ProductOfKNumbers
{
    vector<ll> ans;
    ll mod = 1000000007;

public:
    ProductOfKNumbers()
    {
        ans.clear();
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

    ll mult(ll a, ll b) // O(1)
    {
        return ((a % mod) * (b % mod)) % mod;
    }

    ll inverse(ll a)
    {
        return exponent(a, mod - 2);
    }

    void add(int num)
    {
        if (num == 0)
        {
            ans.clear();
        }
        else
        {
            if (ans.size() == 0)
            {
                ans.emplace_back(num);
            }
            else
            {
                // ll x = (ans.back() * num) % mod;
                ll x = mult(ans.back(), num);
                ans.emplace_back(x);
            }
        }
    }

    int getProduct(int k)
    {
        if (ans.size() < k)
            return 0;
        if (ans.size() == k)
            return (int)ans.back();
        // ll res = (ans.back() / ans[ans.size() - k - 1]);
        ll res = mult(ans.back(), inverse(ans[ans.size() - k - 1]));
        return (int)res;
    }
};


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	ProductOfKNumbers productOfKNumbers;

	while(Q--) {
		string op;
		cin >> op;

		if (op == "add") {
			int num;
			cin >> num;
			productOfKNumbers.add(num);
		}
		else {
			int k;
			cin >> k;

			cout << productOfKNumbers.getProduct(k) << "\n";
		}
	}

	return 0;
}
