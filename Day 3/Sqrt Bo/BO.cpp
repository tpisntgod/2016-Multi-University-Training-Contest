#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int f(int k,int l)
{
	if (k>l) return 0;
	if (k==l) return 1;
	return 2;
}
int main()
{
	int h;
	char s[1007],s2[11]="4294967295";
	char s3[6]="65535",s4[4]="255",s5[3]="15",s6[2]="3",s7[2]="1";
	while(scanf("%s",s)!=EOF)
	{	
		h=f(strlen(s),10);
		if (h==0)
		    printf("TAT\n");
		else if (h==1)
		{
			if (strcmp(s,s2)<=0) printf("5\n");
			else printf("TAT\n");
		}
		else
		{
			h=f(strlen(s),5);
			if (h==0)
			    printf("5\n");
			else if (h==1)
			{
				if (strcmp(s,s3)<=0) printf("4\n");
				else printf("5\n");
			}
			else
			{
				h=f(strlen(s),3);
				if (h==0)
				    printf("4\n");
				else if (h==1)
				{
					if (strcmp(s,s4)<=0) printf("3\n");
					else printf("4\n");
				}
				else
				{
					h=f(strlen(s),2);
					if (h==0)
					    printf("3\n");
					else if (h==1)
					{
						if (strcmp(s,s5)<=0) printf("2\n");
						else printf("3\n");
					}
					else
				    {
				    	if (strcmp(s,s6)>0) printf("2\n");
				    	else
						{
						    if (strcmp(s,s7)>=0) printf("1\n");
						    else printf("TAT\n");					    
						}
					}
				}
			}
		}
	}
}
