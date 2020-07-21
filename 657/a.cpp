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
const string find_str = "abacaba";
int T;
string str;
int n, m;
int check(string &str, int l, int r) {
	debug(l, r, str.size(), find_str.size());
	for (int i = l; i < r; ++i) {
		if (str[i] == '?') {
			str[i] = find_str[i - l];
		}  else {
			if (str[i] != find_str[i - l]) return 0;
		}
	}

	return 1;
}
bool find(string &str) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '?') str[i] = 'z';
	}
	int suit = 0;
	debug(str);
	for (int i = 0; i < str.size() - 6; ++i) {
		if (check(str, i, i + 7)) ++suit;
	}
	debug(suit);
	return suit == 1;
}
void task() {
	 cin >> n;
	 string str;
	 cin >> str;
	 for (int i = 0; i < n - 6; ++i){
		 string str2 = str;
		 int ok = check(str2, i, i + 7);
		 if (!ok) continue;
		 if (ok && find(str2)){
			 puts("Yes");
			 puts(str2.c_str());
			 return;
		 }
	 }
	 puts("No");
	// you should actually read the stuff at the bottom
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //cout<<fixed<<setprecision(20);
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
