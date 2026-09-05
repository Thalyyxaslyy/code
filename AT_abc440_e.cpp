#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
typedef int ll;
typedef short int si;
using namespace std;
class zt{public:long long mw;si gs[50]={0},last=0;};
si n;
ll k,x,a[51];
priority_queue<zt> zts;
bool operator<(zt a,zt b){return a.mw<b.mw;}
bool cmp(ll a,ll b){return a>b;}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k>>x;
    for(si i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);
    zt xd;xd.mw=(long long)k*a[0];xd.gs[0]=k;
    zts.push(xd);ll bj=0;
    while(!zts.empty()){
        bj++;
        if(bj>x)break;
        zt nw=zts.top();zts.pop();
        cout<<nw.mw<<endl;
        for(ll i=nw.last;i<n-1;i++)
            if(nw.gs[i]){
            zt xd=nw;xd.mw+=a[i+1]-a[i];
            xd.gs[i]--;xd.gs[i+1]++;xd.last=i;
            zts.push(xd);
        }
    }
    return 0;
}