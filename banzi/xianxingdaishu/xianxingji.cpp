#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> a;
vector<LL> p;// 把所有向量insert，得到第i为可表示为1的pi
void insert(LL x)
{
    for(int i=63;i>=0;i--)
    {
        if(x>>i&1)
        {
            if(p[i])
            {
                x^=p[i];            
            }
            else
            {
                p[i]=x;
                break;
            }
        }
    }
}
