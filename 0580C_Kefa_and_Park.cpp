#include <bits/stdc++.h>
using namespace std ;
#define MAXN 100005

int n,m,ans ;
vector<vector<int>> g(MAXN) ;
vector<int> c(MAXN) ;

void dfs (int u, int v, int s) {
    int ss=(c[u]==1)?(s+1):0 ;
    if (ss>m) return ;
    for (int w : g[u]) {
        if (w!=v) dfs(w,u,ss) ;
    }
    if (u!=1 && g[u].size()==1) ans++ ;
}

int main() {
    scanf("%d %d",&n,&m) ;
    for (int i=1;i<=n;++i) {
        scanf("%d",&c[i]) ;
    }
    for (int i=0;i<n-1;++i) {
        int a, b;
        scanf("%d %d",&a,&b) ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }
    dfs(1,0,0) ;
    printf("%d",ans) ;
    return 0 ;
}
