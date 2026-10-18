#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
typedef long long ll;
const ll mod=998244353;
using namespace std;
ll n,ans=1;
stack<pair<ll,ll>> vf;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;ll yn=n;
    while(n--){
        ll q;cin>>q;
        while(!vf.empty()&&vf.top().first<q)vf.pop();
        ll cj;
        if(vf.empty())cj=yn-n-1;
        else cj=vf.top().second-n;
        if(n!=yn-1)ans=ans*cj%mod;
        vf.push({q,n});
    }
    cout<<ans<<endl;
    return 0;
}