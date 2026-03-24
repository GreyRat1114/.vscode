#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e7+5;
LL a[N];
LL b[N];
LL s1[N],s2[N];

void solve(){
    int q;
    cin>>q;
    int op;
    LL x,y;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(i==1&&op==1){
            cin>>y;
            x=y;
        }
        if(op==1){
            cin>>y;
            if(i%2==1){
                if(y<x){
                    // s1+=
                }else{

                }
            }else{
                if(y<x){

                }else{

                }                
            }
        }
        else{

        }   
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}