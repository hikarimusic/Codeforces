//Codeforces 58A - Chat room 

#include <bits/stdc++.h>
using namespace std ;

string a,b ;

int main() {
    cin>>a ;
    b="hello" ;
    int cnt=0 ;
    for (int i=0;i<a.length();++i) {
        if (cnt==5) break ;
        if (a[i]==b[cnt]) ++cnt ;
    }
    if (cnt==5) cout<<"YES" ;
    else cout<<"NO" ;
    return 0 ;
}
