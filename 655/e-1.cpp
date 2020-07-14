#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e2+10;
ll dp[N][N];
vector <pii> baz[N];
ll vis[N];
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        ll k;
        cin >> k;
        for (int j=0;j<k;j++){
            ll l,r;
            cin >> l >> r;
            baz[i].pb({l,r});
        }
    }
    for (int i=m;i;i--){
        for (int j=i+1;j<=m+1;j++){
            memset(vis,0,sizeof vis);
            for (int k=1;k<=n;k++){
                for (auto u : baz[k]){
                    if (u.F>=i && u.S<j){
                        for (int p=u.F;p<=u.S;p++){
                            vis[p]++;
                        }
                    }
                }
            }
            for (int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+vis[k]*vis[k]);
            }
        }
    }
    cout << dp[1][m+1];
 
}
