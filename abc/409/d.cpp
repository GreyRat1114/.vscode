#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+5;
void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    char c;
    for(int i=0;i<=n-2;i++){
        if(s[i]>s[i+1]){
            int p=i;
            while(p+1<=n-1&&s[p]>=s[p+1]){
                char tmp=s[p];
                s[p]=s[p+1];
                s[p+1]=tmp;
                p++;
            }
            break;
        }
    }
    cout<<s<<'\n';
}
int main(){ 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}