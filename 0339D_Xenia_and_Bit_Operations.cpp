#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int n,m ;
int a[MAXN], t[4*MAXN] ;

void build(int v, int tl, int tr, bool f) {
    if (tl==tr) t[v]=a[tl] ;
    else {
        int tm=(tl+tr)/2 ;
        build(v*2, tl, tm, f^1) ;
        build(v*2+1, tm+1, tr, f^1) ;
        t[v]= f ? (t[v*2]|t[v*2+1]) : (t[v*2]^t[v*2+1]) ;
    }
}

void update(int v, int tl, int tr, bool f, int pos, int val) {
    if (tl==tr) t[v]=val ;
    else {
        int tm=(tl+tr)/2 ;
        if (pos<=tm) update(v*2,tl,tm,f^1,pos,val) ;
        else update(v*2+1,tm+1,tr,f^1,pos,val) ;
        t[v]= f ? (t[v*2]|t[v*2+1]) : (t[v*2]^t[v*2+1]) ;
    }
}

int main()
{
    scanf("%d %d",&n,&m) ;
    int N=(1<<n) ;
    for (int i=0;i<N;++i) scanf("%d",&a[i]) ;
    build(1,0,N-1,n&1) ;
    for (int i=0;i<m;++i) {
        int p,b ;
        scanf("%d %d",&p,&b) ;
        update(1,0,N-1,n&1,p-1,b) ;
        printf("%d\n",t[1]) ;
    }
    return 0;
}
