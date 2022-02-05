//Codeforces 117B - Very Interesting Game

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a, b, mod ;

void prst(ll n) {
    ll k=100000000 ;
    for (int i=0;i<9;++i) {
        printf("%lld",(n/k)%10) ;
        k/=10 ;
    }
}

int main()
{
    scanf("%lld %lld %lld",&a,&b,&mod) ;
    bool win=0 ;
    ll i ;
    for (i=0;i<=a && i<mod;++i) {
        if ( b< ((mod-i*1000000000%mod)%mod+mod)%mod ) {
            win=1 ;
            break ;
        }
    }
    if (win) {
        printf("%d ",1) ;
        prst(i) ;
    }
    else printf("%d",2) ;
    return 0;
}
