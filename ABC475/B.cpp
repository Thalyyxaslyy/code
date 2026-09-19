#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,m,a,b,c;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--){
        cin>>m;
        ll v=(1000-m%1000)%1000;
        a+=v/100,b+=(v%100)/10,c+=v%10;
    }
    cout<<c<<" "<<b<<" "<<a<<endl;
    return 0;
}