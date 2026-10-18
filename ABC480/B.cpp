#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
using namespace std;
ll n,m;vector<string> ps,xp;map<string,ll>pp;
auto check=[](string a,string b){
    if(a.size()!=b.size())return 0ll;
    ll ws=0;
    for(ll i=0;i<a.size();i++)if(a[i]!=b[i])ws++;
    if(ws>1)return 0ll;
    return ws+1;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;ps.resize(n),xp.resize(m);
    for(auto&t:ps)cin>>t;for(auto&t:xp)cin>>t;
    for(string nw:xp){
        ll wq=0,jj=0;string bx;
        for(string v:ps){
            ll t=check(nw,v);
            if(t==1){wq++;bx=v;break;}
            else if(t==2)jj++,bx=v;
        }
        if(wq||jj==1){
            if(pp.find(bx)==pp.end())pp[bx]=0;
            pp[bx]++;
        }
    }
    for(string t:ps)cout<<pp[t]<<endl;
    return 0;
}