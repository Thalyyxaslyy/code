#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
const ll mod=1234567891;
using namespace std;
ll T,n,k,jc[31],ans;
ll ksm(ll x,ll y){
    ll ans=1;
    while(y){
        if(y%2)ans=ans*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
ll C(ll x,ll y){
    if(y>x)return 0;
    if(y==0||y==x)return 1;
    return jc[x]*ksm(jc[y]*jc[x-y]%mod,mod-2)%mod;
}
ll dbqh(ll a,ll n){
    if(a==1)return n;
    return (ksm(a,n+1)-a+mod)%mod*ksm((a-1+mod)%mod,mod-2)%mod;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    jc[0]=1;for(ll i=1;i<=30;i++)jc[i]=jc[i-1]*i%mod;
    while(T--){
        cin>>n>>k;ans=0;
        for(ll i=0;i<k;i++){
            if(i%2)ans=(ans-C(k,i)*dbqh(k-i,n)%mod)%mod;
            else ans=(ans+C(k,i)*dbqh(k-i,n)%mod+mod)%mod;
        }
        cout<<(ans%mod+mod)%mod<<endl;
    }
    return 0;
}