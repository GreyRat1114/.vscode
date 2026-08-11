#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
using u128=__uint128_t;
ostream& operator<<(ostream& out,i128 x){
    if(x<0)out<<'-';
    u128 y=x<0?-(u128)x:(u128)x;
    if(!y)return out<<0;
    string s;
    while(y)s+=char('0'+y%10),y/=10;
    reverse(s.begin(),s.end());
    return out<<s;
}
istream& operator>>(istream& in,i128& x){
    string s;in>>s;
    x=0;
    int p=0,tag=1;
    if(s[0]=='-')tag=-1,p=1;
    for(;p<s.size();p++)x=x*10+s[p]-'0';
    x*=tag;
    return in;
}
void solve(){
    i128 x,y;
    cin>>x>>y;
    if(x==0){
        cout<<y*(y-1)/2<<'\n';
        return;
    } 
    if(y==0){
        cout<<0<<'\n';
        return;
    }
    if(x==1){
        cout<<y*(y+1)/2<<'\n';
        return;
    }
    i128 s=x-2-(x-2)/(y+1);
    i128 k=s/y;
    i128 yu=s%y;
    i128 pt1=(yu*(k+1)*(k+1)+(y-yu)*k*k+s*s)/2;
    i128 pt2=y*x+y*(y-1)/2+s*(x-1);
    i128 ans=pt2-pt1;
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();

    }
    return 0;
}