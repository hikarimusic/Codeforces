//Codeforces 722C - Destroying Array

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long

int n, a[MAXN], s[MAXN] ;
int p[MAXN] ;
ll sum[MAXN] ;
bool exist[MAXN] ;
vector<ll> ans ;

int find_set(int v) {
    if (p[v]==v) return v ;
    return p[v]=find_set(p[v]) ;
}

void union_set(int v, int u) {
    int pv=find_set(v) ;
    int pu=find_set(u) ;
    if (pv!=pu) {
        p[u]=v ;
        sum[v]+=sum[u] ;
    }
}

int main()
{
    scanf("%d",&n) ;
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]) ;
        p[i]=i ;
        sum[i]=a[i] ;
    }
    for (int i=1;i<=n;++i) scanf("%d",&s[i]) ;
    ll M=0 ;
    ans.push_back(0) ;
    for (int i=n;i>=1;--i) {
        int x=s[i] ;
        exist[x]=1 ;
        if (exist[x-1]) union_set(x,find_set(x-1)) ;
        if (exist[x+1]) union_set(x,find_set(x+1)) ;
        M=max(M,sum[x]) ;
        ans.push_back(M) ;
    }
    for (int i=n-1;i>=0;--i) printf("%lld\n",ans[i]) ;
    return 0;
}
