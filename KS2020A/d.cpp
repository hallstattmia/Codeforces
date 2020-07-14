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



const int maxn = 2e6 + 10;

int T;
string str;
int n, m, nk;
long long ans;
int tr[maxn][26], cnt[maxn]; 
void dfs(int x, int d) {
	for (int i = 0 ; i < 26; ++i) {
		if (tr[x][i]) {
			dfs(tr[x][i], d + 1);
			cnt[x] += cnt[tr[x][i]];
		}
	}
	while (cnt[x] >= nk) {
		ans += d;
		cnt[x] -= nk;
	}
}
void task() {
	
	cin >> n >> nk;
	int m = 1;
	ans = 0;
	for (int it = 0; it < n; ++it) {
		string str;
		cin >> str;  
		int x = 1;
		for (int i = 0; i < str.size(); ++i) {
			if (!tr[x][str[i] - 'A']) {
				tr[x][str[i] - 'A'] = ++m;
			}
			x = tr[x][str[i] - 'A'];
		}
		cnt[x]++;
	}
	dfs(1, 0);
	
	cout << ans << endl;
	memset(tr, 0, (m + 10)*sizeof(tr[0]));
	memset(cnt, 0, (m + 10)*sizeof(int));
	// you should actually read the stuff at the bottom
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
		cout << "Case #" << ti << ": ";
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
