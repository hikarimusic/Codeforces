//Codeforces 71C - Round Table Knights

#include <bits/stdc++.h>
using namespace std;
#define n_max 100000

int n ;
int a[n_max+5] ;

bool good(int i) {
    if (i==n) return 0 ;
    if (n%2==0 && i==n/2) return 0 ;
    for (int j=0;j<i;++j) {
        bool ans=1 ;
        for (int k=0;k<n/i;++k) {
            if (a[(j+k*i)%n]==0) {
                ans=0 ;
                
                
                
                break ;
            }
        }
        if (ans==1) return 1 ;
    }
    return 0 ;
} 

int main()
{
    scanf("%d",&n) ;
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]) ;
    }
    bool ans=0 ;
    for (int i=1;i*i<=n;++i) {
        if (n%i==0) {
            if (good(i) || good(n/i)) {
                ans=1 ;
                break ;
            }
        }
    }
    printf("%s",(ans?"YES":"NO")) ;
    return 0;
}
