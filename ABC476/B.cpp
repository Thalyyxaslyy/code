#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
typedef long long ll;
using namespace std;
string s,t;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s>>t;
    for(ll i=0;i<t.size();i++){
        if(t[i]=='*')continue;
        if(t[i]!=s[i]){
            cout<<"No"<<endl;return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}