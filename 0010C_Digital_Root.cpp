//Codeforces 10C - Digital Root

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, a[9], ans ;

int main()
{
    scanf("%lld",&N) ;
    for (int i=1;i<=N;++i) {
        a[i%9]+=1 ;
    }
    for (int i=0;i<9;++i) {
        for (int j=0;j<9;++j) {
            ans+=a[i]*a[j]*a[i*j%9] ;
        }
    }
    for (int i=1;i<=N;++i) {
        ans-=N/i ;
    }
    printf("%lld",ans) ;
    return 0;
}
