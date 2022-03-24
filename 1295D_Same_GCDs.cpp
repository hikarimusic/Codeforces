#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd (ll a, ll b) {
    return b ? gcd(b,a%b) : a ;
}

ll phi (ll n) {
    ll ans=n ;
    for (ll i=2;i*i<=n;++i) {
        if (n%i==0) {
            ans-=ans/i ;
            while (n%i==0) n/=i ;
        }
    }
    if (n>1) {
        ans-=ans/n ;
    }
    return ans ;
}

int main()
{
    int T ;
    scanf("%d",&T) ;
    for (int i=0;i<T;++i) {
        ll a, m, g ;
        scanf("%lld %lld",&a,&m) ;
        g=gcd(a,m) ;
        cout<<phi(m/g)<<'\n' ;
    }
    return 0;
}
