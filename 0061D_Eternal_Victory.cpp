#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define n_max 100000

vector<vector<pair<int,int>>> g(n_max+5) ;
vector<bool> vis(n_max+5);
vector<ll> dis(n_max+5) ;
ll d_max, d_sum ;

void dfs(int a) {
    vis[a]=1 ;
    for (pair<int,int> p : g[a]) {
        if (!vis[p.first]) {
            dis[p.first]=dis[a]+p.second ;
            d_sum+=p.second ;
            d_max=max(d_max,dis[p.first]) ;
            dfs(p.first) ;
        }
    }
}

int main()
{
    int n ;
    cin>>n ;
    for (int i=0;i<n-1;++i) {
        int x,y,w ;
        cin>>x>>y>>w ;
        g[x].push_back(make_pair(y,w)) ;
        g[y].push_back(make_pair(x,w)) ;
    }
    dfs(1) ;
    cout<<2*d_sum-d_max ;
    return 0;
}
