#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int tag=0;
    if(a==c){
        if(d<=b){
            tag=1;
        }
    }
    else if(c<a){
        int x=(a-c)*60+b-d;
        if(x>=0){
            tag=1;
        }
    }
    if(tag){
        cout<<"Yes"<<'\n';
    }
    else{
        cout<<"No"<<'\n';
    }
}
int main(){
    solve();
    return 0;
}