#include <bits/stdc++.h>
using namespace std;
#define n_max 1000

int n,m ;
bool mp[n_max+5][n_max+5] ;
int vis[n_max+5][n_max+5][5] ;
int dx[4]={1,-1,0,0} ;
int dy[4]={0,0,1,-1} ;

struct point {
    int x,y,dir,cnt ;
}s,t,u,v ;

bool bfs() {
    for (int i=0;i<n+5;++i) 
    for (int j=0;j<m+5;++j) 
    for (int k=0;k<5;++k) 
    vis[i][j][k]=5 ;
    queue<point> q ;
    s.dir=-1 ;
    s.cnt=0 ;
    q.push(s) ;
    while (!q.empty()) {
        v=q.front() ;
        q.pop() ;
        if (v.x==t.x && v.y==t.y) return 1 ;
        for (int i=0;i<4;++i) {
            u.x=v.x+dx[i] ;
            u.y=v.y+dy[i] ;
            u.dir=i ;
            if (v.dir==-1) u.cnt=0 ;
            else if (v.dir==i) u.cnt=v.cnt ;
            else if (v.dir!=i) u.cnt=v.cnt+1 ;
            if (u.x<0||u.y<0) continue ;
            if (!mp[u.x][u.y]||u.cnt>2) continue ;
            if (vis[u.x][u.y][u.dir]<=u.cnt) continue ;
            vis[u.x][u.y][i]=u.cnt ;
            q.push(u) ;
        }
    }
    return 0 ;
}

int main()
{
    scanf("%d %d",&n,&m) ;
    for (int i=0;i<n;++i) {
        string seq ;
        cin>>seq ;
        for (int j=0;j<m;++j) {
            if (seq[j]!='*') mp[i][j]=1 ;
            if (seq[j]=='S') s.x=i,s.y=j ;
            if (seq[j]=='T') t.x=i,t.y=j ;
        }
    }
    printf("%s",bfs()?"YES":"NO") ;
    return 0;
}


