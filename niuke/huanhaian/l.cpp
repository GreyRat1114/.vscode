#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e7+5;
void solve(){
    int n;
    cin>>n;
    LL id;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>id;
        if(id<=s){
            s-=id;
        }
        else{
            s+=id;
        }
        
        
    }
    if(s==0){
        cout<<"Correct"<<'\n';
    }
    else{
        cout<<s<<'\n';
    }
}
int main(){
    solve();
    return 0;
}