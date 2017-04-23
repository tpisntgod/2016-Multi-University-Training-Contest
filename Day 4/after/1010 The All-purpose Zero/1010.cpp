#include<iostream>
#include<cstdio>

using namespace std;

int a[100007],d[100007];
int main()
{
	int t,n,zs,s=0;
	scanf("%d",&t);
	while (t--)
	{
		s++;
		scanf("%d",&n);
		zs=0;
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);
		    if (a[i]==0) zs++;
		}
		int len=1,j,k=0;
		for (int i=1;i<=n;i++)
		    if (a[i]!=0)
			{
			    d[1]=a[i]-k;
			    j=i+1;
			    break;
			}
			else k++;
		for (int i=j;i<=n;i++)
		{
			if (a[i]!=0)
			{
			a[i]-=k;
			if (a[i]<d[1]) d[1]=a[i];
			else if (a[i]>d[len]) d[++len]=a[i];
			else
			{
				int l=1,r=len,mid;
				while (l<=r)
				{
					mid=(l+r)/2;
					if (d[mid]<a[i] && a[i]<=d[mid+1])
					    break;
					else if (d[mid]<a[i]) l=mid+1;
					else r=mid-1;
				}
				d[mid+1]=a[i];
			}
		    }
		    else k++;
		}
		if (zs!=n) printf("Case #%d: %d\n",s,len+zs);
		else printf("Case #%d: %d\n",s,zs);
	}
}
