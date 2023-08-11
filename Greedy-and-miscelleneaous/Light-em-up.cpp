/*
Description

There are n light bulbs in a row. Each bulb is either on or off given in input as 1 or 0 respectively.

In one operation you can select any k consecutive bulbs and flip their switches, that is, if a bulb was off it becomes on and vice versa.

Find minimum number of operations to turn all the bulbs on. If it's impossible to do so print -1.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n and k.

Second line contains n integers, ith integer si represents the state of the ith bulb.

 


Output Format

For each testcase if its possible to turn all the bulbs on, print the minimum operations required, else print -1.
*/

#include <bits/stdc++.h>
using namespace std;

bool isOff;

int minFlips (vector<bool> & v, int k) {
    if (v.size() == 0) {
        return -1;
    }
    if (isOff == true && k == 0) {
        return -1;
    }
    queue<int> flips;
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == flips.size() % 2) {
            res++;
            flips.push(i + k - 1);
        }
        if (!flips.empty() && flips.front() <= i) flips.pop();
    }
    return flips.empty() ? res : -1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<bool> a;
    isOff = false;
    for (int i = 0; i < n; i++) {
        bool x;
        cin >> x;
        if (!x) {
            isOff = true;
        }
        a.push_back(x);
    }
    cout << minFlips(a, k) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
