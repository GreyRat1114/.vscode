#include<bits/stdc++.h>
using namespace std;
using LL= long long;

void solve(){
   LL n,k;
   cin >> n >> k;
   string s;
   cin >> s;
   LL num = 0;
   priority_queue<LL> pq;

   for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if(num == 0) continue;
            else{
                pq.push(num);
                num = 0;
                continue;
            }
        }
        num++;
   }
   if(num != 0) pq.push(num);

   LL r = k;
   while(!pq.empty()&&r!=0){
        LL e = pq.top();
        pq.pop();
        LL ci = 0;
        if(!pq.empty()) ci = pq.top();
        // cout << e << "\n";
        // e--;
        // LL w1 = e / 2;
        // LL w2 = e - w1;
        // if(w1 != 0) pq.push(w1);
        // if(w2 != 0) pq.push(w2);
        for(int i = 1; i<= r; i++){
            LL d = e - i;
            LL fen = i+1;
            LL t1 = d / fen;
            if(d % fen != 0) t1++;

            if(t1 <= ci){
                LL num1 = d % fen;
                LL num2 = fen - num1;
                if(num1 == 0){
                    if(t1 > 0)
                    while(num2--) pq.push(t1);
                }
                else{
                    if(t1 > 0)
                    while(num1--) pq.push(t1);
                    if(t1 > 1)
                    while(num2--) pq.push(t1-1);
                }
                r -= i;
                break;
            }
            if(i == r){
                LL num1 = d % fen;
                LL num2 = fen - num1;
                 if(num1 == 0){
                    if(t1 > 0)
                    while(num2--) pq.push(t1);
                }
                else{
                    if(t1 > 0)
                    while(num1--) pq.push(t1);
                    if(t1 > 1)
                    while(num2--) pq.push(t1-1);
                }
                r = 0;  
                break;
            }
        }
   }

   LL ans = 0;
   LL cnt = 0;
   while(!pq.empty()){
        LL e = pq.top();
        pq.pop();
        // cout << e << " ";
        cnt += e;
        LL p = e*(e+1)/2LL;
        ans += p * 5LL;
   }
    // cout << "\n";
   ans += cnt * 20LL;
   cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}