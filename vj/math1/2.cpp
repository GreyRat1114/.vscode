#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;   

        if(n>=3&&m>=3){
            if((n*m)%2==1){
                printf("Case %d: %d\n",i,n*m/2+1);    
            }else{
                printf("Case %d: %d\n",i,n*m/2);   
            }            
        }else if(n==1||m==1){
            printf("Case %d: %d\n",i,max(n,m));
        }else if(n==2||m==2){
            int y=(n*m)%8;
            int z=min(4,y);
            printf("Case %d: %d\n",i,4*((n*m)/8)+z);
        }

    }
}
int main(){
    solve();
    return 0;
}