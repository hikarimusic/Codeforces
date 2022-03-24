#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

int n ;
vector<double> a ;

int main()
{
    scanf("%d",&n) ;
    for (int i=0;i<n;++i) {
        double x,y ;
        scanf("%lf %lf",&x,&y) ;
        a.push_back(atan2(y,x)) ;
    }
    sort(a.begin(),a.end()) ;
    a.push_back(a[0]+2*PI) ;
    double ans=2*PI ;
    for (int i=0;i<n;++i) {
        ans=min(ans,2*PI-(a[i+1]-a[i])) ;
    }
    printf("%.10lf",ans*180/PI) ;
    return 0;
}
