#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef int ll;
using namespace std;
string s;vector<ll> zs;bool vis[10000001];
bool check(string p){
    for(ll i=0;i<s.size();i++)for(ll j=i+1;j<s.size();j++){
        if((s[i]!=s[j]&&p[i]==p[j])||(s[i]==s[j]&&p[i]!=p[j]))
            return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(ll i=2;i<=100000000;i++){
        if(!vis[i])zs.push_back(i);
        for(ll j:zs){
            if((long long)(i)*j>100000000)break;
            vis[i*j]=true;
            if(i%j==0)break;
        }
    }
    for(ll i:zs){
        string dy=to_string(i);
        if(dy.size()>s.size()){cout<<-1<<endl;break;}
        if(dy.size()<s.size())continue;
        if(check(dy)){cout<<dy<<endl;break;}
    }
    return 0;
}