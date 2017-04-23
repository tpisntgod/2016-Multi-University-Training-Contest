#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int a[10007],b[1007],c[1007],tot=0;
int q(int x)
{
	int k=x,i=1,l=x;
	if (x==1) return 1;
	while (k>1)
	{
		if (k%b[i]==0)
		{
		  if (c[i]==0)
		  {
		  	c[i]==1;
		  	l=l/b[i]*(b[i]-1);
		  }
		  k=k/b[i];
	    }
	    else i++;
	}
	return l;
}
void init()
{
	a[0]=1; a[1]=1;
    for (int i=2; i<=100; i++)
      if (a[i]==0)
      for (int j=2*i; j<=10000; j=j+i)
        a[j]=1;
    for (int i=2;i<=10000;i++)
      if (a[i]==0)
      {
        tot++;
        b[tot]=i;
	  }
}
int main()
{
	int n,m,p;
	init();
	
	while (scanf("%d%d%d",&n,&m,&p)!=EOF)
	{
		int k=0,h=1;
		for (int i=1;i<=m;i++)
		{
			memset(c,0,sizeof(c));
			k=(k+q(i*n)% 1000000007)% 1000000007;
		}
		printf("%d\n",k%p);
		for (int l=1;l<=k;l++)
		  h=h*k;
		printf("%d\n",h%p);
	}
}
