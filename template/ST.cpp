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
