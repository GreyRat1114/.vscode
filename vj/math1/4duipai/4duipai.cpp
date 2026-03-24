#include<bits/stdc++.h>
using namespace std;
int main()
{
	int u;		//总次数 
	int y;		//余数 
	int c;				//次数 
	int a,b;
	scanf ("%d",&u);
	for (int i=1;i<=u;i++)
	{
		scanf ("%d %d",&a,&b);		//被除数	基本数字 
		printf ("Case %d: ",i);
		y=b%a;
		c=1;
		while (y)
		{
			y=(y*10+b)%a;
			//printf ("%d\n",y) ;
			c++;
		}
		printf ("%d\n",c);
	}
	return 0;
}