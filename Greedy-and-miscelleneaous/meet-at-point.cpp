/*Description

There are 
n
 friends in a 2D plane who want to meet at some common point. Each of their position is given to you as 
x
 & 
y
 coordinates.

The distance a person covers to go from position 
(
x
1
,
y
1
)
 to 
(
x
2
,
y
2
)
 is the Manhattan distance, i.e., 
|
x
1
−
x
2
|
+
|
y
1
−
y
2
|
.

They choose the meeting point such that the sum of distances covered by each of them to reach it is minimum. Find this minimum sum of distances.


Input Format

The first line of input contains 
T
, the number of test cases.
The first line of each test case contains 
n
.
Each of the next 
n
 lines contains two integers 
(
x
,
y
)
.


Output Format

For each test case output one integer: The minimum sum of distances covered by them.


Constraints

1
≤
T
≤
10

1
≤
n
≤
10
5

0
≤
x
,
y
≤
10
6
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int getMedian(vector<int>arr){
    int n=arr.size();
    if(n%2){
        return arr[n/2];
    }else {
        return (arr[n/2] + arr[(n-1)/2])/2;
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int>X(n),Y(n);
    for(int i=0;i<n;i++){
        cin>>X[i]>>Y[i];
    }

    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());

    int med_x = getMedian(X);
    int med_y = getMedian(Y);

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(X[i]-med_x) + abs(Y[i]-med_y);
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
