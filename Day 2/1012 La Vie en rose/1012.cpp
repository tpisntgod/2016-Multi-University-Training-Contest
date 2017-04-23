#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int f[507][507][3],a[10007];
char s[10007],p[507];
int main()
{
	int t,ls,lp;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&ls,&lp);
		scanf("%s",s);
		scanf("%s",p);
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		for (int j=0;j<lp;j++)
		{
		    if (j>=1 && s[0]==p[j-1])
		        f[0][j][0]=1;
		    if (s[0]==p[j])
		    {
		        f[0][j][1]=1;
		        if (j==0) a[0]=1;
		    }
		    if (s[0]==p[j+1])
		    {
			    f[0][j][2]=1;
			    if (j==0) a[0]=1;
			}
		}
		for (int i=1;i<ls-lp+1;i++)
		    for (int j=0;j<lp;j++)
		    {
		    	if (j>=1 &&s[i]==p[j-1])
		    	    if (f[i-1][j-1][2]==1)
		    	    {
					f[i][j][0]=1;
		    	    if (j==lp-1) a[i-lp+2]=1;
				    }
		    	if (s[i]==p[j])
		    	    if (j==0 || f[i-1][j-1][0]==1 || f[i-1][j-1][1]==1)
		    	    {
		    	    f[i][j][1]=1;
		    	    if (j==lp-1) a[i-lp+2]=1;
		    	    }
		    	if (s[i]==p[j+1])
		    	    if (j==0 || f[i-1][j-1][0]==1 || f[i-1][j-1][1]==1)
		    	    {
					f[i][j][2]=1;
				    }
			}
		for (int i=0;i<ls-lp+1;i++)
		  printf("%d",a[i]);
		for (int i=ls-lp+1;i<ls;i++)
		  printf("0");
		printf("\n");
	}
}
