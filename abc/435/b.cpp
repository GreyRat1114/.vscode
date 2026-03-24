#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
void solve(){
    int n;
    cin>>n;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s=0;
            for(int k=i;k<=j;k++){
                s+=a[k];
            }
            int tag=1;
            for(int k=i;k<=j;k++){
                if(s%a[k]==0){
                    tag=0;
                }
            }            
            if(tag){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}
