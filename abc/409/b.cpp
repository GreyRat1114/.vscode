#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    map<LL,LL,greater<LL>> tr;
    int n;
    cin>>n;
    LL x;
    for(int i=1;i<=n;i++){
        cin>>x;
        tr[x]++;
    }
    LL ans=0;
    LL s=0;
    for(auto y:tr){
        s+=y.second;

        if(s>=y.first){
            ans=max(ans,y.first);
            
        }else{
            ans=s;
        }
    }
    cout<<ans<<'\n';
}
int main(){ 
    solve();
    return 0;
}