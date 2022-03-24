#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool win(ll n, ll m, ll k) {
    if (n%2==1) {
        if (m!=1 && k==1) return 1 ;
        for (int i=2;i*i<=m;++i) {
            if (m%i==0) {
                if (i>=k || (m/i)>=k) return 1 ;
            }
        }
    }
    return 0 ;
}

int main()
{
    ll n,m,k ;
    scanf("%lld %lld %lld",&n,&m,&k) ;
    printf("%s",win(n,m,k)?"Timur":"Marsel") ;
    return 0;
}
