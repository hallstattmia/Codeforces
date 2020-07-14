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



const int maxn = 1e2 + 10;

int T;
string str;
int n, m;
vector<pair<int, int>> e[maxn];
int cnt[maxn][maxn][maxn];
long long f[maxn][maxn];
void updmax(long long &x, long long y) {
	if (y > x) x = y;
}
long long sqr(long long x) {
	return x * x;
}
void task() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int nk; cin >> nk;
		while (nk--) {
			int x, y;
			cin >> x >> y;
			for (int k = x; k <= y; ++k) {
				cnt[k][x][y]++;
			}
		}
	}
	for (int  k = 1; k <= m; ++k) {
		for (int len = 1; len <= m; len++) {
			for (int l = 1; l <= m - len + 1; ++l) {
				int r = l + len - 1;
				cnt[k][l][r] += cnt[k][l][r - 1] + cnt[k][l + 1][r] - cnt[k][l + 1][r - 1];
			}
		}
	}
	for (int i = 1; i <= m; ++i) 
		for (int j = 1; j <= m; ++j) f[i][j] = 0;
	
	for (int len = 1; len <= m; len++) {
			for (int l = 1; l <= m - len + 1; ++l) {
				int r = l + len - 1;
				for (int k = l; k <= r; ++k) {
					updmax(f[l][r], f[l][k - 1] + f[k + 1][r] + 1LL * cnt[k][l][r] * cnt[k][l][r]);
				}
			}
	}							

	cout << f[1][m] << endl;

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  T = 1;
  while (T--){
    task();
  }

  return 0;
}
