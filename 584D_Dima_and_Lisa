//Codeforces 584D - Dima and Lisa

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_prime(ll n) {
    for (int i=2;i*i<=n;++i) {
        if (n%i==0) return false ;
    }
    return true ;
}

int main()
{
    ll n ;
    scanf("%lld",&n) ;
    if (is_prime(n)) printf("1\n%lld",n) ;
    else if (is_prime(n-2)) printf("2\n%lld 2",n-2) ;
    else if (is_prime(n-4)) printf("3\n%lld 2 2",n-4) ;
    else {
        ll a=n-6, b=3 ;
        while (a){
            if (is_prime(a)) break ;
            a-=2 ;
        }
        while (b) {
            if (is_prime(b) && is_prime(n-a-b)) {
                printf("3\n%lld %lld %lld",a,b,n-a-b) ;
                break ;
            }
            b+=2 ;
        }
    }
    return 0;
}
