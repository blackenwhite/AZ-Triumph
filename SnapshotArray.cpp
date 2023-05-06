#include <bits/stdc++.h>
using namespace std;
class SnapshotArray
{
public:
    unordered_map<int, vector<pair<int, int>>> v;
    int snapId;

    SnapshotArray(int length)
    {
        snapId = 0;
    }

    void set(int index, int val)
    {
        if (v.find(index) != v.end())
        {
            if (v[index].back().second == snapId)
                v[index].back().first = val;
            else
                v[index].push_back({val, snapId});
        }
        else
            v[index].push_back({val, snapId});
    }

    int snap()
    {
        snapId++;
        return snapId - 1;
    }

    int get(int index, int snap_id)
    {
        if (v.find(index) == v.end())
            return 0;

        vector<pair<int, int>> &temp = v[index];

        int L = 0, R = (int)temp.size() - 1;
        int ans = 0;

        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (temp[mid].second <= snap_id)
            {
                ans = temp[mid].first;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }

        return ans;
    }
};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}
