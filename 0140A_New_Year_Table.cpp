#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

double n,R,r ;

double round_6 (double a) {
    return round(a*1000000)/1000000 ;
}

int main()
{
    scanf("%lf %lf %lf",&n,&R,&r) ;
    if (r<=R/2) {
        double m=round_6(PI/asin(r/(R-r))) ;
        printf("%s",(n<=m)?"YES":"NO") ;
    }
    if (r>R/2 && r<=R) {
        printf("%s",(n<=1)?"YES":"NO") ;
    }
    if (r>R) printf("%s","NO") ;
    return 0;
}
