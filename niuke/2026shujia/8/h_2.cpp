#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
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
    i128 n,x;
    cin>>n>>x;
    i128 cnt=0;
    priority_queue<pair<i128,LL>> q;
    i128 s=0;
    for(int i=1;i<=n;i++){
        i128 y;
        cin>>y;
        s+=y;
        cnt+=y/x;
        q.push({y%x,i});
    }
    if(x==1){
        cout<<s%mod<<'\n';
        return;
    }
    LL tag=0;
    while(!q.empty()){
        auto cp=q.top();
        q.pop();
        //printf("{%lld}",cp.first);
        if(cnt+1>=x-cp.first){
            i128 d=x-cp.first;
            cnt-=d;
            cnt++;
        }else{
            q.push(cp);
            tag=1;
            break;
        }
    }
    if(tag){
        i128 ans=0;
        while(!q.empty()){
            ans=(ans+q.top().first)%mod;
            q.pop();
        }
        cout<<(ans+cnt)%mod<<'\n';        
    }else{
        //printf("{%lld}",cnt);
        i128 ans=cnt%(x-1);
        cout<<ans%mod<<'\n';
    }

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