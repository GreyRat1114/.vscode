#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
using LL=long long;
int a[N];
LL ans[N];
void solve(int t){
    int n,k;
    // ofstream outfile;
    // outfile.open("aaa123.txt");
    cin>>n>>k;
        LL x=k%n;
        LL s=0;
        int cnt=1;
        
        while(x){
            x=(x*10+k)%n;
            cnt++;
        }    
        
    // for(int i=1;i<=1e6;i++){

    //     // outfile<<'{'<<i<<','<<cnt<<'}'<<',';              
    // }
    cout<<"Case "<<t<<": "<<cnt<<'\n';
    // if(k%n==0){
    //     cout<<"Case "<<t<<": "<<1<<'\n';
    // }else{
        
    // }
    
    //cout<<tot<<'\n';
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}