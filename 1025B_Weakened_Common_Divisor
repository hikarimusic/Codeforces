//Codeforces 1025B - Weakened Common Divisor

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void factorize(ll n, vector<ll>& fac) {
    if (n%2==0) {
        fac.push_back(2) ;
        while (n%2==0) n/=2 ;
    }
    for (ll i=3;i*i<=n;i+=2) {
        if (n%i!=0) continue ;
        fac.push_back(i) ;
        while (n%i==0) {
            n/=i ;
        }
    }
    if (n>1) fac.push_back(n) ;
}

int main()
{
    ll n, a, b ;
    scanf("%lld %lld %lld",&n,&a,&b) ;
    vector<ll> fac ;
    factorize(a, fac) ;
    factorize(b, fac) ;
    for (int i=0;i<n-1;++i) {
        scanf("%lld %lld",&a,&b) ;
        for (int j=0;j<fac.size();) {
            if (a%fac[j] == 0 || b%fac[j] == 0) {
                j+=1 ;
                continue ;
            }
            fac.erase(fac.begin()+j) ;
        }
    }
    if (fac.size()) printf("%lld",fac[0]) ;
    else printf("-1") ;
    return 0;
}
