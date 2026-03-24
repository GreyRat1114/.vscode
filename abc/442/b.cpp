#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
const LL mod=998244353;
void solve(){
    int q;
    cin>>q;
    int op;
    int tag=0;
    int x=0;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            x++;
        }else if(op==2){
            if(x>=1){
                x--;
            }
        }else{
            tag=tag^1;
        }
        if(x>=3&&tag){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}