#include <bits/stdc++.h>
using namespace std ;
#define MAXN 2005

int n,ans ;
vector<vector<int>> g(MAXN) ;
bool vis[MAXN] ;

void dfs(int u, int l) {
    vis[u]=1 ;
    ans=max(ans,l+1) ;
    for (int v : g[u]) dfs(v,l+1) ;
}

int main() {
    cin>>n ;
    for (int i=1;i<=n;++i) {
        int j ;
        cin>>j ;
        if (j!=-1) g[j].push_back(i) ;
    }
    for (int i=1;i<=n;++i) {
        if (!vis[i]) dfs(i,0) ;
    }
    cout<<ans ;
    return 0 ;
}
