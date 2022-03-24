#include <bits/stdc++.h>
using namespace std;

int n ;

int main()
{
    scanf("%d",&n) ;
    if (n==2) printf("%d",-1) ;
    else {
        for (int i=1;i<=n-2;++i) {
            printf("%d\n",2*3*i) ;
        }
        printf("%d\n",2*5) ;
        printf("%d\n",3*5) ;
    }

    return 0;
}
