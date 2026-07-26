#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL t,x;
    cin>>t>>x;
    LL pre=0;
    for(int i=0;i<t;i++){
        LL a;
        cin>>a;
        if(i==0){
            pre=a;
        }else if(abs(a-pre)>=x){
            pre=a;
        }else{
            continue;
        }

        cout<<i<<' '<<pre<<'\n';
        
    }



}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}