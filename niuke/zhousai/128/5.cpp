#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define it set<int>::iterator
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int x=0;
    //int p=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            // if(p==-1){
            //     p=i;
            // }
            x++;
        }
    }
    int m=x/2;

    if(x%2==0){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                if(cnt<=m){
                    s[i]=' ';
                }else{
                    s[i]='2';
                }
                
            }
        }  
    }else{
        int cnt=0;
        int p=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            if(s[i]=='1'&&s[i+1]=='2'&&cnt<=m+1){
                p=i;
                break;
            }
        }      
        int p2=-1;
        if(p==-1){
            // for(int i=0;i<n;i++){
            //     if(s[i]=='1'&&s[i+1]=='1'){
            //         p=i;
            //         break;
            //     }
            // }  
            p2=m+1;
            // if(p==-1){
                
            // }                            
        }
        cnt=0;
          

        //cout<<p<<'\n';
        
        for(int i=0;i<n;i++){
            if(i==p){
                continue;
            }
            if(s[i]=='1'){
                cnt++;
                if(cnt==p2){
                    continue;
                }
                if(cnt<=m){
                    s[i]=' ';
                }else{
                    s[i]='2';
                }
                
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            continue;
        }
        cout<<s[i];
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    
    return 0;
}