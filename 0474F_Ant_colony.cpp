#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define pii pair<int,int>

int n, t, s[MAXN] ;

struct T {
    int L, R ;
    pii gcd ;
} tree[MAXN*4] ;

pii combine(pii a, pii b) {
    int G=__gcd(a.first,b.first) ;
    int N=0 ;
    if (G==a.first) N+=a.second ;
    if (G==b.first) N+=b.second ;
    return {G,N} ;
}

void build(int v, int l, int r) {
    tree[v].L=l ;
    tree[v].R=r ;
    if (l==r) {
        tree[v].gcd={s[l],1} ;
        return ;
    }
    build(2*v, l, (l+r)/2) ;
    build(2*v+1, (l+r)/2+1, r) ;
    tree[v].gcd=combine(tree[2*v].gcd,tree[2*v+1].gcd) ;
}

pii query(int v, int l, int r) {
    if (tree[v].L>r || tree[v].R<l) return {0,0} ;
    if (tree[v].L>=l && tree[v].R<=r) return tree[v].gcd ;
    return combine(query(2*v,l,r),query(2*v+1,l,r)) ;
}

int main()
{
    scanf("%d",&n) ;
    for (int i=1;i<=n;++i) scanf("%d",&s[i]) ;
    build(1,1,n) ;
    scanf("%d",&t) ;
    while (t--) {
        int l,r ;
        scanf("%d %d",&l,&r) ;
        printf("%d\n",r-l+1-query(1,l,r).second) ;
    }
    return 0;
}
