// String, stack, map

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string solve(string formula) {
    stack < pair < string, int > > s;

    for(int i = 0; i < (int)formula.length(); i++) {
        if(formula[i] == '(') {
            s.push({"(", -1});
        }
        else if(formula[i] == ')') {
            int multiplier = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                multiplier *= 10;
                multiplier += formula[i + 1] - '0';
                i++;
            }
            if(!multiplier) multiplier = 1;

            stack < pair < string, int > > temp;

            while(!s.empty()) {
                auto it = s.top();
                s.pop();
                if(it.first == "(") break;
                temp.push({it.first, it.second * multiplier});
            }

            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
        else if(formula[i] >= 'A' && formula[i] <= 'Z') {
            string atom = "";
            atom += formula[i];
            while(i + 1 < (int)formula.length() && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') {
                atom += formula[i + 1];
                i++;
            }

            int cnt = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                cnt *= 10;
                cnt += formula[i + 1] - '0';
                i++;
            }

            if(!cnt) cnt = 1;

            s.push({atom, cnt});
        }
    }

    map < string, int > M;

    while(!s.empty()) {
        M[s.top().first] += s.top().second;
        s.pop();
    }

    string ans = "";

    for(auto it : M) {
        ans += it.first;
        if(it.second > 1) ans += to_string(it.second);
    }

    return ans;
}


signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string formula;
    cin >> formula;

    cout << solve(formula) << "\n";

    return 0;
}
