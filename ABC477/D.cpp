#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll n,q,xc;char last,dy[300001],sc[300001];bool wp[300001];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;last='a';xc=q;for(ll i=1;i<=n;i++)sc[i]=q+1;
    while(q--){
        ll opt;cin>>opt;
        if(opt==1){
            ll x;cin>>x;wp[x]=!wp[x];
            if(wp[x]&&xc<sc[x])dy[x]=last;
            if(!wp[x])sc[x]=q;
        }else cin>>last,xc=q;
    }
    for(ll i=1;i<=n;i++){
        if(wp[i]||sc[i]<xc)cout<<char(dy[i]);
        else cout<<char(last);
    }
    cout<<endl;
    return 0;
}