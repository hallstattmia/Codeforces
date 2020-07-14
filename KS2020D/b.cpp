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
int f[maxn][5];
int a[maxn];

void task() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 4; j++) f[i][j] = 1e9;
	}
	for (int i = 1; i <= 4; ++i) 
		f[1][i] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= 4; j++) 
			for (int k = 1; k <= 4; ++k) {
				int cost = 1;
				if (a[i + 1] > a[i] && k > j) cost = 0;
				if (a[i + 1] == a[i] && k == j) cost = 0;
				if (a[i + 1] < a[i] && k < j) cost = 0;				
				updmin(f[i + 1][k], f[i][j] + cost);
			}	
	}	
	int ans = 1e9;
	for (int i = 1; i <= 4; ++i) ans = min(ans, f[n][i]);
	cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for(int i = 1; i <= T; ++i) {
		cout << "Case #" << i <<": ";
    task();
  }


  return 0;
}
