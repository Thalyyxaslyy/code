#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,p;vector<ll> ds[151];
ll dp1[151][151],dp2[151][151],siz[151];
void dfs(ll x,ll fa){
    ll dx=ds[x].size()-(bool)fa;siz[x]=1;dp2[x][1]=dx;
    for(ll nxt:ds[x]){
        if(nxt==fa)continue;
        dfs(nxt,x);siz[x]+=siz[nxt];
        for(ll j=1;j<=siz[nxt];j++){
            dp1[x][j]=min({dp1[x][j],dp1[nxt][j],
                dp2[nxt][j]+1});
        }
    }
    for(ll nxt:ds[x]){
        if(nxt==fa)continue;
        for(ll j=siz[x];j>=1;j--)
            for(ll v=1;v<=min(j-1,siz[nxt]);v++){
            dp2[x][j]=min({dp2[x][j],dp2[x][j-v]-1
                +dp2[nxt][v]});
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>p;
    for(ll i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        ds[x].push_back(y);
        ds[y].push_back(x);
    }
    for(ll i=1;i<=n;i++)for(ll j=0;j<=n;j++)
        dp1[i][j]=dp2[i][j]=1e18;
    dfs(1,0);
    cout<<min(dp1[1][p],dp2[1][p])<<endl;
    return 0;
}