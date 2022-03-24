#include <bits/stdc++.h>
using namespace std;
#define n_max 200000

int n ;
vector<vector<int>> g(n_max+5) ;
vector<int> seq ;
vector<int> ord(n_max+5) ;
vector<int> p ;

bool com(int a, int b) {
    return ord[a]<ord[b] ;
}

void bfs(int s) {
    queue<int> q ;
    vector<bool> u(n+1,0) ;
    u[s]=1 ;
    q.push(s) ;
    p.push_back(s) ;
    while (!q.empty()) {
        int v=q.front() ;
        q.pop() ;
        for (int w : g[v]) {
            if (!u[w]) {
                u[w]=1 ;
                q.push(w) ;
                p.push_back(w) ;
            }
        }
    }
}

int main()
{
    scanf("%d",&n) ;
    for (int t=0;t<n-1;++t) {
        int x,y ;
        scanf("%d %d",&x,&y) ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    for (int i=0;i<n;++i) {
        int x ;
        scanf("%d",&x) ;
        seq.push_back(x) ;
        ord[x]=i ;
    }
    for (int i=1;i<=n;++i) {
        sort(g[i].begin(),g[i].end(),com) ;
    }
    bfs(1) ;
    bool ans=1 ;
    for (int i=0;i<n;++i) {
        if (p[i]!=seq[i]) {
            ans=0 ;
            break ;
        }
    }
    printf("%s",ans?"Yes":"No") ;
    return 0;
}
