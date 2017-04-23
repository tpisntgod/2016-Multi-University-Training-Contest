#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int main()
{
	int t,h=0;
	char c;
	scanf("%d",&t);
	c=getchar();
	while(t--)
	{
		int k;
		h++;
	    string s;
	    getline(cin,s);
	    k=0;
	    if (s=="Cleveland Cavaliers") k=1;
	    if (s=="Golden State Warriors") k=2;
	    if (s=="San Antonio Spurs") k=5;
	    if (s=="Miami Heat") k=3;
	    if (s=="Dallas Mavericks") k=1;
	    if (s=="L.A. Lakers") k=11;
	    if (s=="Boston Celtics") k=17;
	    if (s=="Detroit Pistons") k=3;
	    if (s=="Chicago Bulls") k=6;
	    if (s=="Houston Rockets") k=2;
	    if (s=="Philadelphia 76ers") k=2;
		if (s=="Seattle Sonics") k=1;
	    if (s=="Washington Bullets") k=1;
	    if (s=="Portland Trail Blazers") k=1;
	    if (s=="New York Knicks") k=2;
	    if (s=="Milwaukee Bucks") k=1;
	    if (s=="St. Louis Hawks") k=1;
	    if (s=="Philadelphia Warriors") k=2;
	    if (s=="Syracuse Nats") k=1;
	    if (s=="Minneapolis Lakers") k=5;
	    if (s=="Rochester Royals") k=1;
	    if (s=="Baltimore Bullets") k=1;
	    printf("Case #%d: %d\n",h,k);
	}
}
