/*
Description

You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.


Input Format

The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix. Each character is ‘.’ (floor), ‘#’ (wall), ‘A’ (start), or ‘M’ (monster). There is exactly one ‘A’ in the input.


Output Format

First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path that you'll follow.


Constraints

1 ≤ n, m ≤ 1000
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

void solve()
{
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    queue<pii> aQ, mQ;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
                aQ.push({i, j});
            if (mat[i][j] == 'M')
                mQ.push({i, j});
        }
    }

    ll lvl = 0;
    while (true)
    {
        ll sz1 = mQ.size();
        lvl++;
        while (sz1--)
        {
            pii cur = mQ.front();
            mQ.pop();
            for (ll k = 0; k < 4; k++)
            {
                ll nx = cur.first + dir[k][0];
                ll ny = cur.second + dir[k][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && (mat[nx][ny] == '.' || mat[nx][ny] == 'A'))
                {
                    mQ.push({nx, ny});
                    mat[nx][ny] = 'M';
                }
            }
        }
        // cout<<"Printing mat at lvl="<<lvl<<"===\n";
        // pr(mat);

        ll sz2 = aQ.size();
        bool jaa_sakte = false;
        while (sz2--)
        {
            pii Acur = aQ.front();
            aQ.pop();
            for (ll k = 0; k < 4; k++)
            {
                ll nx = Acur.first + dir[k][0];
                ll ny = Acur.second + dir[k][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    cout << "YES\n"
                         << (lvl - 1) << "\n";
                    return;
                }

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.')
                {
                    jaa_sakte = true;
                    aQ.push({nx, ny});
                    mat[nx][ny] = 'A';
                }
            }
        }
        if (!jaa_sakte)
        {
            cout << "NO\n";
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
