#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int MOD = 998244353;
void solve(){
    LL x,k;
    cin >> x >> k;
    LL cur = x;
    LL sum = k;
    vector<LL> pre(70,0);
    pre[0] = 1;
    for(int i=1;i<=60;i++){
        pre[i] = pre[i-1] << 1LL;
    }
    LL last=cur;
    while(cur){
        if(cur>60){
            if(sum==0){
                return;
            }
            cout<<1<<' ';
            cur--;
            sum--;
            last=cur;
        }else{
            for(int i=cur-1;i>=0;i--){
                //printf("{%lld,%lld,%lld,%lld,%lld}",pre[i],i,sum,cur,last);
                if(sum==0){
                    return;
                }
                if(last!=cur){
                    sum--;
                    if(sum==0){
                        return;
                    }             
                }
                if(pre[i]>=sum){
                    cout<<cur-i<<' ';
                    last=cur;
                    cur=i;
                    //sum--;                        
                    break;
                
                }else{
                    sum-=pre[i];
                    last=cur;
                }
                
            }
        }

    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
    solve();
    }
    return 0;
}