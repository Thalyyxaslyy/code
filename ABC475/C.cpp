#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,s,l,a[8001],jl[8001][8001],ans;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>s>>l;for(ll i=1;i<n;i++)cin>>a[i];
    for(ll i=1;i<n;i++)for(ll j=i+1;j<=n;j++)
        jl[i][j]=jl[j][i]=jl[i][j-1]+a[j-1];
    for(ll i=1;i<=s;i++){
        if(l<jl[i][s])continue;
        //1.左右
        ll j=i;
        for(;j<=n;j++)if(jl[j][i]+jl[i][s]>l)break;
        j--;ans=max(ans,max(s,j)-i+1);
    }
    for(ll i=s;i<=n;i++){
        if(l<jl[i][s])continue;
        //1.右左
        ll j=i;
        for(;j>0;j--)if(jl[j][i]+jl[i][s]>l)break;
        j++;ans=max(ans,i-min(s,j)+1);
    }
    cout<<ans<<endl;
    return 0;
}