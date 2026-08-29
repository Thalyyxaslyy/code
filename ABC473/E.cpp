#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<print>
#include<map>
typedef long long ll;
using namespace std;
ll n,k,a[200001],dp[200001];map<ll,ll> cx;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;cx[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];a[i]+=a[i-1];
        dp[i]=dp[i-1];
        if(cx.find(a[i]%k)!=cx.end())
            dp[i]=max(dp[i],dp[cx[a[i]%k]]+1);
        cx[a[i]%k]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}