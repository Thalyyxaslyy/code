#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
ll n,k,T,ed,ans;vector<ll> a;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k>>T;a.resize(n);
    for(ll&t:a)cin>>t;
    a.push_back(T);
    sort(a.begin(),a.end());
    for(ll t:a){
        if(t>T)break;
        if(t<=ed){
            ed=max(ed,t+k);
            continue;
        }
        ll jl=t-ed;
        ll jf=(jl-1)/k+1;
        ans+=jf;
        ed=max(ed+jf*k,t+k);
    }
    cout<<ans<<endl;
    return 0;
}