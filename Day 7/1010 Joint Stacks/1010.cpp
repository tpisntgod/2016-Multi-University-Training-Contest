#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define maxn 100007

using namespace std;

int a[maxn],b[maxn],c[maxn],f[maxn],v[maxn];

int main() {
	int n,ta,tb,tc,ca=0,ct,last;
	while(scanf("%d",&n) && n) {
		ta=tb=tc=0; ct=0; last=1;
		printf("Case #%d:\n",++ca);
		memset(v,0,sizeof(v));
		for (int i=1;i<=n;i++) {
			char s[27];
			char c0,c1,c2,c3,c4;
			scanf("%s",s);
			if (s[1] == 'u') {
				ct++;
				scanf("%c%c%c%d%c",&c0,&c1,&c2,&f[ct],&c4);
				if (c1=='A') a[++ta]=ct;
				else b[++tb]=ct;
			}
			if (s[1] == 'o') {
				scanf("%c%c%c",&c0,&c1,&c4);
				if (c1=='A') {
					if (ta>0) {
						printf("%d\n",f[a[ta]]);
						v[a[ta]]=1;
						ta--;
					}
					else {
						printf("%d\n",f[c[tc]]);
						v[c[tc]]=1;
						tc--;
					}
				}
				else {
					if (tb>0) {
						printf("%d\n",f[b[tb]]);
						v[b[tb]]=1;
						tb--;
					}
					else {
						printf("%d\n",f[c[tc]]);
						v[c[tc]]=1;
						tc--;
					}				
				}				
			}
			if (s[1] == 'e') {
				scanf("%c%c%c%c%c",&c0,&c1,&c2,&c3,&c4);
				ta=tb=0;
				for (int i=last; i<=ct; i++) {
					if (!v[i]) {
						tc++;
						c[tc]=i;
					}
				}
				last = ct+1;
			}
		}
	}
}
