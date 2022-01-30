//Codeforces 25D - Roads not only in Berland

#include <bits/stdc++.h>
using namespace std;
#define n_max 1000

int n ;
vector<int> par(n_max+5) ;
vector<int> siz(n_max+5,1) ;
vector<int> cls ;
vector<int> bld ;

void mak(int v) {
    par[v]=v ;
}

int fnd(int v) {
    if (v==par[v]) return v ;
    par[v]=fnd(par[v]) ;
    return par[v] ;
}

void uni(int v, int u) {
    v=fnd(v) ;
    u=fnd(u) ;
    if (v!=u) {
        if (siz[v]<siz[u]) swap(v,u) ;
        par[u]=v ;
        siz[v]+=siz[u] ;
    }
}

int main()
{
    scanf("%d",&n) ;
    for (int i=1;i<=n;++i) mak(i) ;
    for (int i=1;i<n;++i) {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        if (fnd(a)==fnd(b)) {
            cls.push_back(a) ;
            cls.push_back(b) ;
        }
        uni(a,b) ;
    }
    for (int i=2;i<=n;++i) {
        if (fnd(1)!=fnd(i)) {
            bld.push_back(1) ;
            bld.push_back(i) ;
            uni(1,i) ;
        }
    }
    int t=cls.size()/2 ;
    printf("%d\n",t) ;
    for (int i=0;i<t;++i) {
        printf("%d %d ",cls[2*i],cls[2*i+1]) ;
        printf("%d %d\n",bld[2*i],bld[2*i+1]) ;
    }
    return 0;
}
