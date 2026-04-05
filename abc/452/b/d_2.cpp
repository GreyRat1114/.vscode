#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    string s,t;
    cin>>s;
    cin>>t;
    LL n=s.size();
    LL m=t.size();
    LL tot=(n+1)*n/2;
    vector<LL> fa(m+1,-1);
    LL cnt=0;
    for(int i=0;i<n;i++){

        for(int j=m-1;j>=1;j--){
            if(s[i]==t[j]&&fa[j-1]>=0){
                fa[j]=fa[j-1];
            }
        }         
        if(s[i]==t[0]){
            fa[0]=i;
            //printf("{%lld}",i+1);
        }           
        cnt+=fa[m-1]+1;
        // for(int j=0;j<m;j++){
        //     printf("{%lld}",fa[j]);
        // }
        //printf("<%lld,%lld>",cnt,i);
        //cout<<'\n';
    }
    cout<<tot-cnt<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}