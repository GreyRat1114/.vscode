#include<bits/stdc++.h>
using namespace std;
const int N=25;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
int numl[N];
int numr[N];
int ans[N];
int tot1;
int tot2;
bool check(){
    for(int i=tot2;i>=1;i--){
        if(numl[i]>numr[i]){
            return false;
        }else if(numl[i]<numr[i]){
            return true;
        }
    }
        //     printf("||");
        // for(int i=tot2;i>=1;i--){
        //     cout<<numr[i];
        // }
        // cout<<'\n';
    return true;
}
void copy(){
    for(int i=1;i<=tot2;i++){
        ans[i]=numr[i];
    }
}
int is0(int p){
    int cnt=0;
    for(int i=p;i<=tot2;i++){
        if(numr[i]>=1){
            cnt++;
        }
    }
    return cnt;
}
void pt(){
    int top=0;
    for(int i=tot2;i>=1;i--){
        if(ans[i]!=0){
            top=i;
            break;
        }
    }
    // int tail=1;
    // for(int i=1;i<=tot2;i++){
    //     if(ans[i]!=0){
    //         tail=i;
    //         break;
    //     }
    // }
    int tag=0;
    for(int i=1;i<=top;i++){
        if(ans[i]==0&&tag==0){
            continue;
        }
        if(ans[i]!=0&&tag==0){
            tag=1;
        }
        cout<<ans[i];
    }
    cout<<'\n';
}
void solve(){
    LL l,r;
    for(int i=0;i<=20;i++){
        numl[i]=0;
        numr[i]=0;
        ans[i]=0;
    }
    cin>>l>>r;
    LL yl=l;
    LL yr=r;
    tot1=0;
    while(l){
        LL x=l%10;
        tot1++;
        numl[tot1]=x;
        l=l/10;
    }
    tot2=0;
    while(r){
        LL x=r%10;
        tot2++;
        numr[tot2]=x;
        r=r/10;
    }
    copy();
    if(yl==yr){
        pt();
        return;
    }
    if(is0(1)==1){
        cout<<yr-1<<'\n';

        return;
    }
    for(int i=1;i<=tot2;i++){
        //printf("{%d}",i);
        if(is0(i+1)==0||(is0(i+1)==1&&numr[tot2]==1)){
            pt();
            return;            
        }
        //     printf("||");
        // for(int i=tot2;i>=1;i--){
        //     cout<<numr[i];
        // }
        // cout<<'\n';
        if(numr[i]==9){
            continue;
        }
        while(numr[i+1]==0){
        
            numr[i]=9;
        //                 printf("||");
        // for(int i=tot2;i>=1;i--){
        //     cout<<numr[i];
        // }
        // cout<<'\n';
            i++;
            if(!check()){
                pt();
                return;
            }
            //copy();
        }

        numr[i]=9;
        numr[i+1]=numr[i+1]-1;
        if(!check()){
            pt();
            return;
        }
        copy();
        //printf("{%d %d}",ans[1],ans[2]);
    }
    pt();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}