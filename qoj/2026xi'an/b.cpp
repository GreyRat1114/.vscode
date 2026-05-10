#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using i128=__int128;
const int N=1e6+10;
int a[N];
void solve(){
    ll n,x,y;
    std::cin>>n>>x>>y;
    std::string s;
    std::cin>>s;
    s=" "+s;
    ll sum=0,num=0;
    //0向右1向上
    for(int i=1;i<=n;i++){
       a[i]=s[i]-'0';
       if(a[i]==0){
          sum++;
       }else if(a[i]==1){
          num++;
       }
    }
    if(x==0&&y==0){
        for(int i=1;i<=n;i++){
            if(a[i]==2)std::cout<<0;
            else{
                std::cout<<a[i];
            }
        }
        std::cout<<endl;
        return ;
    }
    int kem=n-(sum+num);
    ll pm=x+y;
    ll cal=pm/n;
    pm%=n;
    //std::cout<<pm<<endl;
    if(pm==0){
       ll cxs=cal*sum;
       ll cys=cal*num;
       x-=cxs,y-=cys;
      // std::cout<<x<<" "<<y<<endl;
       bool flag=true;
       if(x<0||y<0){
        flag=false;
       }
       ll len=0;
       if(x%cal==0){
          len+=x/cal;
       }else{
          flag=false;
       }
       if(y%cal==0){
          len+=y/cal;
       }else{
          flag=false;
       }
       if(len!=kem){
          flag=false;
       }
       if(!flag)std::cout<<-1<<endl;
       else{
          int ks=x/cal,ks1=y/cal;
          for(int i=1;i<=n;i++){
             if(a[i]==2&&ks){
                std::cout<<0;
                ks--;
             }else if(a[i]==2&&ks1){
                 std::cout<<1;
                ks1--;
             }else{
                std::cout<<a[i];
             }
          }
          std::cout<<endl;
       }
    }else{
        ll nx=0,ny=0;//前面的上下个数
        for(int i=1;i<=pm;i++){
            if(a[i]==0)nx++;
            else if(a[i]==1)ny++;
        }
        ll mx=0,my=0;//后面的上下个数
        ll kem=0;
        for(int j=pm+1;j<=n;j++){
            if(a[j]==0)mx++;
            else if(a[j]==1)my++;
            else{
                kem++;
            }
        }
        ll ps=pm-nx-ny;//问号个数
        for(int j=0;j<=ps;j++){
            ll px=x,py=y; 
            ll tx=nx+j,ty=ny+ps-j;//前面选择上右的个数
            ll nowx=(tx+mx)*cal+tx,nowy=(ty+my)*cal+ty;
            px-=nowx,py-=nowy;
            if(px<0||py<0){
                continue;
            } 
            bool flag=true;
            if(cal==0){
                if(px!=0&&px!=0){
                    flag=false;
                }
            }
            int len=0;
         //   std::cerr<<cal<<endl;
            if(cal!=0&&px%cal==0){
                len+=px/cal;
            }else if(cal!=0){
                flag=false;
            }
            //std::cerr<<cal<<endl;
            if(cal!=0&&py%cal==0){
                len+=py/cal;
            }else if(cal!=0){
                flag=false;
            }
            if(len!=kem&&cal!=0){
                flag=false;
            }
           // std::cerr<<1<<endl;
            
            int ks1=0,ks2=0;
            if(cal!=0){
                ks1=px/cal,ks2=py/cal;
            }
            if(flag){
                int km=j,km1=ps-j;
                for(int i=1;i<=pm;i++){
                    if(a[i]!=2)std::cout<<a[i];
                    else if(a[i]==2&&km){
                        std::cout<<0;
                        km--;
                    }else if(a[i]==2&&km1){
                        std::cout<<1;
                        km1--;
                    }else{
                        std::cout<<0;
                    }
                }
                for(int j=pm+1;j<=n;j++){
                    if(a[j]!=2)std::cout<<a[j];
                    else if(a[j]==2&&ks1){
                        std::cout<<0;
                        ks1--;
                        }else if(a[j]==2&&ks2){
                            std::cout<<1;
                            ks2--;
                        }else{
                            std::cout<<0;
                        }
                }
            }
            std::cout<<endl;
            return ;
        }
        std::cout<<-1<<endl;
    }
    
     
}
int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}