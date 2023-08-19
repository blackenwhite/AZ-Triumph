/*
Description

Given an integer t - the number of test cases. For each test case, read an integer n and answer the following 6 queries in the given order in a new line -:

Output the 64 bit binary representation of number n.
Output the position of the most significant bit ( MSB ) or the leftmost set bit of n ( 0- indexed ). If n=0, output -1.
Output the position of the rightmost set bit of n ( 0- indexed ). If n=0, output -1.
Output 1 if n  is a power of 2 i.e n==2X , x > 0, else output 0.
Output the biggest power of 2, that is the divisor of n. i.e biggest 2K such that n%2K == 0, k ≥ 0. If n=0, output -1. 
Output the smallest power of 2, which is not smaller than n, i.e smallest 2K such that 2K ≥ n, k>0.

Input Format

First-line contains an integer t -  number of test cases.

Each next t lines contain an integer n.


Output Format

For each test case, answer the 6 queries in the given order in a new line.


Constraints

1 ≤ t ≤ 105
- 1018 ≤ n ≤ 1018 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void binary(ll x) {
    for (int i = 63; i >= 0; i--) {
        if (x & (1LL << i))cout << 1;
        else cout << 0;
    }
    cout << endl;
}
int msb(ll x) {
    if (x == 0)return -1;
    if (x < 0)return 63; // negative numbers case.
    return (int)__lg(x);
}
int rsb(ll x) {
    if (x == 0)return -1;
    return msb(x ^ (x - 1));
}
bool pow2(ll &x) {
    if (x <= 1)return false;
    return (__builtin_popcountll(x) == 1);
}
ll pow2_div(ll x) {
    if (x == 0)return -1;
    return (1LL << __builtin_ctzll(x)); // 2^(trailing zeroes in bits).
}
ll pow2_n(ll x) {
    if (x <= 1)return 2;
    return (1LL << (64 - __builtin_clzll(x - 1))); // 2^(64 - leading zeroes in bits).
}
void solve() {
    ll n;
    cin >> n;
    binary(n);
    assert(n == 0 || msb(n) == 63 - __builtin_clzll(n));
    cout << msb(n) << endl;
    assert(n == 0 || rsb(n) == __builtin_ctzll(n));
    cout << rsb(n) << endl;
    cout << pow2(n) << endl;
    cout << pow2_div(n) << endl;
    cout << pow2_n(n) << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
