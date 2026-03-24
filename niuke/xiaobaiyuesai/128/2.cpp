#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool isp(int x){
    int tot=0;
    // if(x==1){
    //     return false;
    // }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            tot++;
        }
    }
    if(tot){
        return false;
    }else{
        return true;
    }
}
void solve(){
    int n;
    cin>>n;
    int tag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int cnt=0;
        for(int j=2;j<=a[i];j++){
            if(a[i]%j==0&&isp(j)){
                cnt++;
            }
        }
        if(cnt<=1){
            //printf("{%d}",cnt);
            tag=1;
        }
    }
    if(tag){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
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