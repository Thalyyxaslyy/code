#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef int ll;
const ll x_[]={0,1,0,-1},y_[]={1,0,-1,0};
using namespace std;
ll n,m,sx,sy;;ll vis[1505][1505][3];
bool map[1505][1505],ans;
void dfs(ll x,ll y,ll zx,ll zy){
    if(ans)return;
    if(vis[x][y][0]&&(vis[x][y][1]!=zx||vis[x][y][2]!=zy)){
        ans=true;return;
    }
    vis[x][y][0]=1;vis[x][y][1]=zx,vis[x][y][2]=zy;
    for(ll i=0;i<4;i++){
        ll xx=zx+x_[i],xy=zy+y_[i];
        ll yx=(xx%n+n)%n,yy=(xy%m+m)%m;
        if(!map[yx][yy])continue;
        if(vis[yx][yy][1]!=xx||vis[yx][yy][2]!=yy)
            dfs(yx,yy,xx,xy);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n>>m){
        for(ll i=0;i<n;i++)for(ll j=0;j<m;j++){
            char c;cin>>c;
            if(c=='S')sx=i,sy=j;
            map[i][j]=(c!='#');
            vis[i][j][0]=0;
        }ans=false;
        dfs(sx,sy,sx,sy);
        cout<<(ans?"Yes":"No")<<endl;
    }
    return 0;
}