//Codeforces 28B - pSort

#include <bits/stdc++.h>
using namespace std;
#define n_max 100

int n ;
vector<int> pmt(n_max+5) ;
vector<int> fav(n_max+5) ;

vector<int> par(n_max+5) ;
vector<int> siz(n_max+5) ;

void mak(int v) {
    par[v]=v ;
    siz[v]=1 ;
}

int fnd(int v) {
    if (v==par[v]) return v ;
    par[v]=fnd(par[v]) ;
    return par[v] ;
}

void uni(int a, int b) {
    a=fnd(a) ;
    b=fnd(b) ;
    if (a!=b) {
        if (siz[a]<siz[b]) swap(a,b) ;
        par[b]=a ;
    }
}

int main()
{
    scanf("%d",&n) ;
    for (int i=1;i<=n;++i) scanf("%d",&pmt[i]) ;
    for (int i=1;i<=n;++i) scanf("%d",&fav[i]) ;
    for (int i=1;i<=n;++i) mak(i) ;
    for (int i=1;i<=n;++i) {
        if (i-fav[i]>=1) uni(i,i-fav[i]) ;
        if (i+fav[i]<=n) uni(i,i+fav[i]) ;
    }
    bool ans=1 ;
    for (int i=1;i<=n;++i) {
        if (fnd(pmt[i])!=fnd(i)) {
            ans=0 ;
            break ;
        }
    }
    printf("%s",ans?"YES":"NO") ;
    return 0;
}
