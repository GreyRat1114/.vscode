#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL nn,xx,yy;
    LL sx=0;
    LL sy=0;
    LL sz=0;
    cin>>nn>>xx>>yy;
    i128 x=xx;
    i128 y=yy;
    i128 n=nn;
    string s;
    cin>>s;
    i128 cnt=x+y;
    i128 p=cnt%n;
    //printf("<%lld,%lld,%lld>",x,y,cnt);
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            sx++;
        }else if(s[i]=='1'){
            sy++;
        }else{
            sz++;
        }
    }
    auto check=[&](LL d0,LL d1)->string{
        string a=s;
        for(int i=0;i<n;i++){
            if(a[i]=='2'){
                if(d0>0){
                    a[i]='0';
                    d0--;
                }else{
                    a[i]='1';
                    d1--;
                }
            }
        }
        return a;
    };
    auto check2=[&](LL d1,LL d0)->string{
        string a=s;
        for(int i=0;i<n;i++){
            if(a[i]=='2'){
                if(d1>0){
                    a[i]='1';
                    d1--;
                }else{
                    a[i]='0';
                    d0--;
                }
            }
        }
        return a;
    };    
    if(p==0){
        //printf("||");
        for(int i=sz;i>=0;i--){
            if((sx+i)==0){
                if(x==0){
                    string ans=check(i,sz-i);
                    cout<<ans<<'\n';
                    return;                    
                }else{
                    //cout<<-1<<'\n';
                    continue;
                }

            }else if((sy+sz-i)==0){
                if(y==0){
                    string ans=check(i,sz-i);
                    cout<<ans<<'\n';
                    return;                    
                }else{
                    //cout<<-1<<'\n';
                    continue;
                }
            }
            if(x%(sx+i)==0&&y%(sy+sz-i)==0&&x/(sx+i)==y/(sy+sz-i)){
                string ans=check(i,sz-i);
                cout<<ans<<'\n';
                return;
            }
        }
    }else{
        i128 k=cnt/n;
        i128 p0=0,p1=0,p2=0;
        for(int i=0;i<p;i++){
            if(s[i]=='2'){
                p2++;
            }else if(s[i]=='1'){
                p1++;
            }else{
                p0++;
            }
        }
        //printf("{%lld,%lld,%lld,%lld,%lld}",(LL)k,(LL)p2,(LL)sz,(LL)cnt,(LL)p);
        for(int i=sz;i>=p2;i--){
            i128 d0=i;
            i128 d1=sz-i;
            if((sx+d0)==0){
                if(x==0){
                    string ans=check(d0,d1);
                    cout<<ans<<'\n';
                    return;
                }else{
                    //cout<<-1<<'\n';
                    continue;
                }

            }else if((sy+d1)==0){
                if(y==0){
                    string ans=check(d0,d1);
                    cout<<ans<<'\n';
                    return;
                }else{
                    //cout<<-1<<'\n';
                    continue;                
                }

            }
            if((x-p0-p2)%(sx+d0)==0&&(y-p1)%(sy+d1)==0&&(x-p0-p2)/(sx+d0)==(y-p1)/(sy+d1)){
                string ans=check(d0,d1);
                cout<<ans<<'\n';
                return;
            }

        }
        for(int i=p2-1;i>=0;i--){
            i128 d0=i;
            i128 d1=sz-i;    
            if((sx+d0)==0){
                if(x==0){
                    string ans=check(d0,d1);
                    cout<<ans<<'\n';
                    return;
                }else{
                    //cout<<-1<<'\n';
                    continue;
                }
            }else if((sy+d1)==0){
                if(y==0){
                    string ans=check(d0,d1);
                    cout<<ans<<'\n';
                    return;
                }else{
                    //cout<<-1<<'\n';
                    continue;                   
                }
            }              
            if((x-p0-d0)%(sx+d0)==0&&(y-p1-(p2-d0))%(sy+d1)==0&&(x-p0-d0)/(sx+d0)==(y-p1-(p2-d0))/(sy+d1)){
                //printf("{%lld,%lld,%lld,%lld}",d0,d1,x-p0-d0,y-p1-d1);
                string ans=check(d0,d1);
                cout<<ans<<'\n';        

                return;          
            }                 
        }
    }
    cout<<-1<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}