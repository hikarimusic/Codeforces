#include <bits/stdc++.h>
using namespace std ;

int n,m ;

int main() {
    scanf("%d %d",&n,&m) ;
    int c=0 ;
    while (m>n) {
        if (m&1) {
            m+=1 ;
            c++ ;
        }
        m/=2 ;
        c++ ;
    }
    c+=(n-m) ;
    printf("%d",c) ;
    return 0 ;
}
