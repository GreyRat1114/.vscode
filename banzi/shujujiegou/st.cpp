//st表&&RMO问题
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int f[N][25];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i][0]);

    }
    int lt,rt;
    for(int j=1;j<=20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n-m+1;i++)
    {
        int k=log2(m);
        printf("%d\n",min(f[i][k],f[i+m-(1<<k)][k]));
    }
    return 0;
}