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

    for(int i=0;i<n;i++){
        //if(i==1)continue;
        if((s[i]=='0')&&(t[i]=='1'))a1.push_back(i);
        if((s[i]=='1')&&(t[i]=='0'))a2.push_back(i);
    }
    LL siz=a1.size();
    cout<<siz*3<<'\n';
    for(int i=0;i<siz;i++){
        cout<<a1[i]+1<<'\n';
        cout<<a2[i]+1<<'\n';
        cout<<a1[i]+1<<'\n';
    }

}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}