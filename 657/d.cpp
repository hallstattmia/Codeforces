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
#define fi first
#define se second
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


const int maxn = 1e6 + 10;

int T;
string str;
int n, m;
int h, nk;

void task() {
	cin >> n >> h >> m >> nk;
	vector<pair<int, int>> a; m /= 2;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		debug((y + nk) % (m) , i);
		a.push_back(make_pair((y) % (m) , i));
		a.push_back(make_pair((y) % (m) + m , i));
	}
	sort(a.begin(), a.end());
	int l = 0, r = 0;
	long long ansl = 0, ansr = 1e9;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < a.size() && a[i].first > a[j].first - nk ) ++j;

		if (j - 1 - i < ansr - ansl) {
			ansr = j - 1;
			ansl = i;
		}
	}
	cout << ansr - ansl << " " << (a[ansl].first +nk) % m << endl;
	for (int i = ansl + 1; i <= ansr; ++i) {
		if (i > ansl + 1) cout << " ";
		cout <<a[i].second;
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
