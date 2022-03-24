#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b) {
    return b ? gcd(b,a%b) : a ;
}

void factorize(vector<ll>& fac, ll g) {
    for (int i=1;i*i<=g;++i) {
        if (g%i==0) {
            fac.push_back(i) ;
            fac.push_back(g/i) ;
        }
    }
    sort(fac.begin(),fac.end()) ;
}

ll search(vector<ll> fac, ll low, ll high) {
    ll l=0, h=fac.size()-1, ans=-1 ;
    while (l<=h) {
        ll m=l+(h-l)/2 ;
        if (fac[m]>high) h=m-1 ;
        else {
            ans=fac[m] ;
            l=m+1 ;
        }
    }
    if (ans>=low) return ans ;
    return -1 ;
}

int main()
{
    ll a,b,n,low,high,g ;
    vector<ll> fac ;
    scanf("%lld %lld",&a,&b) ;
    g=gcd(a,b) ;
    factorize(fac,g) ;
    scanf("%lld",&n) ;
    for (int i=0;i<n;++i) {
        scanf("%lld %lld",&low,&high) ;
        printf("%lld\n",search(fac,low,high)) ;
    }
    return 0;
}
