#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll h,w,ans;vector<bool> map[200001];
bool vis[200001];ll gs[200001];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>h>>w;
    if(h>w){
        for(ll i=1;i<=w;i++)map[i].resize(1);
        for(ll i=1;i<=h;i++){
            string s;cin>>s;
            for(ll j=1;j<=w;j++)
                map[j].push_back(s[j-1]=='.');
        }
        swap(w,h);
    }else for(ll i=1;i<=h;i++){
            string s;cin>>s;map[i].push_back(1);
            for(ll j=1;j<=w;j++)
                map[i].push_back(s[j-1]=='.');
        }
    for(ll i=1;i<=h;i++){
        for(ll i=1;i<=w;i++)vis[i]=false;
        for(ll j=i;j<=h;j++){
            for(ll k=1;k<=w;k++)if(map[j][k])vis[k]=true;
            ll ls=-1,rs=-1;
            for(ll z=1;z<=w;z++){
                gs[z]=z?gs[z-1]:0;
                if(!vis[z])continue;
                gs[z]++;
                if(map[i][z])ls=z;
                if(map[j][z])rs=z;
                if(min(ls,rs)!=-1)ans+=gs[min(ls,rs)];
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}