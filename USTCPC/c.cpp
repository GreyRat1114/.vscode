#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    string s;
    cin>>s;
    LL d=0;
    LL x=0;
    LL pre=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='c'){
            pre=d;
            d--;
            
        }else if(s[i]=='p'){
            d++;
            x=0;
        }else{
            if(d>=0){
                if(d<pre){
                    continue;
                }
                if(x>0&&s[i]=='l'){
                    x=0;
                }else if(x<0&&s[i]=='r'){
                    x=0;
                }else{
                    if(s[i]=='l'){
                        x--;
                    }else if(s[i]=='r'){
                        x++;
                    }                
                }
            }            
        }
        //printf("{%lld,%lld,%lld}",d,x,pre);
    }
    if(d==0&&x==0){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}