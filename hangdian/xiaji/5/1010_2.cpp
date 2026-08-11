#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N = 105;
bitset<N> matrix[N];
LL val[N];

vector<LL> Gauss(int n, int m) {

    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur <= m && !matrix[cur].test(i)) {
            cur++;
        }
        if (cur > m) {
            return {};
        }
        if (cur != i) {
            swap(matrix[cur], matrix[i]);
            swap(val[cur], val[i]);
        }
        for (int j = 1; j <= m; j++) {
            if (j != i && matrix[j].test(i)) {
                matrix[j] ^= matrix[i];
                val[j] ^= val[i];
            }
        }
    }
    for (int i = n + 1; i <= m; i++) {
        if (matrix[i].none() && val[i] != 0) {
            return {};
        }
    }
    vector<LL> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = val[i];
    }

    return ans;
}
void solve(){
   int K;
   std::cin>>K;
   int C1;
   vector<LL> S(K+1);
   vector<vector<LL>> C(K+1,vector<LL>());
   vector<LL> q;
   for(int i=1;i<=K;i++){
        LL c,s;
      cin>>c>>s;
      S[i]=s;
      for(int j=1;j<=c;j++){
        LL x;
          std::cin>>x;
          q.push_back(x);
          C[i].push_back(x);
      }
   }    

    sort(q.begin(),q.end());
    LL m=unique(q.begin()+1,q.end())-q.begin();
    map<LL,LL> mp;

    for(int i=0;i<m;i++){
        mp[q[i]]=i+1;
    }
    for(int i=1;i<=K;i++){
        for(int j=0;j<C[i].size();j++){
            LL x=C[i][j];
            LL y=mp[x];
            matrix[i][y]=1;
        }
        val[i]=S[i];
    }
    for(int i=1;i<=K;i++){
        for(int j=1;j<=3;j++){
            std::cerr<<matrix[i][j]<<" ";
        }
        std::cerr<<val[i]<<'\n';
    }
    bool flag=true;
    vector<LL> ans = Gauss(mp.size(), K);
    std::cerr<<ans.size();
    if(ans.empty()){
        flag=false;
    }
    LL qy;
    cin>>qy;
    for(int i=1;i<qy;i++){
        LL d;
        cin>>d;
        LL res=0;
        bool vis=true;
        for(int j=1;j<=d;j++){
            LL r;
            cin>>r;
            if(!mp.count(r)){
                vis=false;
            }
           res=res^ans[mp[r]];
        }
        if(!vis||!flag){
            std::cout<<-1<<'\n';
            continue;
        }
        cout<<res<<'\n';
    }
    
}
int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int T=1;
    std::cin>>T;
    while(T--){
        solve();
    }
}