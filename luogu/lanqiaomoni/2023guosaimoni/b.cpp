#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    queue<LL> a,b;
    LL x,y;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.push(x);
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        b.push(x);
    }
    x=a.front();
    y=b.front();
    a.pop();
    b.pop();
    LL cnt=0;
    while(!a.empty()||!b.empty()){
        if(x<y){
            x+=a.front();
            a.pop();
            cnt++;
        }else if(x>y){
            y+=b.front();
            b.pop();
            cnt++;
        }else{
            x=a.front();
            y=b.front();            
            a.pop();
            b.pop();
        }
        //printf("{%lld,%lld,%lld}",x,y,cnt);
    }
    cout<<cnt<<'\n';

}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}