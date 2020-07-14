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
int n, m, nq;


int a[maxn];
const int max_ST = 21;
class ST{
 private:
	//note:
	//1)init 1.all st[i][0]  2. check maxn, max_ST
	//2)support max(int)
	int st[maxn][max_ST], n;
 public:
	int query(int l,int r) {
		if (l > r) return -1e9;
		if (l < 1 || r > n) return 1e9;
		int k=log2(r-l+1) + 1e-6;
		assert(r-(1<<k)+1 >= 1);
		return max(st[l][k],st[r-(1<<k)+1][k]); 
	}
	void make(int *a, int in_n) {
		n = in_n;
		for (int i = 1 ;i <= n; ++i) st[i][0] = a[i];
		for(int j=1;j<=max_ST;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}	
};
ST st;
bool check(int x, int all, int L) {
	if (st.query(x - L, x - 1) < st.query(x, x + all - L)) return true;
	else return false;
}

void task() {
	cin >> n >> nq;
	a[0] = 1e9;
	a[n] = 1e9;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}
	st.make(a, n);
	for (int i = 1; i <= nq; ++i) {
		int x, y; cin >> x >> y; y--;
		
		debug(x, y);
		int l = 0, r = min(x - 1, y);
		while (l <= r) {
		  debug(l, r);
			int mid = (l + r) / 2;
			if (check(x, y, mid)) l = mid + 1;
			else r = mid - 1;
		}
	
		int left = l - 1, right = y - left;
		debug(i, left, right);
		if (st.query(x - left, x - 1) < st.query(x, x + right - 1))
			cout << x + right;
		else 
			cout << x - left;
		if (i < nq) cout << " ";
	}
	cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for(int i = 1; i <= T; ++i) {
		cout << "Case #" << i <<": ";
    task();
  }

  return 0;
}
