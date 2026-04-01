#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    string s;
    cin>>s;
    LL d=0;
    LL x=0;
    LL pre=0;
    LL rt=0;
    LL n=s.size();
    vector<LL> cntp(n+2,0),cntc(n+2,0);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='c'){
            cntc[i]=cntc[i+1]+1;
        }
        if(s[i]=='p'){
            cntp[i]=cntp[i+1]+1;
        }
    }
    for(int i=0;i<s.size();i++){
        if(d>=rt){
            if(s[i]=='p'){
                
                d++;
                x=0;
                rt=d;
            }else if(s[i]=='c'){
                d--;
                if(x==0){
                    pre=d;
                }
            }else{
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
        }else{
            if(s[i]=='p'){
                d++;
                if(d==rt){
                    x=0;
                    if(cntp[i+1]==0&&cntc[i+1]==rt){
                        cout<<"Yes"<<'\n';
                        return;
                    }
                }
            }else if(s[i]=='c'){
                d--;
            }else{
                if(s[i]=='l'){
                    x--;
                }else if(s[i]=='r'){
                    x++;
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