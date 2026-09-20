#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
typedef long long ll;
using namespace std;
ll n,m,k,x,y,ab[2][200001],ans;auto ret=[](ll v){return v%k?v/k+1:v/k;};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k>>x>>y;
    for(ll i=1;i<=n;i++)cin>>ab[0][i];
    for(ll j=1;j<=m;j++)cin>>ab[1][j];
    sort(ab[0]+1,ab[0]+n+1);sort(ab[1]+1,ab[1]+m+1);
    for(ll i=2;i<=n;i++)ab[0][i]+=ab[0][i-1];
    ans=(upper_bound(ab[0]+1,ab[0]+n+1,x+y*k)-ab[0])-1;
    for(ll d=1;d<=m;d++){
        if(y<ret(ab[1][d]))break;
        y-=ret(ab[1][d]);
        x+=ret(ab[1][d])*k-ab[1][d];
        ans=max(ans,d+(upper_bound(ab[0]+1,ab[0]+n+1,x+y*k)-ab[0])-1);
    }
    cout<<ans<<endl;
    return 0;
}