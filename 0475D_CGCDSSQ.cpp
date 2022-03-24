#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 100005
#define pmax 20

int n,q ;
ll a[nmax] ;
ll st[nmax][pmax] ;
unordered_map<ll,ll> ans ;

ll gcd(ll a,ll b) {
    return (b==0) ? a : gcd(b,a%b) ;
}

void st_build() {
    int k= (int)log2(n) ;
    for (int i=0;i<n;++i) st[i][0]=a[i] ;
    for (int j=1;j<=k;++j) {
        for (int i=0;i+(1<<j)<=n;++i) {
            st[i][j]=gcd(st[i][j-1], st[i+(1<<(j-1))][j-1] ) ;
        } 
    }
}

ll st_quiry(ll L, ll R) {
    int j= (int)log2(R-L+1) ;
    return gcd(st[L][j], st[R-(1<<j)+1][j] ) ;
}

void ans_count() {
    ll L, R1, R2 ;
    for (L=0;L<n;++L) {
        R1=L ;
        while (R1<n) {
            ll now=st_quiry(L,R1) ;
            ll low=R1, high=n-1, mid ;
            while (low<=high) {
                mid=(low+high)/2 ;
                if (st_quiry(L,mid)==now) {
                    R2=mid ;
                    low=mid+1 ;
                }
                else high=mid-1 ;
            }
            ans[now]+=R2-R1+1 ;
            R1=R2+1 ;
        }
    }
}

int main()
{
    scanf("%d",&n) ;
    for (int i=0;i<n;++i) scanf("%lld",&a[i]) ;
    st_build() ;
    ans_count() ;
    scanf("%d",&q) ;
    for (int i=0;i<q;++i) {
        ll x ;
        scanf("%lld",&x) ;
        printf("%lld\n",ans[x]) ;
    }
    return 0;
}
