#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
typedef long long ll;
using namespace std;
ll n,q,idx,dfn[200001],low[200001],dy,ss[200001],rd[200001],sds[200001];
vector<pair<ll,bool>>ds[200001],xd[200001];
bool in_stk[200001];stack<ll> stk;queue<ll> tp;
void tarjan(ll u){
    dfn[u]=low[u]=++idx;
    stk.push(u),in_stk[u]=true;
    for(auto[nxt,xh]:ds[u]){
        if(!dfn[nxt]){
            tarjan(nxt);
            low[u]=min(low[u],low[nxt]);
        }else if(in_stk[nxt])low[u]=min(low[u],dfn[nxt]);
    }
    if(dfn[u]==low[u]){
        dy++;
        while(true){
            ll y=stk.top();in_stk[y]=false;
            stk.pop();ss[y]=dy;
            if(y==u)break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    while(q--){
        ll opt,u,v;cin>>opt>>u>>v;
        ds[u].push_back({v,opt});
    }
    for(ll i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    bool flag=true;
    for(ll i=1;i<=n;i++){
        for(auto[j,xh]:ds[i]){
            if(ss[i]!=ss[j])
                xd[ss[i]].push_back({ss[j],xh}),rd[ss[j]]++;
            else if(xh)flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else{cout<<"No"<<endl;return 0;}
    for(ll i=1;i<=dy;i++)if(!rd[i])sds[i]=1,tp.push(i);
    while(!tp.empty()){
        ll u=tp.front();tp.pop();
        for(auto[nxt,xh]:xd[u]){
            rd[nxt]--;
            if(xh)sds[nxt]=max(sds[nxt],sds[u]+1);
            else sds[nxt]=max(sds[nxt],sds[u]);
            if(rd[nxt]==0)tp.push(nxt);
        }
    }
    for(ll i=1;i<=n;i++)cout<<sds[ss[i]]<<" ";
    cout<<endl;
    return 0;
}