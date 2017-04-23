#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a,v1,v2;
	while (scanf("%d%d%d",&a,&v1,&v2)!=EOF)
	{
		double t;
		if (a==0) printf("0.000000\n");
		else if (v1<=v2) printf("Infinity\n");
		else
		{
		    t=double (v1)*a/(v1*v1-v2*v2);
		    printf("%.10lf\n",t);
		}
	}
}
