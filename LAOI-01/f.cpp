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


const int maxn = 1e6 + 10;

int T;
string str;
int n, m;
struct point {
	long double x, y;
	void read() {
		cin >> x >> y;
	};
} ;
long double L2dis(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
void task() {
	point a, b, c;
	a.read();
	b.read();
	c.read();
	point p;
	p.x = (a.x + b.x + c.x)/3;
	p.y = (a.y + b.y + c.y)/3;
	debug(p.x, p.y);
	long double eps = 1e-12;
	for (int i = 1; i <= 1e6; ++i) {
		point q;
		long double weighta =  L2dis(a, p);
		long double weightb =  L2dis(b, p);
		long double weightc =  L2dis(c, p);
		if (weighta < eps || weightb < eps || weightc < eps)break;
		double weight =  3.0 / weighta + 2.0 /weightb + 1.0/weightc;
		q.x = (3.0*a.x / weighta + 2.0*b.x / weightb + c.x / weightc);
		q.y = (3.0*a.y / weighta + 2.0*b.y / weightb + c.y / weightc);
    p.x = q.x / weight;
    p.y = q.y / weight;
   
	
	}
	debug(3 * L2dis(a, p) + 2 * L2dis(b, p) + L2dis(c, p));
	cout << p.x << " " << p.y << endl;
	// you should actually read the stuff at the bottom
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(5);
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
