#include <bits/stdc++.h>
using namespace std;
#define c_max 10000000

vector<int> lp(c_max+5,0) ;
vector<int> sum(c_max+5,1) ;
vector<int> ans(c_max+5,-1) ;

void lin_sieve() {
    int N=c_max ;
    vector<int> pr ;
    for (int i=2;i<=N;++i) {
        if (lp[i]==0) {
            lp[i]=i ;
            pr.push_back(i) ;
        }
        for (int j=0 ; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N ; ++j) {
            lp[i*pr[j]]=pr[j] ;
        }
    }
}

void cal_sum() {
    int N=c_max;
    for (int i=2;i<=N;++i) {
        int j=i ;
        while (j%lp[i]==0) {
            sum[i]=sum[i]*lp[i]+1 ;
            j/=lp[i] ;
        }
        sum[i]*=sum[j] ;
    }
}

void cal_ans() {
    int N=c_max ;
    for (int i=N;i>0;--i) {
        if (sum[i]<=N) ans[sum[i]]=i ;
    }
}

int main()
{
    lin_sieve() ;
    cal_sum() ;
    cal_ans() ;
    int t ;
    scanf("%d",&t) ;
    for (int i=0;i<t;++i) {
        int c ;
        scanf("%d",&c) ;
        printf("%d\n",ans[c]) ;
    }
    return 0;
}
