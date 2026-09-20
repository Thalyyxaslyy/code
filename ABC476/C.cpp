#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
typedef long long ll;
using namespace std;
ll n,a[500001],mx,mz,mn;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    if(a[1]>=a[2]&&a[2]>=a[3])mx=a[1],mz=a[2],mn=a[3];
    else if(a[1]>=a[3]&&a[3]>=a[2])mx=a[1],mz=a[3],mn=a[2];
    else if(a[2]>=a[1]&&a[1]>=a[3])mx=a[2],mz=a[1],mn=a[3];
    else if(a[2]>=a[3]&&a[3]>=a[1])mx=a[2],mz=a[3],mn=a[1];
    else if(a[3]>=a[2]&&a[2]>=a[1])mx=a[3],mz=a[2],mn=a[1];
    else if(a[3]>=a[1]&&a[1]>=a[2])mx=a[3],mz=a[1],mn=a[2];
    cout<<mn<<endl;
    for(ll i=4;i<=n;i++){
        if(a[i]>=mx)mn=mz,mz=mx,mx=a[i];
        else if(a[i]>=mz)mn=mz,mz=a[i];
        else if(a[i]>=mn)mn=a[i];
        cout<<mn<<endl;
    }
    return 0;
}