#include<stdio.h>
#include<cstring>

int main()
{
	int n,k,s,h;
	double f;
	int c[1007];
	while (scanf("%d",&n)!=EOF)
	{
		s=0; k=0; h=0;
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&c[i]);
		    s+=c[i];
		}
		k=c[1]+c[n];
		if (n==1)
		{
			f=(double)c[1];
			printf("%.6lf\n",f);
		}
		if (n==2)
		{
			f=(double)s/2.0;
			printf("%.6lf\n",f);
		}
		if (n>2)
		{
			h=2*s+k;
			f=(double)h/6.0;
			printf("%.6lf\n",f);
		}
	}
}
