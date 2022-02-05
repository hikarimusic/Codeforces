//Codeforces 780C - Andryusha and Colored Balloons

#include <bits/stdc++.h>
using namespace std;
#define n_max 200000

int n ;
vector<vector<int>> g(n_max+5) ;
vector<bool> vis(n_max+5,0) ;
vector<int> p(n_max+5,0) ;
vector<int> clr(n_max+5) ;
int k=0 ;

void dfs(int v){
    vis[v]=1 ;
    int cnt=0 ;
    for (int u : g[v]) {
        if (!vis[u]) {
            p[u]=v ;
            ++cnt ;
            while (cnt==clr[v]||cnt==clr[p[v]]) {
                ++cnt ;
            }
            clr[u]=cnt ;
            k=max(k,cnt) ;
            dfs(u) ;
        }
    }
}

int main()
{
    scanf("%d",&n) ;
    for (int i=0;i<n-1;++i) {
        int x,y ;
        scanf("%d %d",&x,&y) ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    clr[1]=1, p[1]=0, clr[0]=0 ;
    dfs(1) ;
    printf("%d\n",k) ;
    for (int i=1;i<=n;++i) {
        printf("%d ",clr[i]) ;
    }
    return 0;
}
