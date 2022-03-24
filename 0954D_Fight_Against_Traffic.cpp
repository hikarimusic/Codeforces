#include <bits/stdc++.h>
using namespace std;
#define n_max 1000

int n,m,s,t ;
vector<vector<int>> g(n_max+5) ;
vector<int> ds(n_max+5) ;
vector<bool> vis(n_max+5) ;
vector<int> dt(n_max+5) ;

void bfs(int src, vector<int>& d) {
    queue<int> q ;
    vis[src]=1 ;
    d[src]=0 ;
    q.push(src) ;
    while (!q.empty()) {
        int v=q.front() ;
        q.pop() ;
        for (int u : g[v]) {
            if (!vis[u]) {
                d[u]=d[v]+1 ;
                vis[u]=1 ;
                q.push(u) ;
            }
        }
    }
}

bool valid(int i, int j) {
    for (int v : g[i]) {
        if (v==j) return 0 ;
    }
    if (ds[i]+dt[j]+1<ds[t]) return 0 ;
    if (ds[j]+dt[i]+1<ds[t]) return 0 ;
    return 1 ;
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&s,&t) ;
    for (int i=0;i<m;++i) {
        int u,v ;
        scanf("%d %d",&u,&v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    vis.assign(n_max+5,0) ;
    bfs(s,ds) ;
    vis.assign(n_max+5,0) ;
    bfs(t,dt) ;
    int ans=0 ;
    for (int i=1;i<=n;++i) {
        for (int j=i+1;j<=n;++j) {
            if (valid(i,j)) ++ans ;
        }
    }
    printf("%d",ans) ;
    return 0;
}
