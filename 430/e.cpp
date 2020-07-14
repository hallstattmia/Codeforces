#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int fa[maxn][19];
int dep[maxn];
int getdis(int u, int v)
{
    int ret = 0;
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = 18; i >= 0; i--)
        if(dep[u] - (1 << i) >= dep[v])
        {
            u = fa[u][i];
            ret += 1 << i;
        }
    if(u == v)
        return ret;
    for(int i = 18; i >= 0; i--)
        if(fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
            ret += 1 << i + 1;
        }
    return ret + 2;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int>s1{1}, s2;
    dep[1] = 1;
    int mx = 1;
    for(int v = 2; v <= n + 1; v++)
    {
        int u;
        scanf("%d", &u);
        fa[v][0] = u;
        dep[v] = dep[u] + 1;
        for(int i = 1; (1 << i) < dep[v]; i++)
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        int dist1 = s1.empty() ? 0 : getdis(v, *s1.begin());
        int dist2 = s2.empty() ? 0 : getdis(v, *s2.begin());
        if(max(dist1, dist2) > mx)
        {
            mx = max(dist1, dist2);
            if(dist1 == mx)
            {
                for(int u : s2)
                {
                    if(getdis(u, v) == mx)
                        s1.push_back(u);
                }
                s2.clear(); 
                s2.push_back(v);
            }
            else
            {
                for(int u : s1)
                {
                    if(getdis(u, v) == mx)
                        s2.push_back(u);
                }
                s1.clear();
                s1.push_back(v);
            }
        }
        else if(max(dist1, dist2) == mx)
        {
            if(dist1 >= dist2)
                s2.push_back(v);
            else
                s1.push_back(v);
        }
        printf("%d\n", s1.size() + s2.size());
    }
    return 0;
}
