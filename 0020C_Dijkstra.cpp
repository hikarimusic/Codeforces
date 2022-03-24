#include <bits/stdc++.h>
using namespace std;
#define n_max 100000
#define INF 1e18
#define ll long long
#define pll pair<ll,ll>

vector<vector<pair<ll,ll>>> g(n_max+5) ;

void dijkstra (vector<ll>& d, vector<ll>& p) {
    ll n=g.size() ;
    d[1]=0 ;
    priority_queue<pll, vector<pll>, greater<pll>> q ;
    q.push({0,1}) ;
    while (!q.empty()) {
        ll v=q.top().second ;
        ll d_v=q.top().first ;
        q.pop() ;
        if (d_v!=d[v]) continue ;
        for (auto edge : g[v]) {
            ll to=edge.first ;
            ll len=edge.second ;
            if (d[v]+len<d[to]) {
                d[to]=d[v]+len ;
                p[to]=v ;
                q.push({d[to],to}) ;
            }
        }
    }
}

void showpath(ll n, vector<ll>& p) {
    if (p[n]==-1) printf("%d",-1) ;
    else {
        vector<ll> path ;
        for (int v=n;v!=-1;v=p[v]) {
            path.push_back(v) ;
        }
        reverse(path.begin(),path.end()) ;
        for (auto i : path) printf("%lld ",i) ;
    }
}

int main()
{
    ll n,m ;
    scanf("%lld %lld",&n,&m) ;
    for (int i=0;i<m;++i) {
        ll a,b,w ;
        scanf("%lld %lld %lld",&a,&b,&w) ;
        g[a].push_back({b,w}) ;
        g[b].push_back({a,w}) ;
    }
    vector<ll> d(n+1,INF) ;
    vector<ll> p(n+1,-1) ;
    dijkstra(d,p) ;
    showpath(n,p) ;
    return 0;
}
