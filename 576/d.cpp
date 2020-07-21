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
const int md = 998244353 ;
void addto(int &x, int y) { x = x + y; if (x >= md) x -= md; }
int add(int x, int y) { int z = x + y; return z >= md? z -= md : z;}
void updmin(auto&x, auto y ) { if (y < x) x = y;}
void updmax(auto&x, auto y ) { if (y > x) x = y;}
long long pw(auto x, auto y) {	
	long long s = 1;
	while(y) {
		if (y & 1) s = s * x % md;
		x= 1LL * x * x % md; y /= 2;
	}
	return s;
}


const int maxn = 50 + 10;

int T;
string str;
int n, m;
int f[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
char s[maxn][maxn];
void pre(int n) {
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) {
			f[i][j] = -f[i - 1][j - 1] + f[i - 1][j] + f[i][j - 1] + (s[i][j] == '#');
		}	
}
void task() {
	cin >> n; 
	
	for (int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
	}
	pre(n);
	auto Get = [&](int x1, int y1, int x2, int y2) {
	  return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1-1] + f[x1-1][y1-1];  	
	};
	for (int i = n; i >= 1; --i) {
		for (int j = n; j >= 1; --j) {
			for (int i1 = i; i1 <= n; ++i1) 
				for (int j1 = j; j1 <=n; ++j1) {
					if (Get(i, j, i1, j1) == 0) {
						dp[i][j][i1][j1] = 0;
						continue;
					}
					dp[i][j][i1][j1] = max(i1 - i + 1, j1 - j + 1);
					for (int k = i; k < i1; ++k)
						updmin(dp[i][j][i1][j1], dp[i][j][k][j1] + dp[k + 1][j][i1][j1]);
						
						
					for (int k = j; k < j1; ++k)
						updmin(dp[i][j][i1][j1], dp[i][j][i1][k] + dp[i][k + 1][i1][j1]);
				}			
		}
		
	}
	cout << dp[1][1][n][n] << endl;
	
	
	// you should actually read the stuff at the bottom
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  T = 1;
  for (int ti = 1; ti <= T; ++ti) {
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
