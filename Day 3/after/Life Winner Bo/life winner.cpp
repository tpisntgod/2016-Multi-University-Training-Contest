#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int type,n,m,c;
		scanf("%d%d%d",&type,&n,&m);
		if (n<m)
		{
			c=n; n=m; m=c;
		}
		if (type==1)
		{
			if (n%2==1 && m%2==1) printf("G\n");
			else printf("B\n");
		}
		if (type==2)
		{
			if (n==m) printf("G\n");
			else printf("B\n");
		}
		if (type==3)
		{
			if (n==m && n%3==1) printf("G\n");
			else if (n%3==0 && n==m+1) printf("B\n");
			else printf("D\n");
		}
		if (type==4)
		{
			int a,b,t,l;
			a=n-1; b=m-1;
			if (a>b)
			{
				t=a; a=b; b=t;
			}
			t=b-a;
			l=floor(t*(sqrt(5.0)+1)/2);
			if (l==a) printf("G\n"); else printf("B\n");
		}
	}
	return 0;
}
