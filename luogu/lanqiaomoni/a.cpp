#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int mth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
LL check(LL x){
    //vector<LL> num(10,0);
    map<LL,LL> num;
    while(x){
        if(x%10!=0)num[x%10]++;
        x=x/10;
    }
    LL pre=num.begin()->second;
    for(auto y:num){
        if(y.second!=pre){
            return 0;
        }
    }
    return 1;
}
void solve(){
    LL n;
    //cin>>n;
    LL tot=0;
    
    for(int i=2239;i<=9875;i++){
        LL x=i;
        if(i==2239){
            for(int j=9;j<=12;j++){
                LL y=x*100+j;
                if(j==9){
                    for(int k=9;k<=mth[j];k++){
                        LL d=y*100+k;
                        if(check(d))tot++;
                    }
                }else{
                    for(int k=1;k<=mth[j];k++){
                        LL d=y*100+k;
                        if(check(d))tot++;
                    }                    
                }
            }    
        }else{
            if(i%400==0||(i%4==0&&i%100!=0)){
                for(int j=1;j<=12;j++){
                    LL y=x*100+j;
                    if(j==2){
                        for(int k=1;k<=mth[j]+1;k++){
                            LL d=y*100+k;
                            if(check(d))tot++;
                        }  
                    }else{
                        for(int k=1;k<=mth[j];k++){
                            LL d=y*100+k;
                            if(check(d))tot++;
                        }  
                    }
 
                }    
            }else{
                for(int j=1;j<=12;j++){
                    LL y=x*100+j;
                    for(int k=1;k<=mth[j];k++){
                        LL d=y*100+k;
                        if(check(d))tot++;
                    }   
                }    
            }
        
        }

    }
    cout<<tot<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}