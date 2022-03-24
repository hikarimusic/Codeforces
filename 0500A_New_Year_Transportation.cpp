#include <bits/stdc++.h>
using namespace std ;
#define MAXN 30005

int n,t ;
int a[MAXN] ;

int main() {
    scanf("%d %d",&n,&t) ;
    for (int i=1;i<=n-1;++i) scanf("%d",&a[i]) ;
    int c=1 ;
    while (c<t) c+=a[c] ;
    printf("%s",(c==t)?"YES":"NO") ;
    return 0 ;
}
