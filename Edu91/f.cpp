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
int nq;
int a[maxn];
struct SegTree {
	struct {
		int l, r, lazy;
		int kk, kb, bk, bb;
		void set(int in_kk, int in_kb, int in_bk, int in_bb) {
			kk = in_kk;
			kb = in_kb;
			bk = in_bk;
			bb = in_bb;
		}  //modify1
	}tr[maxn * 4];
	void pushdown(int x) {
		if (tr[x].lazy != 0) {
			tr[x].lazy = 0;
		}
	};// modify3
	
	void pushup(int x) {
		int mid = (tr[x].l + tr[x].r) / 2;
		int v = a[mid] == 1? 9 - a[mid + 1] : 0;
	
		tr[x].kk = (1LL * tr[x << 1].kb * tr[x << 1|1].bk % md);
		if(tr[x].l + 1 <= mid && tr[x].r  - 1 > mid)  tr[x].kk += (1LL * tr[x << 1].kk * tr[x << 1|1].kk % md * v % md);
		tr[x].kb = (1LL * tr[x << 1].kb * tr[x << 1|1].bb % md);
		if(tr[x].l + 1 <= mid) tr[x].kb += (1LL * tr[x << 1].kk * tr[x << 1|1].kb % md * v % md);
		tr[x].bk = (1LL * tr[x << 1].bb * tr[x << 1|1].bk % md);
		if (tr[x].r  - 1 > mid)tr[x].bk += (1LL * tr[x << 1].bk * tr[x << 1|1].kk % md * v % md);
		tr[x].bb = (1LL * tr[x << 1].bb * tr[x << 1|1].bb % md);
		tr[x].bb += (1LL * tr[x << 1].bk * tr[x << 1|1].kb % md * v % md);		
	}; //modify4
	void build(int x, int l, int r) {
		 tr[x].l = l;
		 tr[x].r = r;
		 if (l == r) {
			 tr[x].set(1, 1, 1, a[l] + 1);
			 return;
		 }
		 int mid = (l + r) / 2;
		 build(x * 2, l, mid);
		 build(x * 2 + 1, mid + 1, r);
		 pushup(x);
	};
	void ins_pos(int x, int pos) {
		if (tr[x].l == tr[x].r) {
			tr[x].set(1, 1, 1, a[tr[x].l] + 1);
			return;
		}
		pushdown(x);
		if (pos <= tr[x << 1].r) ins_pos(x << 1, pos);
		if (pos >= tr[x << 1|1].l) ins_pos(x << 1|1, pos);
		pushup(x);
	}
	void ins_interval(int x, int l, int r) {
		if (l <= tr[x].l && tr[x].r <= r) {
			tr[x].set();
		}
	};
};
SegTree seg; 
void task() {
	cin >> n >> nq;
	string str; cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		a[i + 1] = str[i] - '0';
	}
	seg.build(1, 1, n);	
	for (int i = 1; i <= nq; ++i) {
		int x, y; cin >> x >> y;
		a[x] = y;
		seg.ins_pos(1, x);
		cout << seg.tr[1].bb % md << endl;
	}
	
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
