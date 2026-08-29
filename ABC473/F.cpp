#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<print>
typedef int ll;
using namespace std;
class node{public:ll ls,rs,AS,mn,k=1,l,r;};
ll n,q,head;string s;vector<node>nds;
ll build(ll l,ll r){
    node as;as.l=l,as.r=r;
    if(l==r){
        as.AS=(s[l-1]=='A');
        if(s[l-1]=='A')as.mn=1;
        else as.mn=-1;
    }
    else{
        ll mid=(l+r)/2;
        as.ls=build(l,mid);
        as.rs=build(mid+1,r);
        as.AS=nds[as.ls].AS+nds[as.rs].AS;
        ll lc=2*nds[as.ls].AS-mid+l-1;
        as.mn=min(nds[as.ls].mn,nds[as.rs].mn+lc);
    }
    nds.push_back(as);
    return nds.size()-1;
}
void update(ll x,ll p,bool c,ll l,ll r){
    if(l>x||r<x)return;
    if(l==r){
        nds[p].AS=c;
        if(c)nds[p].mn=1;
        else nds[p].mn=-1;
        return;
    }
    update(x,nds[p].ls,c,l,(l+r)/2);
    update(x,nds[p].rs,c,(l+r)/2+1,r);
    nds[p].AS=nds[nds[p].ls].AS+nds[nds[p].rs].AS;
    ll lc=2*nds[nds[p].ls].AS-(l+r)/2+l-1;
    nds[p].mn=min(nds[nds[p].ls].mn,nds[nds[p].rs].mn+lc);
}
node query(ll l,ll r,ll p,ll lf,ll rf){
    if(rf<l||lf>r)return {0,0,0,0,0,0,0};
    if(lf>=l&&rf<=r)return nds[p];
    node ls=query(l,r,nds[p].ls,lf,(lf+rf)/2),
        rs=query(l,r,nds[p].rs,(lf+rf)/2+1,rf);
    if(ls.k==0)return rs;
    if(rs.k==0)return ls;
    node nw;
    nw.AS=ls.AS+rs.AS;
    ll lc=2*ls.AS-ls.r+ls.l-1;
    nw.mn=min(ls.mn,rs.mn+lc);
    nw.l=ls.l,nw.r=rs.r;
    return nw;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>s>>q;
    head=build(1,n);
    while(q--){
        ll opt;cin>>opt;
        if(opt-1){
            ll l,r;cin>>l>>r;
            node gs=query(l,r,head,1,n);
            if(gs.mn>=0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            ll x;char c;
            cin>>x>>c;
            update(x,head,c=='A',1,n);
        }
    }
    return 0;
}