#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define EPS 0.001

double x[3],y[3],dis[3],ang[3] ;

bool feq(double a, double b) {
    return fabs(a-b)<EPS ;
}

double fgcd(double a, double b) {
    if (feq(a,0)) return b ;
    if (feq(b,0)) return a ;
    return fgcd(b,fmod(a,b)) ;
}

int main()
{
    for (int i=0;i<3;++i) scanf("%lf %lf",&x[i],&y[i]) ;
    for (int i=0;i<3;++i) {
        double dx=x[i]-x[(i+1)%3] ;
        double dy=y[i]-y[(i+1)%3] ;
        dis[i]=sqrt(dx*dx+dy*dy) ;
    }
    for (int i=0;i<3;++i) {
        double a=dis[i] ;
        double b=dis[(i+1)%3] ;
        double c=dis[(i+2)%3] ;
        ang[i]=2*acos((b*b+c*c-a*a)/(2*b*c)) ;
    }
    double min_ang=fgcd(ang[0],fgcd(ang[1],ang[2])) ;
    double R=dis[0]/(2*sin(ang[0]/2)) ;
    double ans=(2*PI/min_ang)*R*R*sin(min_ang)/2 ;
    printf("%.8lf",ans) ;
    return 0;
}
