//Codeforces 339A - Helpful Maths

#include <bits/stdc++.h>
using namespace std ;

string s ;
int a[4] ;
int main() {
    cin>>s ;
    for (int i=0;i<s.length();++i) {
        if (s[i]=='+') continue ;
        a[s[i]-'0']++ ;
    }
    string ss ;
    for (int i=1;i<=3;++i) {
        for (int j=0;j<a[i];++j) {
            ss.append(to_string(i)+"+") ;
        }
    }
    cout<<ss.substr(0,ss.length()-1) ;
    return 0 ;
}
