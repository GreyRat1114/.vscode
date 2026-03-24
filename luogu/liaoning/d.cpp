#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N][5];
bool vis[N];
void solve(){
    LL n;
    cin>>n;
    vector<int> cnt(3,0);
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        
    }
    for(int i=1;i<=3;i++){
        int tag=1;
        for(int j=1;j<=n;j++){
            if(a[j][i]==0){
                tag=0;
            }
        }
        if(tag){
            cout<<1<<'\n';
            return;
        }
    }
    for(int i=1;i<=3;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1){
                sum++;
            }

        }
        
        for(int j=1;j<=3;j++){
            int sum2=0;
            if(j==i){
                continue;
            }
            for(int k=1;k<=n;k++){
                if(a[k][j]==1&&a[k][i]!=1){
                    sum2++;
                }
            }
            if(sum+sum2>=n){
                cout<<2<<'\n';
                return;
            }
        }
    }
    cout<<3<<'\n';
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    
    return 0;
}