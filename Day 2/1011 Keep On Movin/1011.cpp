#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>

using namespace std;

int main()
{
	int t,n,k,s,l;
	int a[100007];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		s=0; k=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]%2==1) 
			{
			    a[i]--;
			    k++;
			}
			s+=a[i];
		}
		if (k==0) printf("%d\n",s);
		if (k!=0)
		{
		l=s/k;
		if (l%2==1) l--;
		printf("%d\n",l+1);
		}
	}
}
