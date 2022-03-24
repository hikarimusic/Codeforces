#include <bits/stdc++.h>
using namespace std;
#define n_max 100000

int d[n_max+5] ;

int main()
{
    int n,x,y ;
    scanf("%d",&n) ;
    for (int i=1;i<=n;++i) {
        int ans=0 ;
        scanf("%d %d",&x,&y) ;
        for (int k=1;k*k<=x;++k) {
            if (x%k==0) {
                if ( (i-y)>d[k] ) ++ans ;
                if ( k*k!=x && (i-y)>d[x/k] ) ++ans ; 
                d[k]=d[x/k]=i ;
            }
        }
        printf("%d\n",ans) ;
    }
    return 0;
}
