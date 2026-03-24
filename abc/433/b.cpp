#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int tag=0;
        
        for(int j=i-1;j>=1;j--){
            if(a[j]>a[i]){
                tag=j;
                break;
            }
        }
        if(tag){
            cout<<tag<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
}
int main(){
    solve();
    return 0;
}