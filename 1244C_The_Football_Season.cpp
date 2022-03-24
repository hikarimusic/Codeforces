#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x=1 ;
        y=0 ;
        return a ;
    }
    ll g,x1,y1 ;
    g=gcd(b,a%b,x1,y1) ;
    x=y1 ;
    y=x1-(a/b)*y1 ;
    return g ; 
}

int main() 
{
    ll n,p,w,d ;
    scanf("%lld %lld %lld %lld",&n,&p,&w,&d) ;
    ll g,x0,y0 ;
    g=gcd(w,d,x0,y0) ;
    if (p%g==0) {
        ll x,y,m ;
        m=w/g ;
        y=( (y0%m)*((p/g)%m)%m+m)%m ;
        x=(p-y*d)/w ;
        if (x>=0 && y>=0 && x+y<=n) {
            printf("%lld %lld %lld",x,y,n-x-y) ;
            return 0 ;
        }
    }
    printf("-1") ;
    return 0 ;
}
