#include <bits/stdc++.h>
using namespace std ;
#define MAXN 205

int n ;
vector<vector<int>> g(MAXN) ;
int sum ;

int dfs(int u, int f, int a, int b) {
    int l1=0, l2=0 ;
    for (int v : g[u]) {
        if (v==f) continue ;
        if (u==a && v==b) continue ;
        if (u==b && v==a) continue ;
        int l=1+dfs(v,u,a,b) ;
        if (l>l1) l2=l1, l1=l ;
        else if (l>l2) l2=l ;
    }
    sum=max(sum,l1+l2) ;
    return l1 ;
}

int main() {
    scanf("%d",&n) ;
    for (int i=0;i<n-1;++i) {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }
    int ans=0 ;
    for (int i=1;i<=n;++i) {
        for (int j : g[i]) {
            int a,b ;
            if (j<i) continue ;
            sum=0, dfs(i,0,i,j), a=sum ;
            sum=0, dfs(j,0,i,j), b=sum ;
            ans=max(ans,a*b) ;
        }
    }
    printf("%d",ans) ;
}
