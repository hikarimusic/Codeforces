#include <bits/stdc++.h>
using namespace std ;

string s ;

int main() {
    cin>>s ;
    bool b=1 ;
    for (int i=1;i<s.length();++i) {
        if (s[i]>=97) {
            b=0 ;
            break ;
        }
    }
    if (b) {
        s[0]+=(s[0]<97)?(32):(-32) ;
        for (int i=1;i<s.length();++i) {
            s[i]+=32 ;
        }
    }
    cout<<s ;
    return 0 ;
}
