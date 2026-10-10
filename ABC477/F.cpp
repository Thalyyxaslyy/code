#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;
class Question{public:ll h,l,r,id;};
class node{public:ll ls,rs,val,lazy;};
auto getf11=[](ll x){return (ll)(x/abs(x));};
vector<pair<ll,ll>> lrs;vector<Question>qst;
ll n,m,q,head;vector<ll> ans;vector<node> nds;
bool cmp(Question a,Question b){
    return a.h>b.h;
}
ll build(ll l,ll r){
    node newd;
    if(l!=r){
        ll mid=(l+r)>>1;
        newd.ls=build(l,mid);
        newd.rs=build(mid+1,r);
    }else newd.ls=newd.rs=-1;
    nds.push_back(newd);
    return nds.size()-1;
}
void push_up(ll u){
    nds[u].val=nds[nds[u].ls].val+nds[nds[u].rs].val;
}
void add(ll u,ll ul,ll ur,ll c){
    nds[u].val+=(ur-ul+1)*c;
    nds[u].lazy+=c;
}
void push_down(ll u,ll ul,ll ur){
    if((!nds[u].lazy)||nds[u].ls==-1)return;
    ll mid=(ul+ur)>>1;
    add(nds[u].ls,ul,mid,nds[u].lazy);
    add(nds[u].rs,mid+1,ur,nds[u].lazy);
    nds[u].lazy=0;
}
void update(ll l,ll r,ll u,ll ul,ll ur){
    if(ul>r||ur<l)return;
    if(ul>=l&&ur<=r){
        add(u,ul,ur,1);
        return;
    }
    ll mid=(ul+ur)>>1;
    push_down(u,ul,ur);
    update(l,r,nds[u].ls,ul,mid);
    update(l,r,nds[u].rs,mid+1,ur);
    push_up(u);
}
ll query(ll l,ll r,ll u,ll ul,ll ur){
    if(ul>r||ur<l)return 0;
    if(ul>=l&&ur<=r)return nds[u].val;
    ll mid=(ul+ur)>>1;
    push_down(u,ul,ur);
    return query(l,r,nds[u].ls,ul,mid)+query(l,r,nds[u].rs,mid+1,ur);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;lrs.resize(n);ans.resize(q+1);ans[0]=-1;
    for(auto&[l,r]:lrs)cin>>l>>r;
    for(ll i=0;i<q;i++){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        if(a!=1)qst.push_back({a-1,c,d,-(i+1)});
        qst.push_back({b,c,d,i+1});
    }
    sort(qst.begin(),qst.end(),cmp);
    head=build(1,m);
    for(ll high=1;high<=n;high++){
        update(lrs[high-1].first,lrs[high-1].second,head,1,m);
        while(!qst.empty()&&qst.back().h==high){
            ll l=qst.back().l,r=qst.back().r,id=qst.back().id;
            qst.pop_back();
            ans[abs(id)]+=getf11(id)*query(l,r,head,1,m);
        }
    }
    for(ll&t:ans)if(t>=0)cout<<t<<endl;
    cout<<endl;
    return 0;
}