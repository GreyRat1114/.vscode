#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL maxn=0;
    LL num;
    LL a,b;
    vector<pair<LL,LL>> op(n+1);
    set<LL> st;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        op[i].first=a;
        op[i].second=b;
        if(b==0){
            st.insert(a);
        }
        if(b>=maxn){
            maxn=b;
            num=a;
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("{%lld,%lld}",op[i].first,op[i].second);
    // }
    // printf("{%lld,%lld}",maxn,num);
    auto check=[&](LL x)->LL{
        LL xx=x;
        for(int i=1;i<=n;i++){
            LL y=op[i].first;
            LL cnt=0;
            x=xx;
            for(int j=1;j<=4;j++){
                if((x%10)==(y%10)){
                    cnt++;
                }
                x=x/10;
                y=y/10;
            }
            //printf("{%lld,%lld,%lld}",xx,cnt,i);
            if(cnt!=op[i].second){
                return 0;
            }

        }
        
        //printf("{%lld}",x);
        return 1;
    };
    auto print=[&](LL ans)->void{
        vector<LL> m1(4);
        for(int i=0;i<4;i++){
            m1[i]=ans%10;
            ans=ans/10;
        }  
        for(int i=3;i>=0;i--){
            cout<<m1[i];
        }
        cout<<'\n';
    };
    if(maxn==0){
        for(int i=0;i<10000;i++){
            if(!st.count(i)){
                print(i);
            }
        }
    }else if(maxn==1){
        LL y=num;
        vector<LL> m(4);
        for(int i=0;i<4;i++){
            m[i]=y%10;
            y=y/10;
        }  
        LL ans=0;
        for(int j1=0;j1<=9;j1++){
            for(int j2=0;j2<=9;j2++){
                for(int j3=0;j3<=9;j3++){
                    if(check(j1*1000+j2*100+j3*10+m[0])){
                        ans=j1*1000+j2*100+j3*10+m[0];
                        print(ans);
                    }else if(check(j1*1000+j2*100+m[1]*10+j3)){
                        ans=j1*1000+j2*100+m[1]*10+j3;
                        print(ans);
                    }else if(check(j1*1000+m[2]*100+j2*10+j3)){
                        ans=j1*1000+m[2]*100+j2*10+j3;
                        print(ans);
                    }else if(check(m[3]*1000+j1*100+j2*10+j3)){
                        ans=m[3]*1000+j1*100+j2*10+j3;
                        print(ans);
                    }
                }
            }
        }
    }else if(maxn==2){
        LL y=num;
        vector<LL> m(4);
        for(int i=0;i<4;i++){
            m[i]=y%10;
            y=y/10;
        }        
        LL ans=0;
        for(int j1=0;j1<=9;j1++){
            for(int j2=0;j2<=9;j2++){
                if(check(m[3]*1000+m[2]*100+j1*10+j2)){
                    ans=m[3]*1000+m[2]*100+j1*10+j2;
                    print(ans);
                }else if(check(m[3]*1000+j1*100+m[2]*10+j2)){
                    ans=m[3]*1000+j1*100+m[2]*10+j2;
                    print(ans);
                }else if(check(m[3]*1000+j1*100+j2*10+m[2])){
                    ans=m[3]*1000+j1*100+j2*10+m[2];
                    print(ans);
                }else if(check(j1*1000+m[2]*100+m[1]*10+j2)){
                    ans=j1*1000+m[2]*100+m[1]*10+j2;
                    print(ans);
                }else if(check(j1*1000+m[2]*100+j2*10+m[1])){
                    ans=j1*1000+m[2]*100+j2*10+m[1];
                    print(ans);
                }else if(check(j1*1000+j2*100+m[1]*10+m[0])){
                    ans=j1*1000+j2*100+m[1]*10+m[0];
                    print(ans);
                }
            }
        }
    }else if(maxn==3){
        LL y=num;
        vector<LL> m(4);
        for(int i=0;i<4;i++){
            m[i]=y%10;
            y=y/10;
        }         
        LL ans=0;
        for(int j=0;j<=9;j++){
            //printf("{%lld}",j);
            if(check(j*1000+m[2]*100+m[1]*10+m[0])){
                ans=j*1000+m[2]*100+m[1]*10+m[0];
                print(ans);
            }else if(check(m[3]*1000+j*100+m[1]*10+m[0])){
                ans=m[3]*1000+j*100+m[1]*10+m[0];
                print(ans);
            }else if(check(m[3]*1000+m[2]*100+j*10+m[0])){
                ans=m[3]*1000+m[2]*100+j*10+m[0];         
                print(ans); 
            }else if(check(m[3]*1000+m[2]*100+m[1]*10+j)){    
                ans=m[3]*1000+m[2]*100+m[1]*10+j;
                print(ans); 
            }
            //printf("{%lld}",m[3]*1000+m[2]*100+m[1]*10+j);
        }
    }else{
        print(num);
        //cout<<num<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}