#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL maxn[N];
LL dx[]={0,-1,0,1};
LL dy[]={1,0,-1,0};
void solve(){
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n+1;i++){
        if(i<=3){
            maxn[i]=i-1;
            continue;
        }
        if(i%2==0){
            maxn[i]=maxn[i-1]+2;
        }else{
            maxn[i]=maxn[i-1]+1;
        }
    }    
    if(k>maxn[n]){
        cout<<"No"<<'\n';
        return;
    }
    LL x=0,y=0;
    LL c=1;
    LL dir=0;
    LL cnt=1;
    LL s=0;
    vector<pair<LL,LL>> q;
    printf("{%lld,%lld}",x,y);
    q.push_back(make_pair(x,y));  
    LL pre=0;  
    while(s<k){
        for(int i=1;i<=c;i++){
            x=x+dx[dir%4];
            y=y+dy[dir%4];
            printf("{%lld,%lld}",x,y);
            q.push_back(make_pair(x,y));
            cnt++;
            if((x+y)%2==0&&cnt>=4){
                s+=2;
                pre=2;
            }else{
                s++;
                pre=1;
            }
            if(s>=k){
                break;
            }            
        }
        dir++;
        if(dir%2==0){
            c++;
        }
    }
    if(cnt>=n){
        cout<<"No"<<'\n';
        return;
    }

    s-=pre;
    LL d=k-s;
    if(d==1){
        q.push_back(make_pair(x+dx[(dir+3)%4],y+dy[(dir+3)%4]));
    }else if(d==2){
        q.push_back(make_pair(x+dx[(dir+3)%4],y+dy[(dir+3)%4]));
    }
}
int main(){
    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
    return 0;
}