#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
ll n,q,hx;vector<ll> a,b,dis,vis;
auto gets=[](ll s,ll t){
    if(s>t)swap(s,t);
    if(s==t)return 0ll;
    if(s==0)return a[t-1];
    return a[t-1]-a[s-1];
};
auto gt=[](ll s,ll t){
    if(s!=n-1&&t!=n-1)return gets(s,t);
    if(s==n-1&&t!=0)return gets(s,t);
    if(t==n-1&&s!=0)return gets(s,t);
    return a[n-1]-a[n-2];
};
auto pre=[](ll x){return (x-1+n)%n;};
auto nxt=[](ll x){return (x+1)%n;};
void dijstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(ll i=0;i<n;i++)dis[i]=b[i],pq.push({dis[i],i});
    while(!pq.empty()){
        ll v=pq.top().second;pq.pop();
        if(vis[v])continue;
        vis[v]=true;
        ll pr=pre(v),nx=nxt(v);
        if(dis[pr]>dis[v]+gt(v,pr)){
            dis[pr]=dis[v]+gt(v,pr);
            pq.push({dis[pr],pr});
        }
        if(dis[nx]>dis[v]+gt(v,nx)){
            dis[nx]=dis[v]+gt(v,nx);
            pq.push({dis[nx],nx});
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;a.resize(n),b.resize(n),dis.resize(n),vis.resize(n);
    for(ll&t:a)cin>>t,hx+=t;
    for(ll i=1;i<n;i++)a[i]+=a[i-1];
    for(ll&t:b)cin>>t;
    dijstra();
    while(q--){
        ll s,t;cin>>s>>t;s--,t--;
        if(s==n)cout<<dis[t]<<endl;
        else if(t==n)cout<<dis[s]<<endl;
        else{
            ll zz=gets(s,t),j=dis[s]+dis[t];
            zz=min(zz,hx-zz);
            cout<<min(zz,j)<<endl;
        }
    }
    return 0;
}
/*5 3
1 3 4 2 5
5 2 4 3 7
2 5
5 6
1 4
*/