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
int n, m, nq;
int a[maxn];
int sum[maxn];


void task() {
	cin >> n >> nq;
	int m = 600000 + 5;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[a[i]] = 1;
	}
	for (int i = 1; i <= m; ++i) sum[i] += sum[i - 1];
	int s = 0;
	for (int i = 1; i <= nq; ++i) {
		int x; cin >> x;
		s ^= x;
		int l, r;
		int ans = 0;
		for (int j = log2(m); j >= 0; --j) {
			l = (s ^ ans) >> j << j, r = l + (1 << j) - 1;
			if (l < 0 || r > m) continue;
			debug(sum[r] - (l > 0 ? sum[l - 1] : 0), (r - l + 1));
			if (sum[r] - (l > 0 ? sum[l - 1] : 0) == (r - l + 1)) {
				ans += (1 << j);
			}
	
		}
		cout << ans << endl;
	}
	
	// you should actually read the stuff at the bottom
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
