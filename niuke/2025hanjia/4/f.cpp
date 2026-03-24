#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    LL a,b;
    cin>>a>>b;
    if(a<b){
        int x=b/(a+1);
        int y=b%(a+1);
        for(int i=1;i<=a+1;i++){
            if(i<=y){
                for(int j=1;j<=x+1;j++){
                    cout<<1;
                }
            }else{
                for(int j=1;j<=x;j++){
                    cout<<1;
                }
            }
            if(i!=a+1){
                cout<<0;
            }
        }   
        cout<<'\n'; 
    }else if(a>b){
        int x=a/(b+1);
        int y=a%(b+1);
        for(int i=1;i<=b+1;i++){
            if(i<=y){
                for(int j=1;j<=x+1;j++){
                    cout<<0;
                }
            }else{
                for(int j=1;j<=x;j++){
                    cout<<0;
                }
            }
            if(i!=b+1){
                cout<<1;
            }
        }       
        cout<<'\n';  
    }else{
        for(int i=1;i<=a;i++){
            cout<<0<<1;
        }      
        cout<<'\n';  
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