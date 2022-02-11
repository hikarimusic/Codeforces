//Codeforces 689D - Friends and Subsequences

#include <bits/stdc++.h>
using namespace std;
#define nmax 200005
#define pmax 20
#define ll long long

int n ;
ll a[nmax], b[nmax] ;
ll sta[nmax][pmax] ;
ll stb[nmax][pmax] ;

void sta_build() {
    for (int i=0;i<n;++i) sta[i][0]=a[i] ;
    int k=(int)log2(n)+1 ;
    for (int j=1;j<=k;++j) {
        for (int i=0;i+(1<<j)<=n;++i) {
            sta[i][j]=max(sta[i][j-1], sta[i+(1<<(j-1))][j-1]) ;
        }
    }
}

void stb_build() {
    for (int i=0;i<n;++i) stb[i][0]=b[i] ;
    int k=(int)log2(n)+1 ;
    for (int j=1;j<=k;++j) {
        for (int i=0;i+(1<<j)<=n;++i) {
            stb[i][j]=min(stb[i][j-1], stb[i+(1<<(j-1))][j-1]) ;
        }
    }
}

ll sta_quiry(int L, int R) {
    int k=(int)log2(R-L+1) ;
    return max(sta[L][k],sta[R-(1<<k)+1][k]) ;
}

ll stb_quiry(int L, int R) {
    int k=(int)log2(R-L+1) ;
    return min(stb[L][k],stb[R-(1<<k)+1][k]) ;
}

ll ans_count() {
    ll ans=0 ;
    for (int i=0;i<n;++i) {
        int P1=i-1, P2=n ;
        int L=i, R=n-1, M ;
        while (L<=R) {
            M=(L+R)/2 ;
            if (stb_quiry(i,M)-sta_quiry(i,M)>0) {
                P1=M ;
                L=M+1 ;
            }
            else R=M-1 ;
        }
        L=P1+1, R=n-1 ;
        while (L<=R) {
            M=(L+R)/2 ;
            if (stb_quiry(i,M)-sta_quiry(i,M)<0) {
                P2=M ;
                R=M-1 ;
            }
            else L=M+1 ;
        }
        ans+=P2-P1-1 ;
    }
    return ans ;
}

int main()
{
    scanf("%d",&n) ;
    for (int i=0;i<n;++i) scanf("%lld",&a[i]) ;
    for (int i=0;i<n;++i) scanf("%lld",&b[i]) ;
    sta_build() ;
    stb_build() ;
    printf("%lld",ans_count()) ;
    return 0;
}
