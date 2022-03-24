#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, bool> mp ;

int bfs (pair<int,int> a, pair<int,int> b) {
    map<pair<int,int>,int> d ;
    map<pair<int,int>,bool> u ;
    queue<pair<int,int>> q ;
    d[a]=0 ;
    u[a]=1 ;
    q.push(a) ;
    int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}} ;
    while (!q.empty()) {
        pair<int,int> x=q.front() ;
        q.pop() ;
        for (int i=0;i<8;++i) {
            pair<int,int> y=make_pair(x.first+dir[i][0], x.second+dir[i][1]) ;
            if (mp[y] && !u[y]) {
                d[y]=d[x]+1 ;
                u[y]=1 ;
                q.push(y) ;
            }
        }
    }
    return (u[b] ? d[b] : -1 ) ;
}

int main()
{
    int x0,y0,x1,y1,n ;
    scanf("%d %d %d %d %d",&x0,&y0,&x1,&y1,&n) ;
    mp[make_pair(x0,y0)]=1 ;
    mp[make_pair(x1,y1)]=1 ;
    for (int i=0;i<n;++i) {
        int r,a,b ;
        scanf("%d %d %d",&r,&a,&b) ;
        for (int j=a;j<=b;++j) {
            mp[make_pair(r,j)]=1 ;
        }
    }
    printf("%d",bfs(make_pair(x0,y0),make_pair(x1,y1)) ) ;
    return 0;
}
