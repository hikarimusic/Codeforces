// Codeforces 71A - Way Too Long Words

#include <bits/stdc++.h>
using namespace std ;

int n ;
string s ;

int main() {
    cin>>n ;
    while (n--) {
        cin>>s ;
        int l=s.length() ;
        if (l<=10) cout<<s<<'\n' ;
        else cout<<s[0]<<l-2<<s[l-1]<<'\n' ;
    }
    return 0 ;
}
