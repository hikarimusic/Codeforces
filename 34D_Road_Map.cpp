//Codeforces 34D - Road Map

#include <bits/stdc++.h>
using namespace std;
#define n_max 50000

vector<vector<int>> adj(n_max+5) ;
vector<int> p(n_max+5) ;
vector<bool> vis(n_max+5,0) ;

void dfs (int v) {
    vis[v]=1 ;
    for (int u : adj[v]) {
        if (!vis[u]) {
            p[u]=v ;
            dfs(u) ;
        }
    }
}

int main()
{
    int n,r1,r2,x ;
    scanf("%d %d %d",&n,&r1,&r2) ;
    for (int i=1;i<=n;++i) {
        if (i==r1) continue ;
        scanf("%d",&x) ;
        adj[i].push_back(x) ;
        adj[x].push_back(i) ;
    }
    dfs(r2) ;
    for (int i=1;i<=n;++i) {
        if (i==r2) continue ;
        printf("%d ",p[i]) ;
    }
    return 0;
}
