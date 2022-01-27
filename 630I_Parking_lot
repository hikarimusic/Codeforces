//Codeforces 630I - Parking lot

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binpow(ll a, ll b)
{
    long long r=1 ;
    while(b) {
        if (b&1) r*=a ;
        a*=a ;
        b>>=1 ;
    }
    return r ;
}

int main()
{
    ll n ;
    scanf("%lld",&n) ;
    printf("%lld",(9*n-3)*binpow(4,n-3)) ;
    return 0;
}
