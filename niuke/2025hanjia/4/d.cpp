#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL x1,y1,d;
    d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return d;
}
// LL inv(LL n,LL p){

// }
LL cheng(LL a,LL b,LL p){
	LL res=0;
	a%=p;
	while(b)
	{
		if(b&1)res=(res+a)%p;
		a=(2*a)%p;
		b>>=1;
	}
	return res;
}
void solve(){
    LL x,a,s;
    cin>>x>>a>>s;
    LL x0,y0;
    LL g=exgcd(a,s,x0,y0);
    if(x%g!=0){
        cout<<"No"<<'\n';
        return;
    }
    LL dx=s/g;
    LL dy=a/g;
    LL X=(cheng(x0,x/g,dx)%dx+dx)%dx;
    if(X>(x/a)){
        cout<<"No"<<'\n';
        return;        
    }else{
        LL Y=(x-a*X)/s;
        LL k=(Y-X)/(dx+dy);
        LL c1=X+k*dx;
        LL c2=Y-k*dy;
        LL cc1=X+(k+1)*dx;
        LL cc2=Y-(k+1)*dy;     
        cout<<"Yes"<<'\n';
        if(cc2<0){
            cout<<c1<<' '<<c2<<'\n';

        }else{
            if(max(c1,c2)<=max(cc1,cc2)){
                cout<<c1<<' '<<c2<<'\n';
            }else{
                cout<<cc1<<' '<<cc2<<'\n';
            }
        }
    }

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}