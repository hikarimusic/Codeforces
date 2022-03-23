//Codeforces 118A - String Task

#include <bits/stdc++.h>
using namespace std ;

string s ;

int main() {
    cin>>s ;
    for (int i=0;i<s.length();++i) {
        char c=s[i] ;
        if (c<97) c+=32 ;
        if (c=='a'||c=='o'||c=='y'||c=='e'||c=='u'||c=='i') continue ;
        cout<<'.'<<c ;
    }
    return 0 ;
}
