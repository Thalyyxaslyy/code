#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
const ll mod=1234567891;
typedef long long ll;
using namespace std;
ll ksm(ll x,ll y){
    ll ans=1;
    while(y){
        if(y%2)ans=ans*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}