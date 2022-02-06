//Codeforces 813C - The Tag Game

#include <bits/stdc++.h>
using namespace std;
#define n_max 200000

int n,x ;
vector<vector<int>> g(n_max+5) ;

vector<int> da(n_max+5,0) ;
vector<int> db(n_max+5,0) ;
vector<bool> vis ;

void dfs(int v, vector<int>& d) {
    vis[v]=1 ;
    for (int u : g[v]) {
        if (!vis[u]) {
            d[u]=d[v]+1 ;
            dfs(u,d) ;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&x) ;
    for (int t=0;t<n-1;++t) {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }
    vis.assign(n_max+5,0) ;
    dfs(1,da) ;
    vis.assign(n_max+5,0) ;
    dfs(x,db) ;
    int ans=0 ;
    for (int i=1;i<=n;++i) {
        if (db[i]<da[i] && da[i]>ans) ans=da[i] ;
    }
    printf("%d",2*ans) ;
    return 0;
}
