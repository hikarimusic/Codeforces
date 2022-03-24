#include <bits/stdc++.h>
using namespace std;
#define n_max 300000 
#define a_max 15000000 

vector<int> lp(a_max+5,0) ;

void lin_sieve(int N) {
    vector<int> pr ;
    for (int i=2;i<=N;++i) {
        if (lp[i]==0) {
            lp[i]=i ;
            pr.push_back(i) ;
        }
        for (int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j ) {
            lp[i*pr[j]]=pr[j] ;
        }
    }
}

int gcd(int a, int b) {
    if (b==0) return a ;
    return gcd(b,a%b) ;
}

int main()
{
    lin_sieve(a_max) ;
    int n ;
    scanf("%d",&n) ;
    vector<int> a(n) ;
    int g=0 ;
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]) ;
        g=gcd(a[i],g) ;
    }
    vector<int> fac(a_max+5, 0) ;
    for (int i=0;i<n;++i) {
        a[i]/=g ;
        while (a[i]>1) {
            int x=lp[a[i]] ;
            fac[x]+=1 ;
            while (a[i]%x==0) a[i]/=x ;
        }
    }
    int m=0 ;
    for (int i=0;i<fac.size();++i) {
        m=(fac[i]>m)?fac[i]:m ;
    }
    if (m>0) printf("%d",n-m) ;
    else printf("-1") ;
    return 0;
}
