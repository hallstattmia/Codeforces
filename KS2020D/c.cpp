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
int n, m, A, B;
int fa[maxn];
int count(int x, int y) {
	vector<int> paint(n + 1, 0);
	int cnt = 0;
	paint[x] = 1;
	while (fa[x] != 0) {
		 cnt++;
		 x = fa[x];
		 if (cnt == A) {
			 cnt = 0;
			 paint[x] = 1;
		 }
	}
	paint[y] = 1;
	cnt = 0;
	while (fa[y] != 0) {
		 cnt++;
		 y = fa[y];
		 if (cnt == B) {
			 cnt = 0;
			 paint[y] = 1;
		 }
	}
	int s = 0;
	for (int i = 1;i <= n; ++i) {
		if (paint[i]) s++;
	}
	return s;
}
void task() {
	cin >> n >> A >> B;
	fa[1] = 0;
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x;
		fa[i] = x;
	}
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) ans += count(i, j);
	}
	cout << ans /n /n << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> T;
  for(int i = 1; i <= T; ++i) {
		cout << "Case #" << i <<": ";
    task();
  }
  return 0;
}
