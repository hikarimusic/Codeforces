//Codeforces 514C - Watto and Mechanism

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lmax 600005
#define p 5
#define mod 10000000000000061

int n,m ;
string s ;
vector<ll> ppow (lmax,0) ;
set<ll> myset ;

void get_pow() {
    ppow[0]=1 ;
    for (int i=1;i<lmax;++i) {
        ppow[i]=ppow[i-1]*p%mod ;
    }
}

ll get_hash(string& s) {
    ll ans=0 ;
    ll len=s.length() ;
    for (int i=0;i<len;++i) {
        ans+=(s[i]-'a'+1)*ppow[i] ;
        ans%=mod ;
    }
    return ans ;
}

int main()
{
    get_pow() ;
    scanf("%d %d",&n,&m) ;
    for (int t=0;t<n;t++) {
        cin>>s ;
        myset.insert(get_hash(s)) ;
    }
    for (int t=0;t<m;++t) {
        cin>>s ;
        bool flag=false ;
        ll val=get_hash(s) ;
        ll len=s.length() ;
        for (ll i=0;i<len;++i) {
            for (ll j=0;j<3;++j) {
                ll c='a'+j-s[i] ;
                if (c==0) continue ;
                ll x=((val+c*ppow[i])%mod+mod)%mod ;
                if (myset.count(x)) {
                    flag=true ;
                    break ;
                }
            }
            if (flag==true) break ;
        }
        printf("%s\n",flag?"YES":"NO") ;
    }
    return 0;
}
