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
int a[maxn];
void task() {
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		//if (a[i] == i) cnt++;	
	}
	int l = 1;
	while (l <= n && a[l] == l) ++l;
	int r = n;
	while (r > 0  && a[r] == r) --r;
	if (l > r ) {
		cout << 0 << endl;
		return;
	}
	for (int i = l; i <= r; ++i) {
		if (a[i] == i) cnt++;	
	}
	if (cnt == 0) {
		cout << 1 << endl;
		return;
	}
	cout << 2 << endl;
	
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
