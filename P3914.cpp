#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
ll n,m;vector<ll> ds[5010],colors[5010];
ll dp[5010][5010],zu[5010],gs[5010];
bool vis[5010][5010];
ll dfs(ll x,ll last_color,ll fa){
    if(vis[x][last_color])return dp[x][last_color];
    vis[x][last_color]=true;
    dp[x][last_color]=1;
    if((ds[x].size()==1&&x!=1)||(ds[x].size()==0)){
        zu[x]=(zu[x]+dp[x][last_color])%mod;gs[x]++;
        return dp[x][last_color];
    }
    for(ll nxt:ds[x]){
        if(nxt==fa)continue;
        if(!gs[nxt])while(gs[nxt]<colors[nxt].size())
            dfs(nxt,colors[nxt][gs[nxt]],x);
        ll gs=lower_bound(colors[nxt].begin(),
            colors[nxt].end(),last_color)-
                colors[nxt].begin();
        ll cy=zu[nxt];
        if(gs!=colors[nxt].size()&&colors[nxt][gs]
            ==last_color)cy-=dp[nxt][last_color];
        dp[x][last_color]=dp[x][last_color]*cy%mod;
    }
    zu[x]=(zu[x]+dp[x][last_color])%mod;gs[x]++;
    return dp[x][last_color];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        while(k--){
            ll color;cin>>color;
            colors[i].push_back(color);
        }
        sort(colors[i].begin(),colors[i].end());
        colors[i].erase(unique(colors[i].begin(),
            colors[i].end()),colors[i].end());
    }
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        ds[u].push_back(v),ds[v].push_back(u);
    }
    for(ll color:colors[1])dfs(1,color,0);
    cout<<(zu[1]+mod)%mod<<endl;
    return 0;
}