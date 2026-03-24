#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
int a[10][10];
void solve(){
    set<int> tr;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(tr.count(a[i][j])){
                cout<<"No"<<'\n';
                return;
            }else{
                tr.insert(a[i][j]);
            }
        }
    }
    int x=a[1][1]+a[1][2]+a[1][3];
    for(int i=1;i<=3;i++){
        int s=0;
        for(int j=1;j<=3;j++){
            s+=a[i][j];
        }
        if(s!=x){
            cout<<"No"<<'\n';
            return;            
        }
    }    
    for(int i=1;i<=3;i++){
        int s=0;
        for(int j=1;j<=3;j++){
            s+=a[j][i];
        }
        if(s!=x){
            cout<<"No"<<'\n';
            return;            
        }
    }     
    int y1=a[1][1]+a[2][2]+a[3][3];
    int y2=a[1][3]+a[2][2]+a[3][1];
    if(y1!=x||y2!=x){
        cout<<"No"<<'\n';
        return;            
    }
    cout<<"Yes"<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}