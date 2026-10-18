#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,q;vector<ll> su,vs,tf;
auto qhh=[](ll x){
    return lower_bound(vs.begin(),vs.end(),x)-vs.begin();
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;su.resize(n+1),vs.resize(n+1);tf.resize(n+1);
    for(ll i=1;i<=n;i++)cin>>su[i],su[i]+=su[i-1];
    for(ll i=1;i<=n;i++)vs[i]=vs[i-1]+i,tf[i]=tf[i-1]+su[i];
    while(q--){
        ll l,r;cin>>l>>r;
        ll ls=qhh(l),rs=qhh(r);
        l-=vs[ls-1],r-=vs[rs-1];
        if(ls==rs){//1
            cout<<su[r]-su[l-1]<<endl;
        }else if(ls==rs-1){//2
            cout<<su[ls]-su[l-1]+su[r]<<endl;
        }else{//3
            cout<<su[ls]-su[l-1]+su[r]+tf[rs-1]-tf[ls]<<endl;
        }
    }
    return 0;
}