//cf1521B
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
void solve(){
    LL n;
    cin>>n;
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<'\n';
    }else if(n==2){
        cout<<2<<'\n';
        cout<<1<<' '<<2<<'\n';
    }else if(n==3){
        cout<<2<<'\n';
        cout<<1<<' '<<2<<' '<<2<<'\n';        
    }else if(n==4){
        cout<<3<<'\n';
        cout<<1<<' '<<2<<' '<<2<<' '<<3<<'\n';   
    }else if(n==5){
        cout<<3<<'\n';
        cout<<1<<' '<<2<<' '<<2<<' '<<3<<' '<<3<<'\n';           
    }else if(n==6){
        cout<<4<<'\n';
        cout<<1<<' '<<2<<' '<<2<<' '<<3<<' '<<3<<' '<<4<<'\n'; 
    }else{
        cout<<4<<'\n';
        cout<<1<<' '<<3<<' '<<2<<' '<<4<<' '<<1<<' '<<3<<' '; 
        for(int i=7;i<=n;i++){
            if(i%4==0){
                cout<<4<<' ';
            }else if(i%4==1){
                cout<<1<<' ';
            }else if(i%4==2){
                cout<<3<<' ';
            }else if(i%4==3){
                cout<<2<<' ';
            }
        }
        cout<<'\n';
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