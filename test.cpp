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
class LRUCache {
private:
  list<pair<int, int> > lis; 
  unordered_map<int, list<pair<int, int> > :: iterator> hash;
  int c;

public:
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
      if (hash.find(key) == hash.end()) {
          return -1;
      } else {
				// assert(hash.find(key) != hash.end());
         return (*hash[key]).first;
      }
    }
    
    void put(int key, int value) {
      if (hash.find(key) != hash.end()) { 
          lis.erase(hash[key]);
      } else if (lis.size() == c) {
          hash.erase((*lis.begin()).first);
          lis.erase(lis.begin());
          
      }
      lis.emplace_back(key, value);
      hash[key] = --lis.end();
    }
};
void task() {
  LRUCache cache = LRUCache(2);
  //Test cache.get(1)
  cache.put(1, 1);
  cache.put(2, 2);
  cout << "haha" << endl;
  //Test cache.put(1, 1);
  cout << cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout << cache.get(2);       // returns -1 (not found) ok
  cache.put(4, 4);    // evicts key 1
  cout << cache.get(1);       // returns -1 (not found) ok
  cout << cache.get(3);       // returns 3
  cout << cache.get(4);       // returns 4
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
