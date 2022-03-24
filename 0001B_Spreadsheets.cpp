#include <bits/stdc++.h>
using namespace std;

int n ;
string str ;

int main()
{
    cin>>n ;
    for (int t=0;t<n;++t) {
        cin>>str ;
        int k=1 ;
        int len=str.length() ;
        while (k<len && isdigit(str[k]) ) {
            ++k ;
        }
        if (k==1 || k==len) {
            int m=0, col=0 ;
            while (isalpha(str[m]) ) {
                col=col*26+str[m]-'A'+1 ;
                ++m ;
            }
            string ans='R'+str.substr(m,len-m) ;
            ans+='C'+to_string(col) ;
            cout<<ans<<'\n' ;
        }
        else {
            int row=0 ;
            for (int i=k+1;i<len;++i) {
                row=row*10+str[i]-'0' ;
            }
            string temp ;
            while (row>0) {
                temp+=(row-1)%26+'A' ;
                row=(row-1)/26 ;
            }
            reverse(temp.begin(),temp.end()) ;
            string ans=temp+str.substr(1,k-1) ;
            cout<<ans<<'\n' ;
        }
    }
    return 0;
}
