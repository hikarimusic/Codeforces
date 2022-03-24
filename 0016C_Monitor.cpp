#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a,b,x,y ;

ll gcd(ll a, ll b) {
    return ( b ? gcd(b,a%b) : a ) ;
}

int main()
{
    scanf("%lld %lld %lld %lld",&a,&b,&x,&y) ;
    ll g=gcd(x,y) ;
    x/=g ;
    y/=g ;
    ll k=min(a/x,b/y) ;
    printf("%lld %lld",x*k,y*k) ;
    return 0;
}
