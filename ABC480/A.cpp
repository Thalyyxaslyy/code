#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll s1,s2,s3,s4;string a,b;
auto check=[](){
    if(s1=='A')if(s2=='D'||s3=='D')return true;
    if(s2=='A')if(s1=='D'||s4=='D')return true;
    if(s3=='A')if(s1=='D'||s4=='D')return true;
    if(s4=='A')if(s2=='D'||s3=='D')return true;
    return false;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b;s1=a[0],s2=a[1],s3=b[0],s4=b[1];
    cout<<(check()?"Yes":"No")<<endl;
    return 0;
}