#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
char c;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c;
    if(c=='B')c='Y';
    else if(c=='Y')c='R';
    else c='B';
    cout<<c<<endl;
    return 0;
}