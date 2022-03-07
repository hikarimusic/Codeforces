//Codeforces 466C - Number of Ways

#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define MAXN 500005

ll n, s[MAXN] ;

int main() {
    scanf("%lld",&n) ;
    ll a ;
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a) ;
        s[i]=s[i-1]+a ;
    }
    if (s[n]%3!=0) printf("%d",0) ;
    else {
        ll q1=s[n]/3 ,q2=s[n]*2/3 ;
        ll cnt=0, ans=0 ;
        for (int i=1;i<n;++i) {
            if (s[i]==q2) ans+=cnt ;
            if (s[i]==q1) cnt+=1 ;
        }
        printf("%lld",ans) ;
    }
    return 0 ;
}
