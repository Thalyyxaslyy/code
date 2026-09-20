#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
typedef long long ll;
using namespace std;
class node{public:ll l,r,mxz,mnz;}nds[800001];
ll n,m,pf[200001];
void push_up(ll p){
    if(pf[nds[p*2].mxz]>pf[nds[p*2+1].mxz])
        nds[p].mxz=nds[p*2].mxz;
    else nds[p].mxz=nds[p*2+1].mxz;
    if(pf[nds[p*2].mnz]>pf[nds[p*2+1].mnz])
        nds[p].mnz=nds[p*2+1].mnz;
    else nds[p].mnz=nds[p*2].mnz;
}
void build(ll l,ll r,ll p){
    nds[p].l=l,nds[p].r=r;
    if(l==r)nds[p].mxz=nds[p].mnz=nds[p].l;
    else{
        ll mid=(l+r)/2;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
        push_up(p);
    }
}
void update(ll x,ll p){
    if(nds[p].r<x||nds[p].l>x)return;
    if(nds[p].l==nds[p].r)return;
    update(x,p*2);update(x,p*2+1);
    push_up(p);
}
ll query_mx(ll l,ll r,ll p){
    if(nds[p].r<l||nds[p].l>r)return 0;
    if(nds[p].l>=l&&nds[p].r<=r)return nds[p].mxz;
    ll a=query_mx(l,r,p*2),b=query_mx(l,r,p*2+1);
    if(a==0||b==0)return a|b;
    if(pf[a]<pf[b])return b;
    else return a;
}
ll query_mn(ll l,ll r,ll p){
    if(nds[p].r<l||nds[p].l>r)return 0;
    if(nds[p].l>=l&&nds[p].r<=r)return nds[p].mnz;
    ll a=query_mn(l,r,p*2),b=query_mn(l,r,p*2+1);
    if(a==0||b==0)return a|b;
    if(pf[a]>pf[b])return b;
    else return a;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>pf[i];
    build(1,n,1);
    while(m--){
        ll l,r;cin>>l>>r;
        ll a=query_mx(l,r,1),b=query_mn(l,r,1);
        swap(pf[a],pf[b]);
        update(a,1),update(b,1);
    }
    for(ll i=1;i<=n;i++)cout<<pf[i]<<" ";
    cout<<endl;
    return 0;
}