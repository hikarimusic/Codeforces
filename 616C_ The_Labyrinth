//Codeforces 616C - The Labyrinth

#include <bits/stdc++.h>
using namespace std;
#define n_max 1000 

int n,m ;
vector<string> mp ;
bool vis[n_max+5][n_max+5] ;
int com[n_max+5][n_max+5] ;
int num[n_max*n_max+5] ;
int dx[4]={1,-1,0,0} ;
int dy[4]={0,0,1,-1} ;

bool check(int x,int y) {
    if (x<0||x>=n) return 0 ;
    if (y<0||y>=m) return 0 ;
    if (mp[x][y]=='*') return 0 ;
    return 1 ;
}

void dfs(int x, int y, int cnt) {
    vis[x][y]=1 ;
    com[x][y]=cnt ;
    ++num[cnt] ;
    for (int i=0;i<4;++i) {
        int x1=x+dx[i] ;
        int y1=y+dy[i] ;
        if (!check(x1,y1)) continue ;
        if (!vis[x1][y1]) dfs(x1,y1,cnt) ;
    }
}

int main()
{
    scanf("%d %d",&n,&m) ;
    string in ;
    for (int i=0;i<n;++i) {
        cin>>in ;
        mp.push_back(in) ;
    }
    int cnt=1 ;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (!vis[i][j] && mp[i][j]=='.') {
                dfs(i,j,cnt) ;
                ++cnt ;
            }
        }
        
    }
    for (int i=0;i<n;++i) {
        string out(m,'.') ;
        for (int j=0;j<m;++j) {
            set<int> sur ;
            if (check(i,j)) continue ;
            int ans=1 ;
            for (int k=0;k<4;++k) {
                int x=i+dx[k] ;
                int y=j+dy[k] ;
                if (!check(x,y)) continue ;
                sur.insert(com[x][y]) ;
            }
            for (int t : sur) {
                ans+=num[t] ;
            }
            out[j]=(char) (ans%10)+'0'  ;
        }
        cout<<out<<'\n' ;
    }
    return 0;
}

