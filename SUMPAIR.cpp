#include <bits/stdc++.h>
using namespace std;

class FindPairswithSum
{
public:
    unordered_map<int, int> hash;
    vector<int> v, w;
    FindPairswithSum(vector<int> &A, vector<int> &B)
    {
        for (int i : B)
        {
            w.push_back(i);
            hash[i]++;
        }
        for (int i : A)
            v.push_back(i);
    }

    void add(int index, int val)
    {
        hash[w[index]]--;
        w[index] += val;
        hash[w[index]]++;
    }

    int count(int total)
    {
        int ans = 0;
        for (int i : v)
        {
            if (hash.find(total - i) != hash.end())
                ans += hash[total - i];
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}
