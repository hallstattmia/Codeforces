struct SegTree {
	struct {
		int l, r, lazy;
		long long sum; //modify0
		inline void set(int in_lazy = 0) {
			lazy += in_lazy;
			sum += in_lazy * (r - l + 1);
		}  //modify1
		inline void get() {
			ans += sum;
		}; //modify2
	}tr[maxn * 4];
	inline void pushdown(int x) {
		if (tr[x].lazy != 0) {
			tr[x << 1].lazy += tr[x].lazy;
			tr[x << 1].sum += 1LL * tr[x].lazy * (tr[x << 1].r - tr[x << 1].l + 1);
			tr[x << 1 | 1].lazy += tr[x].lazy;
			tr[x << 1 | 1].sum += 1LL * tr[x].lazy * (tr[x << 1 | 1].r - tr[x << 1 | 1].l + 1);
			tr[x].lazy = 0;
		}
		
	};// modify3
	
	inline void pushup(int x) {
		tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;	
	}; //modify4
	void build(int x, int l, int r) {
		 tr[x].l = l;
		 tr[x].r = r;
		 if (l == r) {
			 tr[x].set(a[l]); //modify
			 return;
		 }
		 int mid = (l + r) / 2;
		 build(x * 2, l, mid);
		 build(x * 2 + 1, mid + 1, r);
		 pushup(x);
	};
	void ins_interval(int x, int l, int r, int w) {
		if (l <= tr[x].l && tr[x].r <= r) {
			tr[x].set(w); //modify
			return;
		}
		pushdown(x);
		if (l <= tr[x << 1].r) ins_interval(x << 1, l, r, w);
		if (r >= tr[x << 1|1].l) ins_interval(x << 1|1, l, r, w);
		pushup(x);		
	};
	
	void query(int x, int l, int r) {
		debug(x, l, r);
		if (l <= tr[x].l && tr[x].r <= r) {
			tr[x].get();  //modify
			debug(ans);
			return;
		}
		pushdown(x);
		if (l <= tr[x << 1].r) query(x << 1, l, r);
		if (r >= tr[x << 1|1].l) query(x << 1|1, l, r);
		pushup(x);		
	};
};
SegTree seg; 

