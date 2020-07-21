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
