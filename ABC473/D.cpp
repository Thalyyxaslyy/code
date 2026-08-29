#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<print>
typedef long long ll;
using namespace std;
ll n,k;ll a[11];
void dfs(ll x,ll su){
    if(x==n){
        if((k-su)%x)return;
        for(ll i=1;i<n;i++)cout<<a[i]<<" ";
        cout<<(k-su)/x<<endl;
        return;
    }
    for(ll i=0;i*x<=k-su;i++)a[x]=i,dfs(x+1,su+i*x);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    dfs(1,0);
    return 0;
}