/*
Description

Given an array A of N integers and an integer target, find three integers in A such that the sum is closest to the target (absolute value of (sum-target) is minimum). Print the minimum absolute value of (sum-target). You cannot select an index more than one. All three indexes should be distinct.


Input Format

The first line contains T, the number of test cases (1<=T<=100).

The first line contains two space-separated integers N, target where 3<=N<=10^3, -1e18<=target<=1e18.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

The Sum of N across all test cases ≤ 10^4.


Output Format

For each test case print the minimum absolute value of (sum-target).
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int,int>

struct less_than_key {
    bool operator()(const pii& a, const pii& b){
        return (a.first-a.second)>(b.first-b.second);
    }
};

vector<vector<int>> arr;

bool valid(int x, int y) {
    int n=arr.size();
    int m=arr[0].size();
    return (x>=0 && x<n) && (y>=0 && y<m);
}
void update(int x1, int y1, int x2, int y2, int x) {
    if(valid(x1,y1)) {
        arr[x1][y1]+=x;
    }

    if(valid(x1, y2+1)) arr[x1][y2+1]-=x;
    if(valid(x2+1,y1)) arr[x2+1][y1] -= x;
    if(valid(x2+1, y2+1)) arr[x2+1][y2+1]+=x;
}

// void print(vector<vector<int>> arr) {
//     cout<<"Printing vector---\n";
//     int n=arr.size();
//     int m=arr[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }

void solve()
{
    int n,t;
    cin>>n>>t;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    int ans = 2e18+9;

    for(int k=0;k<=(n-3);k++){
        int i=k+1, j=n-1;
        while(i<j){
            int sum = v[k]+v[i]+v[j];
            if(sum>t){
                ans = min(ans, abs(t-sum));
                j--;
            }
            else if(sum<t){
                ans = min(ans, abs(sum-t));
                i++;
            }
            else{
                cout<<0<<"\n";
                return;
            }
        }
    }
    cout<<ans<<"\n";
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
