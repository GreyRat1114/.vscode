#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
using LL=long long;
#define mp make_pair

LL a[N][N];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2){
            continue;
        }
        for(int j=1;j<=i;j++){
            a[i][j]=1;
        }
        for(int j=1;j<=i;j++){
            a[j][i]=1;
        }        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(n%2){
                cout<<a[i][j];
            }else{
                cout<<(a[i][j]^1);
            }
            
        }
        cout<<'\n';
    }
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    return 0;
}