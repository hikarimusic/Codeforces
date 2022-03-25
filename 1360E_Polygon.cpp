#include <bits/stdc++.h>
using namespace std ;
#define MAXN 55

int t,n ;
vector<string> g(MAXN) ;

int main() {
    cin>>t ;
    while (t--) {
        cin>>n ;
        for (int i=0;i<n;++i) {
            cin>>g[i] ;
        }
        bool ans=1 ;
        for (int i=0;i<n-1;++i) {
            for (int j=0;j<n-1;++j) {
                if (g[i][j]=='1' && g[i+1][j]=='0' && g[i][j+1]=='0') {
                    ans=0 ;
                    break ;
                }
            }
        }
        printf("%s",ans?"YES\n":"NO\n") ;
    }
    return 0 ;
}
