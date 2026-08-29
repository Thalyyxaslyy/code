#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<print>
typedef long long ll;
using namespace std;
ll n,m,q;
ll h[100005],z[100005];
void addh(ll x,ll y){
    for(;x<=n;x+=x&-x)h[x]+=y;
}
ll queryh(ll x){
    ll ans=0;
    for(;x;x-=x&-x)ans+=h[x];
    return ans;
}
void addz(ll x,ll y){
    for(;x<=m;x+=x&-x)z[x]+=y;
}
ll queryz(ll x){
    ll ans=0;
    for(;x;x-=x&-x)ans+=z[x];
    return ans;
}
ll qjh(ll l,ll r){
    return queryh(r)-queryh(l-1);
}
ll qjz(ll l,ll r){
    return queryz(r)-queryz(l-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    while(q--){
        ll opt;cin>>opt;
        if(opt==1){
            ll x,y;cin>>x>>y;
            if(qjh(x,x)==0)addh(x,1);
            else addh(x,-1);
            if(qjz(y,y)==0)addz(y,1);
            else addz(y,-1);
        }else{
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            ll a=qjh(x1,x2),b=qjz(y1,y2),
                c=x2-x1+1-a,d=y2-y1+1-b;
            cout<<a*d+b*c<<endl;
        }
    }
    return 0;
}