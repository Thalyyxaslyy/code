#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
typedef long long ll;
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    if(s.back()!='e')s+='e';
    s+='r';cout<<s<<endl;
    return 0;
}