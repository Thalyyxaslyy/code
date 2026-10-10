#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll q;string s,t;vector<ll> wz;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>q>>s>>t;
    for(ll i=0;i+t.size()-1<s.size();i++){
        bool ys=true;
        for(ll j=i;j<=i+t.size()-1;j++)
            if(s[j]!=t[j-i]){ys=false;break;}
        if(ys)wz.push_back(i);
    }
    while(q--){
        ll l,r;cin>>l>>r;l--,r--;
        ll df=lower_bound(wz.begin(),wz.end(),l)-wz.begin();
        if(df==wz.size()){cout<<"No"<<endl;continue;}
        ll wzs=wz[df];
        if(wzs+t.size()-1<=r)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}