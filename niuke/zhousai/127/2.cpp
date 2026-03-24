#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int a[5][5];
void solve(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cin>>a[i][j];
        }
    }
    set<int> tr;
    for(int i=1;i<=4;i++){
        tr.clear();
        for(int j=1;j<=4;j++){
            if(tr.count(a[i][j])){
                cout<<"NO"<<'\n';
                return;
            }
            tr.insert(a[i][j]);
        }
    }    
    for(int i=1;i<=4;i++){
        tr.clear();
        for(int j=1;j<=4;j++){
            if(tr.count(a[j][i])){
                cout<<"NO"<<'\n';
                return;
            }
            tr.insert(a[j][i]);
        }
    }
    tr.clear();
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            if(tr.count(a[i][j])){
                cout<<"NO"<<'\n';
                return;                
            }
            tr.insert(a[i][j]);
        }
    }
    tr.clear();
    for(int i=3;i<=4;i++){
        for(int j=1;j<=2;j++){
            if(tr.count(a[i][j])){
                cout<<"NO"<<'\n';
                return;                
            }
            tr.insert(a[i][j]);
        }
    }
    tr.clear();
    for(int i=1;i<=2;i++){
        for(int j=3;j<=4;j++){
            if(tr.count(a[i][j])){
                cout<<"NO"<<'\n';
                return;                
            }
            tr.insert(a[i][j]);
        }
    }
    tr.clear();
    for(int i=3;i<=4;i++){
        for(int j=3;j<=4;j++){
            if(tr.count(a[i][j])){
                cout<<"NO"<<'\n';
                return;                
            }
            tr.insert(a[i][j]);
        }
    }
    tr.clear();
    cout<<"YES\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}