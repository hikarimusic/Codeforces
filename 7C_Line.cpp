//Codeforces 7C - Line

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x=1 ;
        y=0 ;
        return a ;
    }
    ll x1, y1, g ;
    g=exgcd(b,a%b,x1,y1) ;
    x=y1 ;
    y=x1-y1*(a/b) ;
    return g ;
}

int main()
{
    ll A,B,C ;
    scanf("%lld %lld %lld",&A,&B,&C) ;
    ll g,x,y ;
    g=exgcd(A,B,x,y) ;
    if (C%g==0) printf("%lld %lld",-x*C/g,-y*C/g) ;
    else printf("%d",-1) ;
    return 0;
}
