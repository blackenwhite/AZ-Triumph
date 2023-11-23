/*
Description

You have been given a grid of size N x N. Each cell is either empty (.) or occupied (#). Size of each cell is 1 x 1. In the connected component, you can reach any cell from every other cell in the component by repeatedly stepping to adjacent cells in the north, south, east, and west directions. 
Your task is to find the area and perimeter of the connected component having the largest area. The area of a connected component is just the number of '#' characters that are part of it. If multiple connected components tie for the largest area, find the smallest perimeter among them.


Input Format

The first line of input contains N, and the next N lines describe the grid. At least one '#' character will be present.


Output Format

Please output one line containing two space-separated integers, the first being the area of the largest connected component, and the second being its perimeter. If multiple connected components tie for the largest area, print the one which has the smallest perimeter among them.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define ld long double
#define pii pair<ll, ll>

ll n, m, q;

ll mod = (ll)(1e9 + 7);

ll dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Node
{
public:
    ll area;
    ll per;
};

Node bfs(ll x, ll y, vector<vector<char>> &mat)
{
    Node res;
    queue<pii> q;
    q.push({x, y});
    mat[x][y] = 'x';
    res.area = 1;
    res.per = 0;
    while (q.size() > 0)
    {
        pii cur = q.front();
        q.pop();
        for (ll k = 0; k < 4; k++)
        {
            ll nx = cur.first + dir[k][0];
            ll ny = cur.second + dir[k][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && mat[nx][ny] == '#')
            {
                q.push({nx, ny});
                mat[nx][ny] = 'x';
                res.area++;
            }
            else if (nx < 0 || nx >= n || ny < 0 || ny >= n || mat[nx][ny] == '.')
            {
                res.per++;
            }
        }
    }
    // cout << res.area << " " << res.per << "\n";
    return res;
}

void solve()
{
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    Node ans;
    ans.area = 0;
    ans.per = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (mat[i][j] == '#')
            {
                Node temp = bfs(i, j, mat);
                if (temp.area > ans.area)
                {
                    ans.area = temp.area;
                    ans.per = temp.per;
                }
                else if (temp.area == ans.area)
                {
                    if (temp.per < ans.per)
                    {
                        ans.per = temp.per;
                    }
                }
            }
        }
    }
    cout << ans.area << " " << ans.per << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
