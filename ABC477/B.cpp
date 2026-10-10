#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll n,d;vector<ll> ans;
vector<pair<ll,ll>> rz;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>d;rz.push_back({});
    for(ll i=1;i<=n;i++){
        ll x;cin>>x;rz.push_back({x,i});
    }
    sort(rz.begin(),rz.end());
    for(ll i=1;i<=n;i++){
        bool ts=true;
        if(i>1&&rz[i-1].first>rz[i].first-d)ts=false;
        if(i<n&&rz[i+1].first<rz[i].first+d)ts=false;
        if(ts)ans.push_back(rz[i].second);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(ll x:ans)cout<<x<<" ";
    return 0;
}