#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    vector<LL> a1,a2;
    LL c=2;
    for(int i=0;i<n;i++){
        if((s[i]=='0')&&(t[i]=='1'))a1.push_back(i);
        if((s[i]=='1')&&(t[i]=='0'))a2.push_back(i);
    }
    
    LL siz=a1.size()+a2.size()-1;
    if(siz==-1||n==1){
        cout<<0<<'\n';
        return;
    }

    cout<<siz+2<<'\n';
    LL fi=a1.back()+1;
    a1.pop_back();
    cout<<fi<<'\n';
    c=0;
    while(siz--){
        if(c==0){
            cout<<a2.back()+1<<'\n';
            a2.pop_back();
            c=1;
        }else{
            cout<<a1.back()+1<<'\n';
            a1.pop_back();
            c=0;
        }
    }
    cout<<fi<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}