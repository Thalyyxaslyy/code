#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<print>
typedef long long ll;
using namespace std;
ll n,a[101],ans,gs[101];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i],gs[a[i]]++;
    for(ll i=1;i<=100;i++)if(gs[i]%2)ans+=i;
    cout<<ans<<endl;
    return 0;
}