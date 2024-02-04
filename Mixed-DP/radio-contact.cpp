// USACO http://www.usaco.org/index.php?page=viewproblem2&cpid=598
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
//EndCodeSnip

int N, M;

const int INF = 1e9 + 7;
const int MX = 1e3 + 1;

int sq(int a) { return a * a; }

int dist(pi a, pi b) {  // distance squared between two points
	return sq(a.f - b.f) + sq(a.s - b.s);
}

map<char, int> md{{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

// i = current step of John
// j = current step of Bessie

int dp[MX][MX];

int main() {
	setIO("radio");

	cin >> N >> M;

	vector<pi> jl(N + 1);  // john location
	vector<pi> bl(M + 1);  // bessie location

	int a, b;
	cin >> a >> b;

	jl[0] = {a, b};  // initial john location
	cin >> a >> b;
	bl[0] = {a, b};  // initial bessie location

	string jS, bS;  // john and bessie movement strings
	cin >> jS >> bS;

	// calculating both of their movements
	// dx[md[jS[i]]] may look complicated, but it just maps the char to its
	// change

	for (int i = 0; i < sz(jS); i++) {
		jl[i + 1] = {jl[i].f + dx[md[jS[i]]], jl[i].s + dy[md[jS[i]]]};
	}

	for (int i = 0; i < sz(bS); i++) {
		bl[i + 1] = {bl[i].f + dx[md[bS[i]]], bl[i].s + dy[md[bS[i]]]};
	}

	// either john moves, bessie moves, or both move

	fill_n(dp[0], MX * MX, INF);

	dp[0][0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(jl[i + 1], bl[j]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(jl[i], bl[j + 1]));
			dp[i + 1][j + 1] =
			    min(dp[i + 1][j + 1], dp[i][j] + dist(jl[i + 1], bl[j + 1]));
		}
	}

	cout << dp[N][M] << "\n";
}
