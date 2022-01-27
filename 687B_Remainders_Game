//Codeforces 687B - Remainders Game

#include <bits/stdc++.h>
using namespace std;
#define c_max 1000000

vector<int> lp(c_max+5,0) ;
vector<int> pr ;

void lin_sieve(int N) {
    for (int i=2;i<=N;++i) {
        if (lp[i]==0) {
            lp[i]=i ;
            pr.push_back(i) ;
        }
        for (int j=0;j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N;++j) {
            lp[i*pr[j]]=pr[j] ;
        }
    }
}

int main()
{
    lin_sieve(c_max) ;
    int n,k,c ;
    scanf("%d %d",&n,&k) ;
    vector<int> fac(c_max+5,0) ;
    for (int t=0;t<n;++t) {
        scanf("%d",&c) ;
        while (c>1) {
            int p=lp[c] ;
            int q=0 ;
            while (c%p==0) {
                ++q ;
                c/=p ;
            }
            if (q>fac[p]) fac[p]=q ;
        }
    }
    bool ans=1 ;
    while (k>1) {
        --fac[lp[k]] ;
        if (fac[lp[k]]<0) {
            ans=0 ;
            break ;
        }
        k/=lp[k] ;
    }
    printf("%s",ans?"Yes":"No") ;
    return 0;
}
