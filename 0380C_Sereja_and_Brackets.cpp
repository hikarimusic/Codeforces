#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005

char s[MAXN] ;
int n, m ;

struct T {
    int L, R ;
    int cor, opn, cls ;
} tree[MAXN*4] ;

T combine(T a, T b) {
    T c ;
    c.L=a.L ;
    c.R=b.R ;
    int t=min(a.opn, b.cls) ;
    c.cor=a.cor+b.cor+2*t ;
    c.opn=a.opn+b.opn-t ;
    c.cls=a.cls+b.cls-t ;
    return c ;
}

void build(int v, int l, int r) {
    tree[v].L=l ;
    tree[v].R=r ;
    if (l==r) {
        tree[v].cor=0 ;
        tree[v].opn= (s[l]=='(') ? 1 : 0 ;
        tree[v].cls= (s[l]==')') ? 1 : 0 ;
        return ;
    }
    build(v*2,l,(l+r)/2) ;
    build(v*2+1,(l+r)/2+1,r) ;
    tree[v]=combine(tree[2*v],tree[2*v+1]) ;
}

T quiry(int v, int l, int r) {
    if (tree[v].L>r || tree[v].R<l) {
        T res ;
        res.cor=res.opn=res.cls=0 ;
        return res ;
    }
    if (tree[v].L>=l && tree[v].R<=r) {
        T res ;
        res.cor=tree[v].cor ;
        res.opn=tree[v].opn ;
        res.cls=tree[v].cls ;
        return res ;
    }
    return combine(quiry(2*v,l,r), quiry(2*v+1,l,r) ) ;
}

int main()
{
    scanf("%s",s+1) ;
    n=strlen(s+1) ;
    build(1,1,n) ;
    scanf("%d",&m) ;
    while (m--) {
        int l,r ;
        scanf("%d %d",&l,&r) ;
        printf("%d\n",quiry(1,l,r).cor) ;
    }
    return 0;
}
