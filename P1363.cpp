#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<tuple>
typedef long long ll;
const ll x_[]={0,1,0,-1},y_[]={1,0,-1,0};
using namespace std;
ll n,m,sx,sy;bool map[1501][1501];
ll vis[1501][1501][3];
stack<tuple<ll,ll,ll,ll>> wz;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n>>m){
		for(ll i=0;i<n;i++)for(ll j=0;j<m;j++){
            char c;cin>>c;
            vis[i][j][0]=0;
            vis[i][j][1]=vis[i][j][2]=-1;
            if(c=='S')sx=i,sy=j;
            map[i][j]=(c=='#');
		}
        while(!wz.empty())wz.pop();
        wz.push({sx,sy,sx,sy});
        bool ans=false;
        while(!wz.empty()){
            auto[x,y,px,py]=wz.top();wz.pop();
            if(vis[x][y][0]&&(vis[x][y][1]!=px||vis[x][y][2]!=py)){
                ans=true;break;
            }
            vis[x][y][0]=1,vis[x][y][1]=px,vis[x][y][2]=py;
            for(ll i=0;i<4;i++){
                ll xx=px+x_[i],xy=py+y_[i];
                ll dx=(xx%n+n)%n,dy=(xy%m+m)%m;
                if(map[dx][dy])continue;
                if(vis[dx][dy][1]!=xx||vis[dx][dy][2]!=xy||!vis[dx][dy][0])
                    wz.push({dx,dy,xx,xy});
            }
        }
        cout<<(ans?"Yes":"No")<<endl;
	}
	return 0;
}