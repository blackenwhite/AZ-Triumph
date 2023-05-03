#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector <int> box;
    vector <int> inc;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        int siz = box.size();
        if (siz == n) // box is full
            return;
        box.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        int siz = box.size();
        if (siz == 0) // box is empty
            return -1;
        else {
            int z = box[siz - 1] + inc[siz - 1];
            if (siz > 1)
                inc[siz - 2] += inc[siz - 1];
            inc.pop_back();
            box.pop_back();
            return z;
        }
    }

    void increment(int k, int val) {
        int siz = box.size();
        k = min(k, siz);
        if (k == 0)
            return;
        inc[k - 1] += val;
    }
};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxSize;
	cin >> maxSize;

	int q;
	cin >> q;

	CustomStack* customStack = new CustomStack(maxSize);

	for (int itr = 0; itr < q; itr++) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;

			customStack->push(x);
		}
		else if (op == "pop") {
			cout << customStack->pop() << "\n";
		}
		else if (op == "inc") {
			int k, val;
			cin >> k >> val;
			customStack->increment(k, val);
		}
	}

}
