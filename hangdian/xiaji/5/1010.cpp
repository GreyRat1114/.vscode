#include<bits/stdc++.h>
int matrix[105][105];

std::vector<int>Gauss(int n, int m)  
{
  for (int i = 1; i <= n; i++) {
    int cur = i;
    while (cur <= m && !matrix[cur]) cur++;
    if (cur > m) return std::vector<int>(0);
    if (cur != i) swap(matrix[cur], matrix[i]);
    for (int j = 1; j <= m; j++)
      if (i != j && matrix[j].test(i)) matrix[j] ^= matrix[i];
  }
     std::vector<bool> ans(n + 1);
  for (int i = 1; i <= n; i++) ans[i] = matrix[i].test(0);
  return ans;
}
const int N=110;
int C[N][N];
int S[N];
int vis[N];
void solve(){
   int K;
   std::cin>>K;
   int C1;
   for(int i=1;i<=K;i++){
      std::cin>>C1>>S[i];
      for(int j=1;j<=C1;j++){
          std::cin>>C[i][j];
          vis[C[i][j]]++;
          matrix[i][C[i][j]]=1;
      }
   }
   int m=0;
   for(int i=1;i<=100;i++){
       if(vis[i])m++;
   }
   std::vector<bool>ans=Gauss(m,K);
   
   int Q;
   std::cin>>Q;
   while(Q--){
       int D;
       std::cin>>D;
       
   }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T=1;
    std::cin>>T;
    while(T--){
        solve();
    }
}