//Codeforces 1117D - Magic Gems

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007 ;

void mat_init(ll A[100][100], ll M) {
    for (int i=0;i<100;++i) {
        for (int j=0;j<100;++j) {
            A[i][j]=0 ;
        }
    }
    for (int i=0; i<99;++i) {
        A[i][i+1]=1 ;
    }
    A[0][0]=1 ;
    A[M-1][0]=1 ;
}

void mat_mul(ll A[100][100], ll B[100][100]) {
    ll res[100][100] ;
    for (int i=0;i<100;++i) {
        for (int j=0;j<100;++j) {
            res[i][j]=0 ;
            for (int k=0;k<100;++k) {
                res[i][j]+=A[i][k]*B[k][j] ;
                res[i][j]%=mod ;
            }
        }
    }
    for (int i=0;i<100;++i) {
        for (int j=0;j<100;++j) {
            A[i][j]=res[i][j] ;
        }
    }
}

void mat_pow(ll A[100][100], ll n) {
    ll res[100][100] ;
    for (int i=0;i<100;++i) {
        for (int j=0;j<100;++j) {
            res[i][j]=0 ;
        }
        res[i][i]=1 ;
    }
    while (n) {
        if (n&1) {
            mat_mul(res,A) ;
        }
        mat_mul(A,A) ;
        n>>=1 ;
    }
    for (int i=0;i<100;++i) {
        for (int j=0;j<100;++j) {
            A[i][j]=res[i][j] ;
        }
    }
}

int main()
{
    ll N, M ;
    scanf("%lld %lld",&N,&M) ;
    ll A[100][100] ;
    mat_init(A,M) ;
    mat_pow(A,N) ;
    printf("%lld",A[0][0]) ;
    return 0;
}
