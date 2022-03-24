#include <bits/stdc++.h>
using namespace std ;
#define MAXN 305
#define ll long long

ll n,k ;
ll d[MAXN][MAXN] ;

int main() {
    scanf("%lld",&n) ;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%lld",&d[i][j]) ;
        }
    }
    scanf("%lld",&k) ;
    while (k--) {
        ll a,b,c ;
        scanf("%lld %lld %lld",&a,&b,&c) ;
        ll s=0 ;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                d[i][j]=min(d[i][j],d[i][a]+c+d[b][j]) ;
                d[i][j]=min(d[i][j],d[i][b]+c+d[a][j]) ;
                if (j>i) s+=d[i][j] ;
            }
        }
        printf("%lld ",s) ;
    }
}
