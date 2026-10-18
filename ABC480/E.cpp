#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
ll Num,ans;
void cf(ll&a,ll b){
    if(a>1e18/b)a=0;
    else a=a*b;
}
ll ksm(ll x,ll y){
    ll ans=1;
    while(y){
        if(y%2)cf(ans,x);
        cf(x,x),y/=2;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>Num;
    for(ll n=3;n<=20;n++){
        ll l=1,r=1e6,dz=0;
        while(l<=r){
            ll mid=(l+r)/2;
            cout<<ksm(mid,n)<<endl;
            if(ksm(mid,n)==0||ksm(mid,n)>=Num)r=mid-1;
            else l=mid+1,dz=mid;
        }
        cout<<dz<<endl;
        cout<<ksm(dz+1,n)<<endl;
        for(ll a=1;a<=dz;a++){
            l=1,r=1e18;ll jr=0;
            while(l<=r){
                ll mid=(l+r)/2;
                ll v=Num;
                for(ll i=0;i<n;i++)Num/=a+i*mid;
                // cout<<mid<<" "<<Num<<" "<<a<<" "<<n<<endl;
                if(!Num)r=mid-1;
                else l=mid+1,jr=mid;
            }
            ans+=jr;
        }
    }
    cout<<ans<<endl;
    return 0;
}