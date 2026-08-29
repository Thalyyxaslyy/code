#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<print>
typedef long long ll;
using namespace std;
ll n,k,a[200001],ans,gs[200001],mx,drmx;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i],gs[a[i]]++;
    for(ll i=1;i<=k;i++)mx=max(gs[i],mx);
    for(ll i=1;i<=k;i++)if(gs[i]==mx||gs[i]==mx-1)ans++;
    cout<<ans<<endl;
    return 0;
}