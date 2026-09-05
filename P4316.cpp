#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<print>
typedef long long ll;
using namespace std;
ll n,m,rd[100010],cd[100010];double dp[100010];
vector<pair<ll,ll>> ds[100010];queue<ll> qfs;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--){
        ll u,v,w;cin>>u>>v>>w;
        ds[v].push_back({u,w});
        rd[u]++,cd[u]++;
    }
    qfs.push(n);
    while(!qfs.empty()){
        ll u=qfs.front();qfs.pop();
        for(auto[v,w]:ds[u]){
            rd[v]--;
            dp[v]+=(dp[u]+w)/cd[v];
            if(rd[v]==0)qfs.push(v);
        }
    }
    printf("%.2f",dp[1]);
    return 0;
}