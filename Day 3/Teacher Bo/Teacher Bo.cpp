#include<stdio.h>
#include<math.h>
#include<cstring>

int main()
{
	int t,n,m,p;
	int a[100007][3],b[200007];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		p=0;
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)
		    scanf("%d%d",&a[i][1],&a[i][2]);
		if (n>=650) printf("YES\n");
		else
		{
			for (int i=1;i<=n;i++)
			{
			    for (int j=i+1;j<=n;j++)
			    {
			    	int k;
			    	k=abs(a[i][1]-a[j][1])+abs(a[i][2]-a[j][2]);
			    	if (b[k]==1)
			    	{
			    		p=1;
			    		printf("YES\n");
			    		break;
					}
					else b[k]=1;
				}
				if (p==1) break;
			}
			if (p==0) printf("NO\n");
		}
	}
}
