//Codeforces 112A - Petya and Strings

#include <bits/stdc++.h>
using namespace std ;

string a,b ;

int main() {
    cin>>a>>b ;
    int t=0 ;
    for (int i=0;i<a.length();++i) {
        if (a[i]<97) a[i]+=32 ;
        if (b[i]<97) b[i]+=32 ;
        if (a[i]<b[i]) {
            t=-1 ;
            break ;
        }
        if (a[i]>b[i]) {
            t=1 ;
            break ;
        }
    }
    cout<<t ;
    return 0 ;
}
