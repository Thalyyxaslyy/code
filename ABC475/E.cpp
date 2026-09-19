#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<deque>
typedef int ll;
using namespace std;
ll n,m,k,q,ls[14000001],rs[14000001],idx,h,bj[14000001];
string T,s[30001];
void add(deque<bool>&ss,ll wz){
    bj[wz]++;
    if(ss.empty())return;
    if(ss.front()==0){
        ss.pop_front();
        if(!ls[wz])ls[wz]=++idx;
        add(ss,ls[wz]);
    }else{
        ss.pop_front();
        if(!rs[wz])rs[wz]=++idx;
        add(ss,rs[wz]);
    }
}
void del(deque<bool>&ss,ll wz){
    bj[wz]--;
    if(ss.empty())return;
    if(ss.front()==0){
        ss.pop_front();
        del(ss,ls[wz]);
    }else{
        ss.pop_front();
        del(ss,rs[wz]);
    }
}
ll gs(deque<bool>&ss,ll wz){
    if(ss.empty()){return bj[wz];}
    if(ss.front()==0){
        ss.pop_front();
        return gs(ss,ls[wz]);
    }else{
        ss.pop_front();
        return gs(ss,rs[wz])+bj[ls[wz]];
    }
}
deque<bool> ret(string s){
    deque<bool> ss;
    for(ll j=0;j<k;j++)ss.push_back(T[j]!=s[j]);
    return ss;
}
bool check(string s){
    for(ll i=0;i<k;i++)if(s[i]==T[i])return false;
    return true; 
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k>>T;h=++idx;
    for(ll i=1;i<=n;i++){
        cin>>s[i];
        auto v=ret(s[i]);
        add(v,h);
    }
    cin>>q;while(q--){
        ll i,j;cin>>i>>j;
        auto v=ret(s[i]);
        del(v,h);
        if(s[i][j-1]=='o')s[i][j-1]='x';
        else s[i][j-1]='o';
        v=ret(s[i]);
        add(v,h);
        v=ret(s[i]);
        ll vs=gs(v,h);
        if(n==m)
            cout<<(check(s[i])?"No":"Yes")<<endl;
        else cout<<(vs<=m?"Yes":"No")<<endl;
    }
    return 0;
}