

//============================================================================
// Name        : yo.cpp
// Author      : nabajyoti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style

/*
Description

Monkey D. Luffy, on his journey of becoming the "King of Pirates" and to conquer the "One Piece", wants to travel across the Grand Line.
Grand Line is a mysterious sea, and is in the shape of a 
N
∗
M
 grid 
S
 with each cell denoting the wind direction. The sign of 
S
[
i
]
[
j
]
 can be:

1
 which means wind in the cell flows to the right. (i.e from 
S
[
i
]
[
j
]
 to 
S
[
i
]
[
j
+
1
]
)
2
 which means wind in the cell flows to the left. (i.e from 
S
[
i
]
[
j
]
 to 
S
[
i
]
[
j
−
1
]
)
3
 which means wind in the cell flows downwards. (i.e from 
S
[
i
]
[
j
]
 to 
S
[
i
+
1
]
[
j
]
)
4
 which means wind in the cell flows upwards. (i.e from 
S
[
i
]
[
j
]
 to 
S
[
i
−
1
]
[
j
]
)
Notice that there could be some signs on the cells of the grid 
S
 that point outside the Grand Line sea grid.

Luffy's ship "Merry" can only sail along the wind direction and can't go outside the Grand Line sea grid 
S
 at any point.
Luffy can also modify the wind's direction on a cell with 
c
o
s
t
=
1
. ( can modify the sign on a cell one time only )
Find the minimum cost to make Luffy's Voyage from the top left corner of the Grand line i.e 
S
[
1
]
[
1
]
 to its bottom right corner i.e 
S
[
N
]
[
M
]
 possible.
*/


//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int,int>
#define N 100005
int inf = 1e18;
struct less_than_key {
    bool operator()(const pii& a, const pii& b){
        return (a.first-a.second)>(b.first-b.second);
    }
};

int mult(int a, int b) // O(1)
{
    return ((a % mod) * (b % mod)) % mod;
}

int exponent(int a, int b)
{
    int ans = 1;
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

int inverse(int a)
{
    return exponent(a, mod - 2);
}

int fact[N];
int invFact[N];

void init(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=mult(i, fact[i-1]);
    }

    invFact[N-1] = inverse(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        invFact[i] = mult(invFact[i+1], i+1);
    }
}

int nCr(int n, int r){
    return mult(fact[n] , mult(invFact[n-r], invFact[r]));
}

int add(int a, int b)
{ // O(1)
    int ans = (a + b);
    if (ans >= mod)
        ans -= mod;
    if (ans < 0)
        ans += mod;
    return ans;
}

vector<vector<int>>grid, dist;
int n,m;
int dirs[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1, 0}};

bool isValid(int x, int y){
	return x>=1 && y>=1 && x<=n && y<=m;
}

void print(vector<vector<int>>v) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void solve()
{

    cin>>n>>m;
    grid.resize(n+1,vector<int>(m+1));
    dist.resize(n+1,vector<int>(m+1, inf));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>grid[i][j];
    	}
    }

    dist[1][1] = 0;
    deque<pii> dq;
    dq.push_front({1,1});
    while(dq.size()>0){
    	pii cur = dq.front();
    	dq.pop_front();
    	int x = cur.first;
    	int y = cur.second;
    	int k1 = grid[x][y];
//    	cout<<"hello at "<<x<<" "<<y<<" "<<k1<<"\n";

    	int new_x, new_y;
    	new_x = x+dirs[k1][0];
    	new_y = y+dirs[k1][1];
    	if(isValid(new_x,new_y) && dist[new_x][new_y]>dist[x][y]){
    		dist[new_x][new_y] = dist[x][y];
//    		cout<<"pushing "<<new_x<<" "<<new_y<<" at the front\n";
    		dq.push_front({new_x, new_y});
    	}

    	for(int k=1;k<=4;k++) {
    		if(k1==k) continue;
    		new_x = x+dirs[k][0];
    		new_y = y+dirs[k][1];
			if(isValid(new_x,new_y) && dist[new_x][new_y]>(dist[x][y]+1)){
				dist[new_x][new_y] = dist[x][y]+1;
				dq.push_back({new_x, new_y});
			}
    	}
    }
//    print(dist);
    cout<< dist[n][m]<<"\n";


}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin >> t;
    // init();
    while (t--)
    {
        solve();
    }
    return 0;
}
