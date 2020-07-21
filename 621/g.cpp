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
vector<pair<int, long long>> ans;
namespace mincost {
	//note: start 0
	const int V=250,E=40000,inf=0x20202020,_inf=0x20;
	const long long inff=1LL<<60;
	long long dis[V],c[E],cost;
	int q[V*30],vis[V],fst[V],pre[V],nxt[E],y[E],f[E],S,T,flow,tot,tn;
	void init(int s,int t,int Tn) {
		tot=1; tn=Tn;
		for (int i = 0; i < tn; ++i) fst[i]=0;
		S=s;T=t;
	}
	void add(int u,int v,int ff,long long cc) {
		tot++;y[tot]=v;nxt[tot]=fst[u];f[tot]=ff;c[tot]=cc;fst[u]=tot;
		tot++;y[tot]=u;nxt[tot]=fst[v];f[tot]=0;c[tot]=-cc;fst[v]=tot;
	}
	bool spfa() {
		for (int i = 0; i < tn; ++i) dis[i]=inff,vis[i]=0,pre[i]=0;
		dis[S]=0;q[0]=S;vis[S]=1;
		int t=1;
		for (int i = 0; i < t; ++i) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) {
				int v=y[j];
				if (f[j]&&dis[v]>dis[u]+c[j]) {
					dis[v]=dis[u]+c[j];
					pre[v]=j;
					if (!vis[v]) vis[v]=1,q[t++]=v;
				}
			}
			vis[u]=0;
		}
		return dis[T]!=inff;
	}
	void augment() {
		int p=T,_f=inf;
		while (pre[p]) _f=min(_f,f[pre[p]]),p=y[pre[p]^1];
		flow+=_f;cost+=_f*dis[T];
		p=T;
		while (pre[p]) f[pre[p]]-=_f,f[pre[p]^1]+=_f,p=y[pre[p]^1];
		ans.pb(mp(flow,cost));
	}
	void solve() {
		flow=0,cost=0;
		while (spfa()) augment();
	}
}

void task() {
	cin >> n >> m;
	mincost::init(0, n - 1, n);
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		mincost::add(x - 1, y - 1, 1, z);
	}
	mincost :: solve();
	int nq; cin >> nq;
	for (int qi = 1; qi <= nq; ++qi) {
		int cost;
		cin >> cost;
		double res = 1e30;
		for (auto x : ans) {
			res = min(res, 1.0 * (x.s + cost) / x.f);
		}
		cout << res << endl;
		
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
