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
const int md = 998244353;
void addto(auto &x, auto y) { x = x + y; if (x >= md) x -= md; }
auto add(auto x, auto y) { auto z = x + y; return z >= md? z -= md : z;}
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

const int maxn = 1e6 + 10;

int T;
string str;
int n, m;

void task() {

	cin >> n;
	vector<long long> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(++a.begin(), a.end(), greater<int>());
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
	}
	for (int k = 1; k <= n; ++k) {
		long long ans = 0;
		for (int j = 1; j <= n;  j+= k) {
			int l = j;
			int r = min(n, j + k - 1);
			ans += (a[r] - a[l - 1]) * ((j - 1)  / k);
			ans %= md;
		}
		if ( k > 1) cout << " ";
		debug(ans);
		cout << ans * pw(n, md - 2) % md;
	}
	cout << endl;
	
	
	
	
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
