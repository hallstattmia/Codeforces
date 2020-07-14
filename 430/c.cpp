#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace  std;
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int md = 1e9 + 7;
void addto(int &x, int y) { x = x + y; if (x >= md) x -= md; }
int add(int x, int y) { int z = x + y; return z >= md? z -= md : z;}
void updmin(auto&x, auto y ) { if (y < x) x = y;}
void updmax(auto&x, auto y ) { if (y > x) x = y;}



const int maxn = 1e6 + 10;

int T;
string str;
int n, m;
int a[maxn];

vector<int> dp[maxn][2];
vector<int> e[maxn];

void dfs(int x, int fa) {
	for (auto y : e[x]) {
		if (y == fa) continue;
		for (int i = 0; i < 2; ++i) 
			for (auto g : dp[x][i]) {
				dp[y][i].push_back(__gcd(g, a[y]));
				if (i == 0) dp[y][i + 1].push_back(g);
			}
    for (int i = 0; i < 2; ++i) {
			sort(dp[y][i].begin(), dp[y][i].end());
			dp[y][i].erase(unique(dp[y][i].begin(),dp[y][i].end()), dp[y][i].end());
		}
		dfs(y, x);	
	}
}
void task() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		int x, y; cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dp[1][0].push_back(a[1]);
	dp[1][1].push_back(0);
	dfs(1, 0);
	for (int it = 1; it <= n; ++it) {
		if (it > 1) cout << " ";
		int s = 0;
		for (int i = 0; i < 2; ++i) 
			for (auto g : dp[it][i]) {
				s = max(s, g);
		}
		cout << s;
		debug(dp[it][0], dp[it][1]);
	}
	cout << endl;
	// you should actsually read the stuff at the bottom
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  T = 1;
  while (T--){
    task();
  }
  return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* write down
*/
