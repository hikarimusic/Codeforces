//Codeforces 154B - Colliders

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define n_max 100000

vector<bool> pr(n_max+5,1) ;
vector<int> prime ;

void sieve() {
    pr[0]=pr[1]=0 ;
    for (int i=2;i<=n_max;++i) {
        if (pr[i]) {
            prime.push_back(i) ;
            for (ll j=(ll)i*i;j<=n_max;j+=i) pr[j]=0 ;
        }
    }
}

void factorize(int n, vector<int>& fac) {
    for (int i : prime) {
        if (i*i>n) break ;
        if (n%i==0) {
            fac.push_back(i) ;
            while (n%i==0) n/=i ;
        }
    }
    if (n>1) fac.push_back(n) ;
}

int main()
{
    sieve() ;
    int n,m ;
    cin>>n>>m ;
    vector<bool> on(n+1,0) ;
    vector<int> act(n+1,0) ;
    for (int t=0;t<m;++t) {
        char pm ;
        int num ;
        cin>>pm>>num ;
        vector<int> fac ;
        factorize(num,fac) ;
        if (pm=='+') {
            if (on[num]) printf("Already on\n") ;
            else {
                int con=0 ;
                for (int i : fac) {
                    if (act[i]) {
                        con=act[i] ;
                        break ;
                    }
                }
                if (con) printf("Conflict with %d\n",con) ;
                else {
                    printf("Success\n") ;
                    on[num]=1 ;
                    for (int i : fac) act[i]=num ;
                }
            }
        }
        if (pm=='-') {
            if (!on[num]) printf("Already off\n") ;
            else {
                printf("Success\n") ;
                on[num]=0 ;
                for (int i : fac) act[i]=0 ;
            }
        }
    }
    return 0;
}
