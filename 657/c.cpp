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

void task() {
	 cin >> n >> m;
	 vector<pair<long long, long long> > a;
	 vector<long long> b;
	 for (int i = 1; i <= m; ++i) {
		 long long x, y;
		 cin >> x >> y;
		 a.push_back(make_pair(y, x));
		 b.push_back(x);
	 }
	 long long ans = 0;
	 sort(a.begin(), a.end(), greater<pair<long long, long long>>());
	 sort(b.begin(), b.end(), greater<long long>());
	 int st = 0;
	 long long sum  = 0;
	 for (auto p : a) {
		 long long y = p.first, x = p.second;
		 while (st < n && st < b.size() && b[st] > y) {
			 sum += b[st];  ++st;
		 }
		 int need = n - st;
		 long long s = sum;
		 debug(x, y, s, st, need);
		 if (need > 0) {
			 if (x <= y) {
				 need--;
			   s += x;
			 }
			 s += y * need; 
		 }
		 
		 ans = max(ans, s);
		 
	 }
	 cout << ans << endl;
	// you should actually read the stuff at the bottom
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> T;
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
