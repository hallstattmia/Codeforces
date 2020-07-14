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



const int maxn = 1e6 + 10;

int T;
string str;
int n, m;

void task() {
	cin >> n;
	long long s  = 1e18, pa, pb;
	long long a, b;
	for (int i = 1; i * i <= n; ++i) if (n % i == 0){
		int d = i;
		//a = (n / d) / 2, b = n / d - a;
		//a *= d; b *= d;
		a = d; b = n - d;
		long long s2 = a * b / __gcd(a, b); 
		if (a && b && s2 < s) {
			s = s2; pa = a, pb = b;
		}
		
		d = n / i;
		//a = (n / d) / 2, b = n / d - a;
		//a *= d; b *= d;
		a = d; b = n - d;
		s2 = a * b / __gcd(a, b); 
		if (a && b && s2 < s) {
			s = s2; pa = a, pb = b;
		}
	}
	cout << pa << " " << pb << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--){
    task();
  }

  return 0;
}
