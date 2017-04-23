#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int a[100007],l[100007],r[100007],f[100007];

void msort(int l,int rt)
{
	int i,j,k,m,ct=0;
	if (l==rt) return;
	m=(l+rt)/2;
	msort(l,m);
	msort(m+1,rt);
	i=l; j=m+1; k=l;
	while (i<=m && j<=rt)
	{
		if (a[i]<=a[j])
		{
			r[a[i]]+=ct;
			f[k]=a[i];
			k++;
			i++;
		}
		else
		{
			ct++;
			f[k]=a[j];
			k++;
			j++;
		}
	}
	while (i<=m)
	{
		r[a[i]]+=ct;
		f[k]=a[i];
		k++;
		i++;
	}
	while (j<=rt)
	{
		f[k]=a[j];
		k++;
		j++;
	}
	for (i=l;i<=rt;i++)
	    a[i]=f[i];
}

int main()
{
	int t,n,k,q=0;
	scanf("%d",&t);
	while(t--)
	{
		q++;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		    r[i]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]<i) l[a[i]]=a[i]; else l[a[i]]=i;
		}
		for (int i=1;i<=n;i++)
		    r[a[i]]+=i;
		msort(1,n);
		printf("Case #%d: ",q);
		for (int i=1;i<=n-1;i++)
		    printf("%d ",abs(r[i]-l[i]));
		printf("%d\n",abs(r[n]-l[n]));
	}
}
