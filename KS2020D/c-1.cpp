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

vector<int> szA, szB;
vector<int> e[maxn];
int find(int x, int A) {
	for (int i = 0; i < 21; ++i) {
		if (A & (1 << i)) 
			x = fa[x][i];
	}
	return x;
}
int fa[maxn][22], dep[maxn];
void Deal_first(int u,int fa){
	dep[u]=dep[fa]+1;
	fa[u][0]=fa;
	for(int i=0;i<21;i++) fa[u][i+1]=fa[fa[u][i]][i];//递推过程
	for(auto v : e[u]) {
		if(v==fath) continue;
		Deal_first(v,u);
	}
}
void dfs(int x, int fa, vector<int> & sz, int A) {
	for (auto y : e[x]) {
		if (y == fa) continue;
		dfs(y, x, sz, A);
	}
	sz[x]++;
	if (find(x, A) > 0) {
		sz[find(x, A)] += sz[x];
	}
}	
void task() {
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x; 
		e[x].push_back(i);
	}
	Deal_first(1, 0);
	double ans = 0;
	szA.clear(); szB.clear();
	szA.resize(n + 1, 0);
	szB.resize(n + 1, 0);
	dfs(1, 0, szA, A);
	dfs(1, 0, szB, B);
	long long sumA = 0, sumB = 0;
	for (int i = 1; i <= n; ++i) {
		sumA += szA[i];
		sumB += szB[i];
	//	debug(i, szA[i], szB[i]);
	}
	for (int i = 1; i <= n; ++i) {
		ans += (long long)szA[i] * n + (long long)szB[i] * n - (long long)szA[i] * szB[i];
	}
	cout <<   ans /n /n << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(20);
  cin >> T;
  for(int i = 1; i <= T; ++i) {
		cout << "Case #" << i <<": ";
    task();
  }
  return 0;
}
