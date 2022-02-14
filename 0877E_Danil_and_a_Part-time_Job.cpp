//Codeforces 877E - Danil and a Part-time Job

#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n,q ;
vector<vector<int>> G(MAXN) ;
int t[MAXN] ;
int cnt, in[MAXN], out[MAXN], dfn[MAXN] ;

void dfs (int v, int p) {
    in[v]=++cnt ;
    dfn[cnt]=v ;
    for (int u : G[v]) {
        if (u==p) continue ;
        dfs(u,v) ;
    }
    out[v]=cnt ;
}

struct T {
    int L, R ;
    int lazy, sum ;
} tree[MAXN*4] ;

void pushup (int v) {
    tree[v].sum=tree[2*v].sum+tree[2*v+1].sum ;
}

void pushdown (int v) {
    if (tree[v].lazy) {
        tree[2*v].lazy^=1 ;
        tree[2*v].sum=tree[2*v].R-tree[2*v].L+1-tree[2*v].sum ;
        tree[2*v+1].lazy^=1 ;
        tree[2*v+1].sum=tree[2*v+1].R-tree[2*v+1].L+1-tree[2*v+1].sum ;
        tree[v].lazy=0 ;
    }
}

void build (int v, int l, int r) {
    tree[v].L=l ;
    tree[v].R=r ;
    tree[v].lazy=0 ;
    if (l==r) {
        tree[v].sum=t[dfn[l]] ;
        return ;
    }
    build(2*v, l, (l+r)/2) ;
    build(2*v+1, (l+r)/2+1, r) ;
    pushup(v) ;
}

void update (int v, int l, int r) {
    if (tree[v].L>r || tree[v].R<l) return ;
    if (tree[v].L>=l && tree[v].R<=r) {
        tree[v].lazy^=1 ;
        tree[v].sum=tree[v].R-tree[v].L+1-tree[v].sum ;
        return ;
    }
    pushdown(v) ;
    if (tree[2*v].R>=l) update(2*v,l,r) ;
    if (tree[2*v+1].L<=r) update(2*v+1,l,r) ;
    pushup(v) ;
}

int query (int v, int l, int r) {
    if (tree[v].L>r || tree[v].R<l) return 0 ;
    if (tree[v].L>=l && tree[v].R<=r) return tree[v].sum ;
    pushdown(v) ;
    int ans=0 ;
    if (tree[2*v].R>=l) ans+=query(2*v,l,r) ;
    if (tree[2*v+1].L<=r) ans+=query(2*v+1,l,r) ;
    pushup(v) ;
    return ans ;
}

int main()
{
    scanf("%d",&n) ;
    for (int i=2;i<=n;++i) {
        int x ;
        scanf("%d",&x) ;
        G[i].push_back(x) ;
        G[x].push_back(i) ;
    }
    for (int i=1;i<=n;++i) scanf("%d",&t[i]) ;
    dfs(1,-1) ;
    build(1,1,n) ;
    scanf("%d",&q) ;
    while(q--) {
        string op ;
        int x ;
        cin>>op>>x ;
        if (op=="pow") update(1,in[x],out[x]) ;
        else printf("%d\n",query(1,in[x],out[x])) ;
    }
    return 0;
}
