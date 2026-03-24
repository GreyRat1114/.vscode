#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    int x,y;
    cin>>x>>y;
    double p=0;
    int s=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(i+j>=x){
                s++;
            }
        }
    }
    p+=1.0*s/36;
    s=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(abs(i-j)>=y){
                s++;
            }
        }
    }
    p+=1.0*s/36;
    s=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(abs(i-j)>=y&&i+j>=x){
                s++;
            }
        }
    }
    p-=1.0*s/36;
    cout<<setprecision(10)<<fixed<<p<<'\n';
}
int main(){
    solve();
    return 0;
}